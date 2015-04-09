/*
 * eestore.cpp
 *
 *  Created on: 14 но€б. 2013 г.
 *      Author: Kreyl
 */

#include "eestore.h"

uint8_t EEStore_t::GetLastValuedPtr(EEChunk32_t** PPtr) {
    EEChunk32_t *p = EE_PTR_FIRST, *pprev = EE_PTR_FIRST;
    // Check if anything is stored
    if(p->Sign != EE_STORE_SIGN) return FAILURE;
    // Iterate through array
    for(uint32_t i=1; i < EE_CNT; i++) {
        p++;    // Next chunk
        // Check if nothing or data tail
        if((p->Sign != EE_STORE_SIGN) or ((pprev->Counter + 1) != p->Counter)) {
            *PPtr = pprev;
            return OK;
        }
        pprev = p;
    }
    // Will be here if counter diff was 1 all the way. Return Last value.
    *PPtr = p;
    return OK;
}

uint8_t EEStore_t::Put(uint32_t *Ptr) {
    EEChunk32_t *p = EE_PTR_FIRST, Chunk;
    Chunk.Data = *Ptr;
    Chunk.Sign = EE_STORE_SIGN;
    if(GetLastValuedPtr(&p) != OK) Chunk.Counter = 0;    // Nothing is written yet
    else {
        Chunk.Counter = p->Counter + 1;
        // Increase pointer
        if(p == EE_PTR_LAST) p = EE_PTR_FIRST;  // Reset if last
        else p++;
    }
    // Write data
    volatile uint32_t *PDst32 = (uint32_t*)p;
    uint32_t *PSrc32 = (uint32_t*)&Chunk;
    UnlockEE();
    chSysLock();
    // Wait for last operation to be completed
    uint8_t r = WaitForLastOperation();
    if(r == OK) {
        *PDst32++ = *PSrc32++;
        r = WaitForLastOperation();
        if(r == OK) {
            *PDst32 = *PSrc32;
            r = WaitForLastOperation();
        }
    }
    LockEE();
    chSysUnlock();
    return r;
}

uint8_t EEStore_t::Get(uint32_t *Ptr) {
    EEChunk32_t *p;
    if(GetLastValuedPtr(&p) == OK) {
        *Ptr = p->Data;
        return OK;
    }
    else return FAILURE;
}

// Just writes 0 at first position
void EEStore_t::Remove() {
    UnlockEE();
    uint8_t r = WaitForLastOperation();
    if(r == OK) {
        *(volatile uint32_t*)(EEPROM_BASE_ADDR + EE_START_ADDR) = 0;
        WaitForLastOperation();
    }
    LockEE();
}
