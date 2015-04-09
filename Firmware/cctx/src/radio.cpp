/*
 * radio_lvl1.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: kreyl
 */

#include "radio.h"
#include "evt_mask.h"
#include "cc1101.h"
#include "cmd_uart.h"

#define DBG_PINS

#ifdef DBG_PINS
#define DBG_GPIO1   GPIOA
#define DBG_PIN1    15
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
    chThdSleepMilliseconds(20);
    CC.Recalibrate();   // Recalibrate manually every cycle, as auto recalibration disabled
    // Transmit
    DBG1_SET();
    CC.TransmitAsync(&PktTx);
    DBG1_CLR();
}
#endif

#if 1 // ============================
void radio_t::Init(uint16_t ASelfID) {
    PinSetupOut(DBG_GPIO1, DBG_PIN1, omPushPull);
    // Init RadioPkt
    PktTx.Value=0xF0;
    // Init radioIC
    CC.Init();
    //CC.SetTxPower(CC_PwrMinus30dBm);
    CC.SetTxPower(CC_PwrPlus5dBm);
    CC.SetChannel(CHANNEL_ZERO);
    // Variables
    // Thread
    chThdCreateStatic(warradioThread, sizeof(warradioThread), HIGHPRIO, (tfunc_t)radioThread, NULL);
}
#endif
