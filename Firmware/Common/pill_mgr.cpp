/*
 * pill.cpp
 *
 *  Created on: Apr 17, 2013
 *      Author: g.kruglov
 */

#include "pill_mgr.h"

PillMgr_t PillMgr;

void PillMgr_t::Init() {
    chSemInit(&Sem, 0); // Requesting Thread will be queued
    Deinit();
    PinSetupOut(PERIPH_PWR_GPIO, PERIPH_PWR_PIN, omPushPull);   // Power
    PinSet(PERIPH_PWR_GPIO, PERIPH_PWR_PIN);
    chThdSleepMilliseconds(1);  // Allow power to rise
    i2c.Init(PILL_I2C, PILL_I2C_GPIO, PILL_SCL_PIN, PILL_SDA_PIN, PILL_I2C_BITRATE_HZ, PILL_DMATX, PILL_DMARX);
    chSemSignal(&Sem);
}

void PillMgr_t::Deinit() {
    PinClear(PERIPH_PWR_GPIO, PERIPH_PWR_PIN);
    chThdSleepMilliseconds(1);  // Allow power to fade
    PinSetupAnalog(PERIPH_PWR_GPIO, PERIPH_PWR_PIN);    // Power
    i2c.Standby();
}

void PillMgr_t::ResetBus() {
    Deinit();
    PinSetupOut(PERIPH_PWR_GPIO, PERIPH_PWR_PIN, omPushPull);   // Power
    PinSet(PERIPH_PWR_GPIO, PERIPH_PWR_PIN);
    chThdSleepMilliseconds(1);  // Allow power to rise
    i2c.Resume();
}

uint8_t PillMgr_t::CheckIfConnected(uint8_t i2cAddr) {
    chSemWait(&Sem);
    uint8_t Rslt = i2c.CmdWriteWrite(i2cAddr, NULL, 0, NULL, 0);
    if(i2c.Error == true) ResetBus();
    chSemSignal(&Sem);
    return Rslt;
}

uint8_t PillMgr_t::Read(uint8_t i2cAddr, uint8_t *Ptr, uint32_t Length) {
    chSemWait(&Sem);
    uint8_t WordAddress = PILL_START_ADDR;
    uint8_t Rslt = i2c.CmdWriteRead(i2cAddr, &WordAddress, 1, Ptr, Length);
    if(i2c.Error == true) ResetBus();
    chSemSignal(&Sem);
    return Rslt;
}

uint8_t PillMgr_t::Write(uint8_t i2cAddr, uint8_t *Ptr, uint32_t Length) {
    chSemWait(&Sem);
    uint8_t WordAddress = PILL_START_ADDR;
    uint8_t Rslt = OK;
    // Write page by page
    while(Length) {
        uint8_t ToWriteCnt = (Length > PILL_PAGE_SZ)? PILL_PAGE_SZ : Length;
        Rslt = i2c.CmdWriteWrite(i2cAddr, &WordAddress, 1, Ptr, ToWriteCnt);
        if(Rslt == OK) {
            chThdSleepMilliseconds(5);   // Allow memory to complete writing
            Length -= ToWriteCnt;
            Ptr += ToWriteCnt;
            WordAddress += ToWriteCnt;
        }
        else break;
    }
    if(i2c.Error == true) ResetBus();
    chSemSignal(&Sem);
    return Rslt;
}
