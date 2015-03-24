/*
 * cmd_uart.h
 *
 *  Created on: 15.04.2013
 *      Author: kreyl
 */

#ifndef CMD_UART_H_
#define CMD_UART_H_

#include "stm32l1xx.h"
#include "ch.h"
#include "hal.h"
#include "kl_sprintf.h"
#include "kl_lib_L15x.h"
#include <cstring>

// Set to true if RX needed
#define UART_RX_ENABLED     TRUE

// UART
#define UART_TXBUF_SIZE     1500


#define UART                USART1
#define UART_GPIO           GPIOA
#define UART_TX_PIN         9
#define UART_AF             AF7 // for all uarts
#define UART_RCC_ENABLE()   rccEnableUSART1(FALSE)

#define UART_DMA_TX         STM32_DMA1_STREAM4
#define UART_DMA_TX_MODE    DMA_PRIORITY_LOW | \
                            STM32_DMA_CR_MSIZE_BYTE | \
                            STM32_DMA_CR_PSIZE_BYTE | \
                            STM32_DMA_CR_MINC |       /* Memory pointer increase */ \
                            STM32_DMA_CR_DIR_M2P |    /* Direction is memory to peripheral */ \
                            STM32_DMA_CR_TCIE         /* Enable Transmission Complete IRQ */

#if UART_RX_ENABLED // ==== RX ====
#define UART_RXBUF_SZ       72 // unprocessed bytes
#define UART_CMD_BUF_SZ     54 // payload bytes
#define UART_RX_PIN         10
#define UART_RX_REG         UART->DR

#define UART_RX_POLLING_MS  99
#define UART_DMA_RX         STM32_DMA1_STREAM5
#define UART_DMA_RX_MODE    DMA_PRIORITY_LOW | \
                            STM32_DMA_CR_MSIZE_BYTE | \
                            STM32_DMA_CR_PSIZE_BYTE | \
                            STM32_DMA_CR_MINC |       /* Memory pointer increase */ \
                            STM32_DMA_CR_DIR_P2M |    /* Direction is peripheral to memory */ \
                            STM32_DMA_CR_CIRC         /* Circular buffer enable */
#endif

#define DELIMITERS      " ,"

class Cmd_t {
private:
    void Finalize() {
        for(uint32_t i=Cnt; i < UART_CMD_BUF_SZ; i++) IString[i] = 0;
        Name = strtok(IString, DELIMITERS);
        GetNextToken();
    }
    void Backspace() { if(Cnt > 0) Cnt--; }
    char IString[UART_CMD_BUF_SZ];
    uint32_t Cnt;
public:
    char *Name, *Token;
    void PutChar(char c) { if(Cnt < UART_CMD_BUF_SZ-1) IString[Cnt++] = c; }
    bool IsEmpty() { return (Cnt == 0); }
    uint8_t GetNextToken() {
        Token = strtok(NULL, DELIMITERS);
        return (*Token == '\0')? FAILURE : OK;
    }
    uint8_t TryConvertTokenToNumber(uint32_t *POutput) { return Convert::TryStrToUInt32(Token, POutput); }
    uint8_t TryConvertTokenToNumber( int32_t *POutput) { return Convert::TryStrToInt32(Token, POutput); }
    bool NameIs(const char *SCmd) { return (strcasecmp(Name, SCmd) == 0); }
    friend class CmdUart_t;
};

class CmdUart_t {
private:
    char TXBuf[UART_TXBUF_SIZE];
    char *PRead, *PWrite;
    bool IDmaIsIdle;
    uint32_t IFullSlotsCount, ITransSize;
    void ISendViaDMA();
#if UART_RX_ENABLED
    int32_t SzOld=0, RIndx=0;
    uint8_t IRxBuf[UART_RXBUF_SZ];
    Cmd_t ICmd[2], *PCmdWrite = &ICmd[0], *PCmdRead = &ICmd[1];
    void CompleteCmd();
#endif
public:
    void Printf(const char *S, ...);
    void PrintfI(const char *S, ...);
    void FlushTx() { while(!IDmaIsIdle); }  // wait DMA
    void PrintNow(const char *S) {
        while(*S != 0) {
            while(!(UART->SR & USART_SR_TXE));
            UART->DR = *S++;
        }
    }
    void Init(uint32_t ABaudrate);
    // Inner use
    void IRQDmaTxHandler();
    void IPutChar(char c);
    void IPrintf(const char *format, va_list args);
#if UART_RX_ENABLED
    void PollRx();
    // Command and reply
    void Ack(int32_t Result) { Printf("#Ack %d\r\n", Result); }
#endif
};

extern CmdUart_t Uart;

#endif /* CMD_UART_H_ */
