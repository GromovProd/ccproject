/*
 * File:   main.cpp
 * Author: Kreyl
 * Project: Armlet2South
 *
 * Created on Feb 05, 2013, 20:27
 */

#include "kl_lib_L15x.h"
#include "ch.h"
#include "hal.h"
#include "clocking_L1xx.h"
#include "cmd_uart.h"
#include "radio.h"
#include "application.h"

static inline void Init();

#define LED_N       0

#define LED_ON()    PinSet(GPIOB, LED_N)
#define LED_OFF()   PinClear(GPIOB, LED_N)

int main(void) {
    // ==== Init Vcore & clock system ====
    SetupVCore(vcore1V8);
    //Clk.SetupFlashLatency(24);  // Setup Flash Latency for clock in MHz
//    Clk.SetupBusDividers(ahbDiv1, apbDiv1, apbDiv1);
    Clk.UpdateFreqValues();

    // ==== Init OS ====
    halInit();
    chSysInit();
    // ==== Init Hard & Soft ====
    Init();
//    if(ClkResult) Uart.Printf("Clock failure\r");

    while(1) {
        //chThdSleepMilliseconds(999);
        chSysLock();
        chThdSleepS(TIME_INFINITE); // Forever
        chSysUnlock();
    } // while
}

void Init() {
    Uart.Init(115200);
    Uart.Printf("ccTX\n");
    PinSetupOut(GPIOB, LED_N, omPushPull);
    LED_ON();

    Radio.Init(0);  // FIXME: read ID somehow
}
