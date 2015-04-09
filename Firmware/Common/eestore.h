/*
 * eestore.h
 *
 *  Created on: 14 но€б. 2013 г.
 *      Author: Kreyl
 */

#ifndef EESTORE_H_
#define EESTORE_H_

#include "kl_lib_L15x.h"

/*
 * Data is stored repeatedly, thus EEPROM wearing is distributed.
 * Generally, data is stored as such: { Counter16, EE_Sign16, Payload32 }
 */
#define EE_STORE_SIGN   0x157A  // == "ista", "know" on Quenya

struct EEChunk32_t {
    uint16_t Counter;
    uint16_t Sign;
    uint32_t Data;
} __attribute__ ((__packed__));
#define EE_CHUNK_SZ     sizeof(EEChunk32_t)

#define EE_START_ADDR   16  // Not 0 just in case
#define EE_CNT          250
#define EE_PTR_FIRST    ((EEChunk32_t*)(EEPROM_BASE_ADDR + EE_START_ADDR))
#define EE_PTR_LAST     ((EEChunk32_t*)(EEPROM_BASE_ADDR + EE_START_ADDR + (EE_CNT - 1) * EE_CHUNK_SZ))

class EEStore_t : private Flash_t {
private:
    uint8_t GetLastValuedPtr(EEChunk32_t** PPtr);
public:
    void Remove();
    uint8_t Put(uint32_t *Ptr);
    uint8_t Get(uint32_t *Ptr);
};

#endif /* EESTORE_H_ */
