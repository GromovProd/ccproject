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

rPkt_t PktRx;

bool isON = false;
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
    PinSetupOut(GPIOB, 0, omPushPull, pudNone);

    Uart.Init(115200);

    CC.Init();
    CC.SetChannel(CHANNEL_ZERO);
    // ==== Main cycle ====
    while(true) {

        CC.Recalibrate();

        if(CC.ReceiveSync(30, &PktRx) == OK) {
            PinSet(GPIOB, 1);
            chThdSleepMilliseconds(2000);
            PinClear(GPIOB, 1);
            chThdSleepMilliseconds(2000);
        }
        if(isON) {
            PinSet(GPIOB, 0);
        }
        else {
            PinClear(GPIOB, 0);
        }
        isON = isON? false : true;

    } // while true

}
