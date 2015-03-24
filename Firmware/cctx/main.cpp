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

//static WORKING_AREA(waLedThread, 256);
//__attribute__ ((__noreturn__))
//static void LedThread(void *arg) {
//    chRegSetThreadName("LedThd");
//    while(true) {
//        PinSet(GPIOB, 7);
//        chThdSleepMilliseconds(207);
//        PinClear(GPIOB, 7);
//        chThdSleepMilliseconds(99);
//    }
//}


//Timer_t Tmr;

//#define MAX_TMR 10000

int main(void) {
    // ==== Init Vcore & clock system ====
   /* SetupVCore(vcore1V5);
    Clk.EnableHSI();
    Clk.SwitchToHSI();*/
    Clk.UpdateFreqValues();

    // ==== Init OS ====
    halInit();
    chSysInit();

    // ==== Init Hard & Soft ====
    PinSetupOut(GPIOB, 1, omPushPull, pudNone);
    PinSetupOut(GPIOB, 0, omPushPull, pudNone);

    Uart.Init(9600);
    // ==== Main cycle ====
    while(true) {
        chThdSleepMilliseconds(999);

        Uart.Printf("Hello STM32L151!\n");
    } // while true

}




