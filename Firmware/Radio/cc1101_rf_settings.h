/*
 * File:   cc_rf_settings.h
 * Author: Kreyl Laurelindo
 *
 * Created on 7 Март 2010 г., 12:42
 */

#ifndef _CC_RF_SETTINGS_H
#define	_CC_RF_SETTINGS_H
// All this is for 27.0 MHz crystal, and for 868 MHz carrier

// Bitrate

// ============================ Common use values ==============================
#define CC_TX_FIFO_SIZE     33
#define CC_RX_FIFO_SIZE     32

// ===================== Frequency 868 MHz: RF Studio ==========================
#define CC_FREQ2_VALUE      0x20        // Frequency control word, high byte.
#define CC_FREQ1_VALUE      0x25        // Frequency control word, middle byte.
#define CC_FREQ0_VALUE      0xED        // Frequency control word, low byte.

// =================================== Common ==================================
//#define CC_MCSM0_VALUE      0x18        // Calibrate at IDLE->RX,TX

// Clear channel signal
#define CC_CCA_MODE         0b00000000  // Always clear
//#define CC_CCA_MODE         0b00100000  // Unless currently receiving a packet
#define CC_RXOFF_MODE       0b00000000  // RX->IDLE
//#define CC_RXOFF_MODE       0b00001100  // RX->RX
#define CC_TXOFF_MODE       0b00000000  // TX->IDLE

#define CC_MCSM2_VALUE      0b00000111  // WOR settings, nothing interesting here
#define CC_MCSM1_VALUE      (CC_CCA_MODE | CC_RXOFF_MODE | CC_TXOFF_MODE)
#define CC_MCSM0_VALUE      0x08        // Never calibrate

#define CC_FIFOTHR_VALUE    0b00000111  // RX attenuation = 0; RXFIFO and TXFIFO thresholds: TX 33, RX 32
//#define CC_IOCFG2_VALUE     0x07        // GDO2 - Asserts when a packet has been received with CRC OK. De-asserts when the first byte is read from the RX FIFO.
//#define CC_IOCFG0_VALUE     0x06        // GDO0 - Asserts when sync word has been sent / received, and de-asserts at the end of the packet.

#define CC_IOCFG2_VALUE     0x0C        // GDO2 - Asserts when a packet has been received with CRC OK. De-asserts when the first byte is read from the RX FIFO.
#define CC_IOCFG0_VALUE     0x0B

//#define CC_PKTCTRL1_VALUE   0b00001110  // PQT=0, CRC autoflush=1, Append=1, Address check = 10 (check, 0 is broadcast)
#define CC_PKTCTRL1_VALUE   0b00001100  // PQT=0, CRC autoflush=1, Append=1, Address check = 00 (no check)
#define CC_PKTCTRL0_VALUE   0b00010010//0b01000100  // WhiteData=1, PKTFormat=normal, CRC enabled, Fixed Length
//#define CC_PKTCTRL0_VALUE   0b00000100  // WhiteData=0, PKTFormat=normal, CRC enabled, Fixed Length
//#define CC_PKTCTRL0_VALUE   0b00000000  // WhiteData=0, PKTFormat=normal, CRC disabled, Fixed Length
#define CC_ADDR_VALUE       0x01        // Device address.

// ========================= Bitrate-specific ==================================
#define CC_FSCTRL1_VALUE    0x0C        // }
#define CC_FSCTRL0_VALUE    0x00        // } Frequency synthesizer control: RF studio, nothing to do here

#define CC_MDMCFG4_VALUE    0x2D        // }
#define CC_MDMCFG3_VALUE    0x2F        // } Modem configuration: RF Studio, nothing to do here
#define CC_MDMCFG2_VALUE    0x00//0x13        // Filter, modulation format, no Manchester coding, SYNC_MODE=011 => 30/32 sync word bits
//#define CC_MDMCFG2_VALUE    0x11        // Filter, modulation format, no Manchester coding, SYNC_MODE=001 => 15/16 sync word bits
//#define CC_MDMCFG2_VALUE    0x14        // Filter, modulation format, no Manchester coding, SYNC_MODE=100
#define CC_MDMCFG1_CHANSPC_E    0x02    // Exponent of Channel Spacing
//#define CC_MDMCFG1_VALUE    (0b10100000 | CC_MDMCFG1_CHANSPC_E)  // FEC=1, Preamble length=010 => 4bytes
#define CC_MDMCFG1_VALUE    (0b00100000 | CC_MDMCFG1_CHANSPC_E)  // FEC=0, Preamble length=010 => 4bytes
//#define CC_MDMCFG1_VALUE    (0b10000000 | CC_MDMCFG1_CHANSPC_E)  // FEC=1, Preamble length=000 => 2bytes
//#define CC_MDMCFG1_VALUE    (0b11000000 | CC_MDMCFG1_CHANSPC_E)  // FEC=1, Preamble length=100 => 8bytes
#define CC_MDMCFG0_VALUE    0xE5        // Channel spacing mantissa. See exponent at MDMCFG1. RF studio.

#define CC_DEVIATN_VALUE    0x62        // Modem deviation setting - RF studio, nothing to do here
#define CC_FREND1_VALUE     0xB6        // Front end RX configuration - RF studio, no docs, nothing to do
#define CC_FREND0_VALUE     0x10        // Front end TX configuration - RF studio, no docs, nothing to do

#define CC_FOCCFG_VALUE     0x1D        // Frequency Offset Compensation - RF studio, some unknown reasons for settings
#define CC_BSCFG_VALUE      0x1C        // Bit synchronization Configuration - RF studio, some unknown reasons for settings
#define CC_AGCCTRL2_VALUE   0xC7        // AGC control: 00 - all gain settings, 000 - max possible gain, 111 - target ampl=42dB
#define CC_AGCCTRL1_VALUE   0x00        // Generally, nothing interesting
#define CC_AGCCTRL0_VALUE   0xB0        // AGC filter settings: RF studio, some unknown reasons for settings

#define CC_FSCAL3_VALUE     0xEA        // }
#define CC_FSCAL2_VALUE     0x2A        // }
#define CC_FSCAL1_VALUE     0x00        // }
#define CC_FSCAL0_VALUE     0x1F        // } Frequency synthesizer calibration: RF studio, nothing to do here

#define CC_TEST2_VALUE      0x88        // Various test settings: RF studio
#define CC_TEST1_VALUE      0x31        // Various test settings: RF studio
#define CC_TEST0_VALUE      0x09        // Various test settings: RF studio

// Rare use settings
#define CC_SYNC1_VALUE      0xD3
#define CC_SYNC0_VALUE      0x91

#define CC_CHANNR_VALUE     0x00        // Channel number.

#endif

#ifdef _CC_RF_SETTINGS_H2
// ============================ Common use values ==============================
#define CC_TX_FIFO_SIZE     33
#define CC_RX_FIFO_SIZE     32

// ===================== Frequency 868 MHz: RF Studio ==========================
#define CC_FREQ2_VALUE      0x20        // Frequency control word, high byte.
#define CC_FREQ1_VALUE      0x25        // Frequency control word, middle byte.
#define CC_FREQ0_VALUE      0xED        // Frequency control word, low byte.

// =================================== Common ==================================
//#define CC_MCSM0_VALUE      0x18        // Calibrate at IDLE->RX,TX

// Clear channel signal
#define CC_CCA_MODE         0b00000000  // Always clear
//#define CC_CCA_MODE         0b00100000  // Unless currently receiving a packet
#define CC_RXOFF_MODE       0b00000000  // RX->IDLE
//#define CC_RXOFF_MODE       0b00001100  // RX->RX
#define CC_TXOFF_MODE       0b00000000  // TX->IDLE

#define CC_MCSM2_VALUE      0b00000111  // WOR settings, nothing interesting here
#define CC_MCSM1_VALUE      (CC_CCA_MODE | CC_RXOFF_MODE | CC_TXOFF_MODE)
#define CC_MCSM0_VALUE      0x08        // Never calibrate

#define CC_FIFOTHR_VALUE    0b00000111  // RX attenuation = 0; RXFIFO and TXFIFO thresholds: TX 33, RX 32
#define CC_IOCFG2_VALUE     0x07        // GDO2 - Asserts when a packet has been received with CRC OK. De-asserts when the first byte is read from the RX FIFO.
#define CC_IOCFG0_VALUE     0x06        // GDO0 - Asserts when sync word has been sent / received, and de-asserts at the end of the packet.
                                        // In RX, the pin will also deassert when a packet is discarded due to address or maximum length filtering

//#define CC_PKTCTRL1_VALUE   0b00001110  // PQT=0, CRC autoflush=1, Append=1, Address check = 10 (check, 0 is broadcast)
#define CC_PKTCTRL1_VALUE   0b00001100  // PQT=0, CRC autoflush=1, Append=1, Address check = 00 (no check)
#define CC_PKTCTRL0_VALUE   0b00010010//0b01000100  // WhiteData=1, PKTFormat=normal, CRC enabled, Fixed Length
//#define CC_PKTCTRL0_VALUE   0b00000100  // WhiteData=0, PKTFormat=normal, CRC enabled, Fixed Length
//#define CC_PKTCTRL0_VALUE   0b00000000  // WhiteData=0, PKTFormat=normal, CRC disabled, Fixed Length
#define CC_ADDR_VALUE       0x01        // Device address.

// ========================= Bitrate-specific ==================================
#define CC_FSCTRL1_VALUE    0x0C        // }
#define CC_FSCTRL0_VALUE    0x00        // } Frequency synthesizer control: RF studio, nothing to do here

#define CC_MDMCFG4_VALUE    0x2D        // }
#define CC_MDMCFG3_VALUE    0x2F        // } Modem configuration: RF Studio, nothing to do here
#define CC_MDMCFG2_VALUE    0x00//0x13        // Filter, modulation format, no Manchester coding, SYNC_MODE=011 => 30/32 sync word bits
//#define CC_MDMCFG2_VALUE    0x11        // Filter, modulation format, no Manchester coding, SYNC_MODE=001 => 15/16 sync word bits
//#define CC_MDMCFG2_VALUE    0x14        // Filter, modulation format, no Manchester coding, SYNC_MODE=100
#define CC_MDMCFG1_CHANSPC_E    0x02    // Exponent of Channel Spacing
//#define CC_MDMCFG1_VALUE    (0b10100000 | CC_MDMCFG1_CHANSPC_E)  // FEC=1, Preamble length=010 => 4bytes
#define CC_MDMCFG1_VALUE    (0b00100000 | CC_MDMCFG1_CHANSPC_E)  // FEC=0, Preamble length=010 => 4bytes
//#define CC_MDMCFG1_VALUE    (0b10000000 | CC_MDMCFG1_CHANSPC_E)  // FEC=1, Preamble length=000 => 2bytes
//#define CC_MDMCFG1_VALUE    (0b11000000 | CC_MDMCFG1_CHANSPC_E)  // FEC=1, Preamble length=100 => 8bytes
#define CC_MDMCFG0_VALUE    0xE5        // Channel spacing mantissa. See exponent at MDMCFG1. RF studio.

#define CC_DEVIATN_VALUE    0x62        // Modem deviation setting - RF studio, nothing to do here
#define CC_FREND1_VALUE     0xB6        // Front end RX configuration - RF studio, no docs, nothing to do
#define CC_FREND0_VALUE     0x10        // Front end TX configuration - RF studio, no docs, nothing to do

#define CC_FOCCFG_VALUE     0x1D        // Frequency Offset Compensation - RF studio, some unknown reasons for settings
#define CC_BSCFG_VALUE      0x1C        // Bit synchronization Configuration - RF studio, some unknown reasons for settings
#define CC_AGCCTRL2_VALUE   0xC7        // AGC control: 00 - all gain settings, 000 - max possible gain, 111 - target ampl=42dB
#define CC_AGCCTRL1_VALUE   0x00        // Generally, nothing interesting
#define CC_AGCCTRL0_VALUE   0xB0        // AGC filter settings: RF studio, some unknown reasons for settings

#define CC_FSCAL3_VALUE     0xEA        // }
#define CC_FSCAL2_VALUE     0x2A        // }
#define CC_FSCAL1_VALUE     0x00        // }
#define CC_FSCAL0_VALUE     0x1F        // } Frequency synthesizer calibration: RF studio, nothing to do here

#define CC_TEST2_VALUE      0x88        // Various test settings: RF studio
#define CC_TEST1_VALUE      0x31        // Various test settings: RF studio
#define CC_TEST0_VALUE      0x09        // Various test settings: RF studio

// Rare use settings
#define CC_SYNC1_VALUE      0xD3
#define CC_SYNC0_VALUE      0x91

#define CC_CHANNR_VALUE     0x00        // Channel number.

#endif
