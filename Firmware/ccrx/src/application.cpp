/*
 * application.cpp
 *
 *  Created on: Nov 9, 2013
 *      Author: kreyl
 */

#include "application.h"
#include "cmd_uart.h"
#include <stdlib.h>
#include "radio.h"

App_t App;
#define UART_RPL_BUF_SZ     36
//static uint8_t SBuf[UART_RPL_BUF_SZ];


#if 1 // ============================ Timers ===================================
#endif

#if 1 // ========================= Application =================================
// Snd coeffs
#define DMG_SND_MAX     1000
#define DMG_SND_BCKGND  40
#define DMG_MAX         10      // Maximum radiation value
#define DMG2SNDDMG(dmg) ((((DMG_SND_MAX - DMG_SND_BCKGND) * ((dmg) - 1)) / (DMG_MAX - 1)) + DMG_SND_BCKGND)
// Just for example
#define DMG_SND_MID     220
#define DMG_SND_HEAVY   700

static WORKING_AREA(waAppThread, 256);
__attribute__((noreturn))
static void AppThread(void *arg) {
    chRegSetThreadName("App");
    while(true) {
        chThdSleepMilliseconds(18);
    } // while 1
}

void App_t::Init() {
    /*rccEnableTIM2(FALSE);
    PinSetupAlterFunc(GPIOB, 3, omPushPull, pudNone, AF1);
    TIM2->CR1 = TIM_CR1_CEN | TIM_CR1_OPM;
    TIM2->CR2 = 0;
    TIM2->ARR = 22;
    TIM2->CCMR1 |= (0b111 << 12);
    TIM2->CCER  |= TIM_CCER_CC2E;

    uint32_t divider = TIM2->ARR * 1000;
    uint32_t FPrescaler = Clk.APB1FreqHz / divider;
    if(FPrescaler != 0) FPrescaler--;
    TIM2->PSC = (uint16_t)FPrescaler;
    TIM2->CCR2 = 20;*/

    PThd = chThdCreateStatic(waAppThread, sizeof(waAppThread), NORMALPRIO, (tfunc_t)AppThread, NULL);
}
#endif

#if 1 // ======================= Command processing ============================
void Ack(uint8_t Result) { Uart.Cmd(0x90, &Result, 1); }

void UartCmdCallback(uint8_t CmdCode, uint8_t *PData, uint32_t Length) {
    switch(CmdCode) {
        case CMD_PING: Ack(OK); break;

        default: break;
    } // switch
}
#endif
