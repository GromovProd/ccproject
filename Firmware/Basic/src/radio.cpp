/*
 * radio_lvl1.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: kreyl
 */

#include "radio.h"
#include "evt_mask.h"
#include "application.h"
#include "cc1101.h"
#include "cmd_uart.h"

#include "peripheral.h"

#define DBG_PINS

#ifdef DBG_PINS
#define DBG_GPIO1   GPIOB
#define DBG_PIN1    14
#define DBG1_SET()  PinSet(DBG_GPIO1, DBG_PIN1)
#define DBG1_CLR()  PinClear(DBG_GPIO1, DBG_PIN1)
#endif


radio_t Radio;

#if 1 // ================================ Task =================================
static WORKING_AREA(warradioThread, 256);
__attribute__((noreturn))
static void radioThread(void *arg) {
    chRegSetThreadName("radio");
    while(true) Radio.ITask();
}

//#define TX
#define RX

void radio_t::ITask() {
    while(true) {
        // New cycle begins
        CC.Recalibrate();   // Recalibrate manually every cycle, as auto recalibration disabled

#ifdef TX
        // Transmit
        DBG1_SET();
        CC.TransmitSync(&PktTx);
        DBG1_CLR();
        chThdSleepMilliseconds(99);

#elif defined RX
        uint8_t RxRslt = CC.ReceiveSync(306, &PktRx);
        if(RxRslt == OK) {
            Uart.Printf("%d\r", PktRx.RSSI);
        }
#else
        //IterateEmanators();
//        Uart.Printf("%d\r", Damage);
        chThdSleepMilliseconds(45);
#endif
    } // while true
}

#endif

#if 1 // ============================
void radio_t::Init(uint16_t ASelfID) {
#ifdef DBG_PINS
    PinSetupOut(DBG_GPIO1, DBG_PIN1, omPushPull);
#endif
    // Init radioIC
    CC.Init();
    CC.SetTxPower(CC_Pwr0dBm);
    CC.SetChannel(CHANNEL_ZERO);
    // Thread
    PThread = chThdCreateStatic(warradioThread, sizeof(warradioThread), HIGHPRIO, (tfunc_t)radioThread, NULL);
}
#endif
