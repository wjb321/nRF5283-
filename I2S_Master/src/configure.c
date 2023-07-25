

#include "configure.h"
//#include "meinv8k.h"
#include <nrf.h>
#include "textMessage8k.h"
//#include "2k_16bit.h"
//#include "2k_8bit.h"
//#include "ISO-2.h"
//#include "beauty.h"
//#include "audio_laugh2048s8.h" // PCM (uncompressed) 24 bit mixed with 8bit :some noise, and fast sane like 16KHz sample rate in audiocity

#define PIN_MCK    (13)
#define PIN_SCK    (14)
#define PIN_LRCK   (15)
#define PIN_SDOUT  (16)


void I2Sconfiguration()
  {
  // Enable transmission
  NRF_I2S->CONFIG.TXEN = (I2S_CONFIG_TXEN_TXEN_ENABLE << I2S_CONFIG_TXEN_TXEN_Pos);
  
  // Enable MCK generator
  NRF_I2S->CONFIG.MCKEN = (I2S_CONFIG_MCKEN_MCKEN_ENABLE << I2S_CONFIG_MCKEN_MCKEN_Pos);
  
  // MCKFREQ = 4 MHz
  NRF_I2S->CONFIG.MCKFREQ = I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV32  << I2S_CONFIG_MCKFREQ_MCKFREQ_Pos;
  
  // Ratio = 64 
  NRF_I2S->CONFIG.RATIO = I2S_CONFIG_RATIO_RATIO_128X << I2S_CONFIG_RATIO_RATIO_Pos;
    
  // Master mode, 16Bit, left aligned
  NRF_I2S->CONFIG.MODE = I2S_CONFIG_MODE_MODE_MASTER << I2S_CONFIG_MODE_MODE_Pos;
  NRF_I2S->CONFIG.SWIDTH = I2S_CONFIG_SWIDTH_SWIDTH_16BIT << I2S_CONFIG_SWIDTH_SWIDTH_Pos; //high how 
  NRF_I2S->CONFIG.ALIGN = I2S_CONFIG_ALIGN_ALIGN_RIGHT << I2S_CONFIG_ALIGN_ALIGN_Pos;
  
  // Format = I2S
  NRF_I2S->CONFIG.FORMAT = I2S_CONFIG_FORMAT_FORMAT_I2S << I2S_CONFIG_FORMAT_FORMAT_Pos;
  
  // Use stereo 
  NRF_I2S->CONFIG.CHANNELS = I2S_CONFIG_CHANNELS_CHANNELS_RIGHT << I2S_CONFIG_CHANNELS_CHANNELS_Pos;
  
  // Configure pins
  NRF_I2S->PSEL.MCK =   (PIN_MCK << I2S_PSEL_MCK_PIN_Pos);
  NRF_I2S->PSEL.SCK =   (PIN_SCK << I2S_PSEL_SCK_PIN_Pos); 
  NRF_I2S->PSEL.LRCK =  (PIN_LRCK << I2S_PSEL_LRCK_PIN_Pos); 
  NRF_I2S->PSEL.SDOUT = (PIN_SDOUT << I2S_PSEL_SDOUT_PIN_Pos);
  
  NRF_I2S->ENABLE = 1;
  
  // Configure data pointer
  NRF_I2S->TXD.PTR = (uint32_t)(&data[0]);
  NRF_I2S->RXTXD.MAXCNT = (uint32_t) (sizeof(data) /sizeof(uint32_t));
  
  // Start transmitting I2S data
  NRF_I2S->TASKS_START = 1;
  }