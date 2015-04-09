/*
 * pill.h
 *
 *  Created on: Apr 17, 2013
 *      Author: g.kruglov
 */

#ifndef PILL_H_
#define PILL_H_

#include "cmd_uart.h"
#include "ch.h"

#define PILL_I2C_STD_ADDR   0x50    // Standard address start of EEPROM - 0x01010aaa
#define PILL_I2C_ADDR       (PILL_I2C_STD_ADDR | 0) // Only Zero supported
#define PILL_START_ADDR     0x00    // Address of data
// Number of bytes to be written simultaneously. IC dependant, see datasheet.
#define PILL_PAGE_SZ        8

// I2C & hardware
#define PERIPH_PWR_GPIO     GPIOB
#define PERIPH_PWR_PIN      7
#define PILL_I2C_GPIO       GPIOB
#define PILL_SCL_PIN        8
#define PILL_SDA_PIN        9

#define PILL_I2C            I2C1
#define PILL_I2C_BITRATE_HZ 200000
#define PILL_DMATX          STM32_DMA1_STREAM6
#define PILL_DMARX          STM32_DMA1_STREAM7

class PillMgr_t {
private:
    Semaphore Sem;
    i2c_t i2c;
    void Deinit();
    void ResetBus();
public:
    void Init();
    uint8_t CheckIfConnected(uint8_t i2cAddr);
    uint8_t Read (uint8_t i2cAddr, uint8_t *Ptr, uint32_t Length);
    uint8_t Write(uint8_t i2cAddr, uint8_t *Ptr, uint32_t Length);
};

extern PillMgr_t PillMgr;

#endif /* PILL_H_ */
