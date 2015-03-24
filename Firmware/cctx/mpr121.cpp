/*
 * mpr121.cpp
 *
 *  Created on: 16 сент. 2014 г.
 *      Author: Kreyl
 */

#include "mpr121.h"
#include "cmd_uart.h"
#include "evt_mask.h"
#include "main.h"

i2c_t i2c;
mpr121_t Touch;

#if 1 // ==== Constants ====// Electrode configuration:// Baseline tracking by default, Eleprox disabled, elements 0...N enabled
#define ELECTRODE_CFG           (0x00 | 0x00 | MPR_USED_SNS_CNT)

/* The status bits in Status Register 0x00 and 0x01 will only take place after
 * the number of consecutive touch or release detection meets the debounce number setting. */
//#define DEBOUNCE_REG_VALUE  0x11
// ==== Filtering settings ====
const uint8_t Filtering[] = {
        0x2B,                   // Reg addr
        0x01, 0x01, 0x00, 0x00, // Rising:  MHD, NHD, NCL, FDL
        0x01, 0x01, 0xFF, 0x02, // Falling: MHD, NHD, NCL, FDL
//        0x00, 0x00, 0x00        // Touched
};

// ==== Touch / Release threshold ====
/* For very small electrodes, smaller values can be used and for very large electrodes
 * the reverse is true. One easy method is to view the deltas actually seen in a system
 * and set the touch at 80% and release at 70% of delta for good performance */
#define TOUCH_THRESHOLD     15
#define RELEASE_THRESHOLD   10
const uint8_t Thresholds[] = {
        0x41, // Reg addr
        TOUCH_THRESHOLD, RELEASE_THRESHOLD,
        TOUCH_THRESHOLD, RELEASE_THRESHOLD,
        TOUCH_THRESHOLD, RELEASE_THRESHOLD,
        TOUCH_THRESHOLD, RELEASE_THRESHOLD,
        TOUCH_THRESHOLD, RELEASE_THRESHOLD,
};

// ==== AFE Filter cfg ==== except ESI
const uint8_t AfeFilterCfg[] = {
        0x5C,   // Reg addr
        0x00,   // 6 samples (def), no charging
        0x04    // 4 samples (def), sampling intl=16ms(def)
};
#define FILTER_CFG  0x00    // Electrode charging dis, 4 samples (default)
// ==== Auto-configuration ====
#define FFI         0xC0    // Must be same in 0x7B and 0x5C. 00=6smpl(def), 40=10, 80=18, C0=34#define BVA_CL      0b10    // 10 - Baseline tracking enabled, initial baseline value is loaded with the 5 high bits of the first 10-bit electrode data valueconst uint8_t AutoCfg[] = {
        0x7B,           // Reg addr
        (FFI | (BVA_CL << 2) | 0b11), // Reg0; AutoCfg en, AutoRecfg en
        0x00, // Reg1; Both CDTx and CDCx will be searched and set by autoconfiguration and/or autoreconfiguration; no failure IRQs.
        ((256 * (MPR_VDD_MV - 700)) / MPR_VDD_MV),         // USL; AN3889 p.7
        ((256 * (MPR_VDD_MV - 700) * 65) / (100 * MPR_VDD_MV)), // LowSideLimit
        ((256 * (MPR_VDD_MV - 700) * 90) / (100 * MPR_VDD_MV)) // TargetLevel; AN3889 p.8
};
#endif

#if 1 // ==== Thread ====static WORKING_AREA(waMprThread, 256);__attribute__ ((__noreturn__))
static void MprThread(void *arg) {
    chRegSetThreadName("MprThd");
    while(true) Touch.ITask();
}

void mpr121_t::ITask() {
    chThdSleepMilliseconds(99);
    ReadOutput();
    if(Output.TouchStatus != 0) {
//        Uart.Printf("\r");
//        Uart.Printf("TS: %04X", Output.TouchStatus);
//        Uart.Printf("   ");
//        Uart.Printf("oo: %04X   ", Output.OorStatus);
//        for(uint8_t i=0; i<MPR_USED_SNS_CNT; i++) Uart.Printf("%04X ", Output.EleData[i]);
//        Uart.Printf("   ");
//        for(uint8_t i=0; i<MPR_USED_SNS_CNT; i++) Uart.Printf("%02X ", Output.Baseline[i]);
//        Uart.Printf("   ");
//        for(uint8_t i = 0; i < MPR_USED_SNS_CNT; i++) {
//            if(Output.TouchStatus & (1 << SnsIndx[i])) Uart.Printf("V ");
//            else Uart.Printf("_ ");
//        }

        xCurrent = CalcCoordinate();
        int32_t Fdx=0;
//        Uart.Printf("  x = %u", xCurrent);
        // ==== Handle events ====
        if(!WasTouched) {   // Evt OnTouch occured
            WasTouched = true;
            xPrev = xCurrent;
            if(App.PThd != nullptr) chEvtSignal(App.PThd, EVTMSK_ON_FINGER_TOUCH);
        }
        else {
            // Was touched already, check if OnMove
            Fdx = xCurrent - xPrev;
//            Uart.Printf("  dx1=%d;", Fdx);
            // Filter dx
//            Fdx = (Fdx + 9*dxPrev) / 10;
//            dxPrev = Fdx;
//            Uart.Printf("  dx1=%d;", dx);
            if(Fdx != 0) { // OnMove
                xPrev = xCurrent;
                dx = Fdx;
                if(App.PThd != nullptr) chEvtSignal(App.PThd, EVTMSK_ON_FINGER_MOVE);
            }
        } // WasTouched == true
    }
    else if(WasTouched) {
        WasTouched = false;
        // Evt OnDetouch
    }
}
#endif

#if 1 // ==== Calculations ====int32_t mpr121_t::CalcCoordinate() {    int32_t WeightedSum = 0, Sum = 0;
    for(uint8_t i = 0; i < MPR_USED_SNS_CNT; i++) {
        uint8_t n = SnsIndx[i];
        int32_t D = Output.EleData[n] & 0xFFFC;
        int32_t B = Output.Baseline[n] << 2; // The read out from the baseline register must be left shift two bits before comparing it with the 10-bit electrode data
        int32_t Delta = (D > B)? (D - B) : (B - D);
        WeightedSum += (i + 1) * Delta;
        Sum += Delta;
//        Uart.Printf("D%u=%d ", i, Delta);
    }
//    Uart.Printf("WSum=%d Sum=%d ", WeightedSum, Sum);
    if(WeightedSum == 0 or Sum == 0) return 0;
    else return (25 * WeightedSum / Sum) - 25;
}

#endif

void mpr121_t::Init() {
    i2c.Init(MPR_I2C, MPR_I2C_GPIO, MPR_SCL_PIN, MPR_SDA_PIN, MPR_I2C_BITRATE_HZ, MPR_DMATX, MPR_DMARX);
    Reset();
    chThdSleepMilliseconds(1);
    Write((void*)Filtering, countof(Filtering));
    Write((void*)Thresholds, countof(Thresholds));
    Write((void*)AutoCfg, countof(AutoCfg));
    chThdSleepMilliseconds(1);
    Write(0x5C, FFI);           // FFI must be same as in AutoCfg
    chThdSleepMilliseconds(1);
    SetSampleInterval(msi16);
    chThdSleepMilliseconds(1);

//    Irq.Setup(MPR_IRQ_GPIO, MPR_IRQ_PIN, ttFalling);
    PThd = chThdCreateStatic(waMprThread, sizeof(waMprThread), NORMALPRIO, (tfunc_t)MprThread, NULL);
    On();
}

void mpr121_t::On() {
    Write(0x5E, (ELECTRODE_CFG | (BVA_CL << 6)));
}
void mpr121_t::Off() {
    Write(0x5E, 0);
}

void mpr121_t::SetSampleInterval(mprSampleInterval_t SampleInterval) {
    Write(0x5D, FILTER_CFG | (uint8_t)SampleInterval);
}

void mpr121_t::Write(void *PRegData, uint8_t Length) {
    uint8_t r = i2c.CmdWriteWrite(MPR_I2C_ADDR, PRegData, Length, nullptr, 0);
    if(r != OK) Uart.Printf("\rmprW %A Fail", PRegData, Length, ' ');
    else Uart.Printf("\rmprW %A Ok", PRegData, Length, ' ');
}
void mpr121_t::Write(uint8_t RegAddr, uint8_t AData) {
    uint8_t Buf[2];
    Buf[0] = RegAddr;
    Buf[1] = AData;
    uint8_t r = i2c.CmdWriteWrite(MPR_I2C_ADDR, Buf, 2, nullptr, 0);
    if(r != OK) Uart.Printf("\rmprW %A Fail", Buf, 2, ' ');
    else Uart.Printf("\rmprW %A Ok", Buf, 2, ' ');
}

void mpr121_t::Read(uint8_t RegAddr, void *PData, uint8_t Length) {
    uint8_t r = i2c.CmdWriteRead(MPR_I2C_ADDR, &RegAddr, 1, PData, Length);
    if(r != OK) Uart.Printf("\rmprR %X Fail", RegAddr);
//    else Uart.Printf("\rmprR %A", PData, Length, ' ');
}
