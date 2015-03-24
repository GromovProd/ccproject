/*
 * File:   main.cpp
 * Author: Kreyl
 * Project: ChibiArmlet-Atlantis
 *
 * Created on Feb 05, 2013, 20:27
 */

#include "kl_lib_L15x.h"
#include "ch.h"
#include "hal.h"
#include "clocking_L1xx.h"
#include "cmd_uart.h"

#include "Radio/rPkt.h"
#include "Radio/cc1101.h"

#define DBG_PINS

#ifdef DBG_PINS
#define DBG_GPIO1   GPIOA
#define DBG_PIN1    15
#define DBG1_SET()  PinSet(DBG_GPIO1, DBG_PIN1)
#define DBG1_CLR()  PinClear(DBG_GPIO1, DBG_PIN1)
#endif

rPkt_t PktTx;

int main(void) {
    // ==== Init Vcore & clock system ====
    SetupVCore(vcore1V5);
    Clk.EnableHSI();
    Clk.SwitchToHSI();
    Clk.UpdateFreqValues();

    // ==== Init OS ====
    halInit();
    chSysInit();

    // ==== Init Hard & Soft ====
    PinSetupOut(GPIOB, 1, omPushPull, pudNone);

    //Uart.Init(115200);
    CC.Init();
    CC.SetTxPower(CC_PwrPlus5dBm);
    CC.SetChannel(CHANNEL_ZERO);

    PktTx.Value = 8;
    PktTx.RSSI = 1;
    // ==== Main cycle ====
    while(true) {
        //PinSet(GPIOB, 1);
        CC.Recalibrate(); // Recalibrate manually every cycle, as auto recalibration disabled
        // Transmit
        DBG1_SET();
        CC.TransmitSync(&PktTx);
        DBG1_CLR();
        chThdSleepMilliseconds(20);
        //PinClear(GPIOB, 1);
        //chThdSleepMilliseconds(100);

    } // while true

}

