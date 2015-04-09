/*
 * peripheral.h
 *
 *  Created on: 18.01.2013
 *      Author: kreyl
 */

#ifndef PERIPHERAL_H_
#define PERIPHERAL_H_

#include <stdint.h>
#include "kl_lib_L15x.h"

enum ChunkKind_t {ckNormal=0, ckStop=1, ckRepeat=2};

#if 1 // ================================= Beep ================================
struct BeepChunk_t {
    uint8_t Volume;   // 0 means silence, 10 means top
    uint16_t Freq_Hz;
    uint16_t Time_ms;
    ChunkKind_t ChunkKind;
};
#define BEEP_CHUNK_SZ   sizeof(BeepChunk_t)
class Beeper_t {
private:
    VirtualTimer ITmr;
    const BeepChunk_t *IPFirstChunk;
public:
    void BeepI(const BeepChunk_t *PSequence);
    void Beep(const BeepChunk_t *PSequence) {   // Beep with this function
        IPFirstChunk = PSequence;
        chSysLock();
        BeepI(PSequence);
        chSysUnlock();
    }
    void Stop() {
        chSysLock();
        if(chVTIsArmedI(&ITmr)) chVTResetI(&ITmr);
        chSysUnlock();
        IPin.Set(0);
    }
    void Init();
    void Shutdown();
    // Inner use
    PwmPin_t IPin;
};
extern Beeper_t Beeper;
#endif

#if 1 // ============================== LED RGB ================================
// Colors
struct Color_t {
    uint8_t Red, Green, Blue;
    bool operator == (const Color_t AColor) { return ((Red == AColor.Red) and (Green == AColor.Green) and (Blue == AColor.Blue)); }
    //bool operator != (const Color_t AColor) { return ((this->Red != AColor.Red) || (this->Green != AColor.Green) || (this->Blue != AColor.Blue)); }
};
#define clBlack     ((Color_t){0,   0,   0})
#define clRed       ((Color_t){255, 0,   0})
#define clGreen     ((Color_t){0,   255, 0})
#define clBlue      ((Color_t){0,   0,   255})
#define clYellow    ((Color_t){255, 255, 0})
#define clMagenta   ((Color_t){255, 0, 255})
#define clCyan      ((Color_t){0, 255, 255})
#define clWhite     ((Color_t){255, 255, 255})

// Timer
#define LED_TIM         TIM3
#define LED_RED_CCR     CCR4
#define LED_GREEN_CCR   CCR3
#define LED_BLUE_CCR    CCR2
#define LED_RCC_EN()    rccEnableTIM3(FALSE)
#define LED_ALTERFUNC   AF2 // TIM3
// GPIO
#define LED_GPIO        GPIOB
#define LED_P1          0   // }
#define LED_P2          1   // }
#define LED_P3          5   // } No need to diff between colors, see CCR above

struct LedChunk_t {
    Color_t Color;
    uint16_t Time_ms;
    ChunkKind_t ChunkKind;
};
#define LED_CHUNK_SZ   sizeof(LedChunk_t)

class LedRGB_t {
private:
    const LedChunk_t *IPFirstChunk;
    VirtualTimer ITmr;
    void ISetRed  (uint8_t AValue) {LED_TIM->LED_RED_CCR   = AValue;}
    void ISetGreen(uint8_t AValue) {LED_TIM->LED_GREEN_CCR = AValue;}
    void ISetBlue (uint8_t AValue) {LED_TIM->LED_BLUE_CCR  = AValue;}
public:
    void Init();
    void SetColor(Color_t AColor) {
        ISetRed(AColor.Red);
        ISetGreen(AColor.Green);
        ISetBlue(AColor.Blue);
    }
    void StartBlink(const LedChunk_t *PLedChunk) {
        chSysLock();
        IPFirstChunk = PLedChunk; // Save first chunk
        IStartBlinkI(PLedChunk);
        chSysUnlock();
    }
    void StopBlink() {
        chSysLock();
        if(chVTIsArmedI(&ITmr)) chVTResetI(&ITmr);
        SetColor(clBlack);
        chSysUnlock();
    }
    // Inner use
    void IStartBlinkI(const LedChunk_t *PLedChunk);
};

extern LedRGB_t Led;
#endif

#if 1 // ================================ Vibro ================================
#define VIBRO_ENABLED   TRUE
#define VIBRO_GPIO      GPIOB
#define VIBRO_PIN       6

enum StateOnOff_t {stOn, stOff};
struct VibroChunk_t {
    StateOnOff_t OnOff;
    uint16_t Time_ms;
    ChunkKind_t ChunkKind;
} PACKED;
#define VIBRO_CHUNK_SZ   sizeof(VibroChunk_t)

class Vibro_t {
private:
    VirtualTimer ITmr;
    const VibroChunk_t *IPFirstChunk;
public:
    void Flinch(const VibroChunk_t *PSequence) {   // Beep with this function
        IPFirstChunk = PSequence;
        chSysLock();
        IFlinchI(PSequence);
        chSysUnlock();
    }
    void Stop() {
        chSysLock();
        if(chVTIsArmedI(&ITmr)) chVTResetI(&ITmr);
        chSysUnlock();
        PinClear(VIBRO_GPIO, VIBRO_PIN);
    }
    void Init();
    // Inner use
    void IFlinchI(const VibroChunk_t *PSequence);
};
extern Vibro_t Vibro;
#endif

#endif /* PERIPHERAL_H_ */
