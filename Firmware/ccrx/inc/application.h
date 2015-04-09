/*
 * application.h
 *
 *  Created on: Nov 9, 2013
 *      Author: kreyl
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "kl_lib_L15x.h"

# if 1 // Uart Command Codes. See https://docs.google.com/document/d/1pGQf9CrQ016ObS0w7PhPLAy92MRPhdBriICflt1YGXA/edit
#define CMD_PING            0x01
#define CMD_PILL_STATE      0x30
#define CMD_PILL_WRITE      0x31
#define CMD_PILL_READ       0x32
#define CMD_DOSE_GET        0x60
#define CMD_DOSE_SET        0x61

#define RPL_ACK             0x90    // Acknowledge
#define RPL_PILL_STATE      0xC0
#define RPL_PILL_WRITE      0xC1
#define RPL_PILL_READ       0xC2
#define RPL_DOSE_GET        0xE0
#endif

#if 1 // ==== Timings ====
#endif

class App_t {
private:
public:
    Thread *PThd;
    void Init();
};

extern App_t App;

#endif /* APPLICATION_H_ */
