/*
 * radio_lvl1.h
 *
 *  Created on: Nov 17, 2013
 *      Author: kreyl
 */

#ifndef RADIO_LVL1_H_
#define RADIO_LVL1_H_

#include "ch.h"
#include "rPkt.h"
#include "kl_lib_L15x.h"
#include "cc1101.h"

class radio_t {
private:
    rPkt_t PktRx, PktTx;
    Thread *PThread;
    //int32_t NaturalDmg, RadioDmg;
    /*inline void GetDmgOutOfPkt() {
        int32_t prc = RSSI_DB2PERCENT(PktRx.RSSI);
//      Uart.Printf("%u\r", PktRx.ID);
        if(prc >= PktRx.MinLvl) {   // Only if signal level is enough
            if((PktRx.DmgMax == 0) and (PktRx.DmgMin == 0)) NaturalDmg = 0; // "Clean zone" emanator
            else {  // Ordinal emanator
                int32_t EmDmg = 0;
                if(prc >= PktRx.MaxLvl) EmDmg = PktRx.DmgMax;
                else {
                    int32_t DifDmg = PktRx.DmgMax - PktRx.DmgMin;
                    int32_t DifLvl = PktRx.MaxLvl - PktRx.MinLvl;
                    EmDmg = (prc * DifDmg + PktRx.DmgMax * DifLvl - PktRx.MaxLvl * DifDmg) / DifLvl;
                    if(EmDmg < 0) EmDmg = 0;
                }
                RadioDmg += EmDmg;
            }
        }
    }
    void IterateEmanators() {
        NaturalDmg = 1;
        RadioDmg = 0;
        // Iterate slow emanators
        for(uint8_t i=0; i<SLOW_EMANATOR_CNT; i++) {
            CC.SetChannel(CHANNEL_ZERO + i);
            if(CC.ReceiveSync(27, &PktRx) == OK) {
                GetDmgOutOfPkt();
//              if(RadioDmg != 0) Uart.Printf("%d; %d\r", prc, RadioDmg);
            } // if ok
        } // for
        // Sleep until asked
        CC.Sleep();
        chSysLock();
        Damage = NaturalDmg + RadioDmg;
        chSysUnlock();
    }*/
public:
    //uint32_t Damage;
    void Init(uint16_t ASelfID);
    // Inner use
    void ITask();
};

extern radio_t Radio;

#endif /* RADIO_LVL1_H_ */
