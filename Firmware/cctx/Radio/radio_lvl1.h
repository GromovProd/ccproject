/*
 * radio_lvl1.h
 *
 *  Created on: Nov 17, 2013
 *      Author: kreyl
 */

/*
#ifndef RADIO_LVL1_H_
#define RADIO_LVL1_H_
*/

#include "ch.h"
#include "kl_lib_L15x.h"
#include "cc1101.h"
#include "rPkt.h"

class rLevel1_t {
private:
    rPkt_t PktRx, PktTx;
    Thread *PThread;
    int32_t NaturalDmg, RadioDmg;
    inline void GetDmgOutOfPkt() {
        int32_t prc = RSSI_DB2PERCENT(PktRx.RSSI);
//      Uart.Printf("%u\r", PktRx.ID);

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
    }
public:
    uint32_t Damage;
    void Init(uint16_t ASelfID);
    // Inner use
    void ITask();
};

extern rLevel1_t Radio;

#endif /* RADIO_LVL1_H_ */
