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
#include "sequences.h"
#include "evt_mask.h"
#include "eestore.h"
#include "radio.h"

App_t App;
#define UART_RPL_BUF_SZ     36
static uint8_t SBuf[UART_RPL_BUF_SZ];

#if 1 // ================================ Pill =================================
struct Pill_t {
    uint16_t ID;
    uint16_t Charge;
    uint32_t Value;
} __attribute__ ((__packed__));
static Pill_t Pill;

void App_t::IPillHandler() {
    // Read med
    if(PillMgr.Read(PILL_I2C_ADDR, (uint8_t*)&Pill, sizeof(Pill_t)) != OK) return;
    //Uart.Printf("Pill: %u, %X, %u\r", Pill.ID, Pill.Charge, Pill.Value);
//    if((Pill.ID == PILL_ID_CURE) and (Pill.Charge != 0)) {
//        bool Rslt = OK;
//        // Lower charges if not infinity
//        if(Pill.Charge != INFINITY16) {
//            Pill.Charge--;
//            Rslt = PillMgr.Write(PILL_I2C_ADDR, (uint8_t*)&Pill, sizeof(Pill_t));
//        }
//        if(Rslt == OK) {
//            Beeper.Beep(BeepPillOk);
//            Led.StartBlink(LedPillOk);
//            // Decrease dose if not dead, or if this is panacea
//            if((Dose.State != hsDeath) or (Pill.Charge == INFINITY16)) Dose.Decrease(Pill.Value, diNeverIndicate);
//            chThdSleep(2007);    // Let indication to complete
//            Dose.ChangeIndication();
//            return;
//        }
//    } // if Cure
    // Will be here in case of strange/discharged pill
    Beeper.Beep(BeepPillBad);
//    Led.StartBlink(LedPillBad);
    chThdSleep(2007);    // Let indication to complete
//    Dose.ChangeIndication();
}

#endif

#if 1 // ============================ Timers ===================================
static VirtualTimer ITmrDose, ITmrDoseSave, ITmrPillCheck;
void TmrDoseCallback(void *p) {
    chSysLockFromIsr();
    chEvtSignalI(App.PThd, EVTMSK_DOSE_INC);
    chVTSetI(&ITmrDose,      MS2ST(TM_DOSE_INCREASE_MS), TmrDoseCallback, nullptr);
    chSysUnlockFromIsr();
}
void TmrDoseSaveCallback(void *p) {
    chSysLockFromIsr();
    chEvtSignalI(App.PThd, EVTMSK_DOSE_STORE);
    chVTSetI(&ITmrDoseSave,  MS2ST(TM_DOSE_SAVE_MS),     TmrDoseSaveCallback, nullptr);
    chSysUnlockFromIsr();
}
void TmrPillCheckCallback(void *p) {
    chSysLockFromIsr();
    chEvtSignalI(App.PThd, EVTMSK_PILL_CHECK);
    chVTSetI(&ITmrPillCheck, MS2ST(TM_PILL_CHECK_MS),    TmrPillCheckCallback, nullptr);
    chSysUnlockFromIsr();
}
#endif

#if 1 // ========================= Application =================================
static WORKING_AREA(waAppThread, 256);
__attribute__((noreturn))
static void AppThread(void *arg) {
    chRegSetThreadName("App");
    uint32_t EvtMsk;
    bool PillConnected = false;
    while(true) {
        EvtMsk = chEvtWaitAny(ALL_EVENTS);
        // ==== Process dose ====
//        if(EvtMsk & EVTMSK_DOSE_INC) {
//            // Check if radio damage occured. Will return 1 if no.
//            uint32_t FDamage = Radio.Damage;
//            //if(FDamage != 1) Uart.Printf("Dmg=%u\r", FDamage);
//            Dose.Increase(FDamage, diUsual);
//            //Uart.Printf("Dz=%u; Dmg=%u\r", Dose.Get(), FDamage);
//        }

        // ==== Store dose ====
//        if(EvtMsk & EVTMSK_DOSE_STORE) {
//            //if(Dose.Save() != OK) Uart.Printf("EE Fail\r");   // DEBUG
//        }

        // ==== Check pill ====
        if(EvtMsk & EVTMSK_PILL_CHECK) {
            // Check if new connection occured
            if(PillMgr.CheckIfConnected(PILL_I2C_ADDR) == OK) {
                if(!PillConnected) {
                    PillConnected = true;
                    App.IPillHandler();
                }
            }
            else PillConnected = false;
        } // if EVTMSK_PILL_CHECK
    } // while 1
}

void App_t::Init() {
    //Dose.Load();
//    Uart.Printf("Dose = %u\r", Dose.Get());
    PThd = chThdCreateStatic(waAppThread, sizeof(waAppThread), NORMALPRIO, (tfunc_t)AppThread, NULL);
    // Timers init
    chSysLock();
//    chVTSetI(&ITmrDose,      MS2ST(TM_DOSE_INCREASE_MS), TmrDoseCallback, nullptr);
//    chVTSetI(&ITmrDoseSave,  MS2ST(TM_DOSE_SAVE_MS),     TmrDoseSaveCallback, nullptr);
    chVTSetI(&ITmrPillCheck, MS2ST(TM_PILL_CHECK_MS),    TmrPillCheckCallback, nullptr);
    chSysUnlock();
}
#endif
