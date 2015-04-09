/*
 * application.cpp
 *
 *  Created on: Nov 9, 2013
 *      Author: kreyl
 */

#include "application.h"
#include "cmd_uart.h"
#include "pill_mgr.h"
#include "peripheral.h"
#include "evt_mask.h"
#include "eestore.h"

App_t App;
#define UART_RPL_BUF_SZ     36
//static uint8_t SBuf[UART_RPL_BUF_SZ];


#if 1 // ============================ Timers ===================================
#endif

#if 0 // ========================= Application =================================
static WORKING_AREA(waAppThread, 256);
__attribute__((noreturn))
static void AppThread(void *arg) {
    chRegSetThreadName("App");
    uint32_t EvtMsk;
    while(true) {
        EvtMsk = chEvtWaitAny(ALL_EVENTS);

    } // while 1
}

void App_t::Init() {
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
