/*
 * radio_lvl1.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: kreyl
 */

#include "radio.h"
#include "evt_mask.h"
#include "application.h"
#include "cmd_uart.h"

//#define DBG_PINS

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

void radio_t::ITask() {
    CC.Recalibrate();
    CC.ReceiveAsync();
    while(true) {
//        Uart.Printf("c");
        // New cycle begins
        //CC.Recalibrate();   // Recalibrate manually every cycle, as auto recalibration disabled
        //CC.ReceiveAsync();
        //CC.EnterIdle();
        //if(CC.ReceiveSync(30, &PktRx) == OK) {
            //Uart.Printf("%d hi\n",PktRx.RSSI);
        //}

        int8_t rssi = CC.ReadRSSI();
        Uart.Printf("%d dBm\n",rssi);
        //IterateEmanators();
        //Uart.Printf("%d\r", Damage);
        chThdSleepMilliseconds(45);
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
