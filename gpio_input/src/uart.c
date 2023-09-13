#include "uart.h"
#include <nrf.h>
#include "stdio.h"

#define PIN_TXD        (6)
#define PIN_RXD        (8)

void uart_configuration()
{
  uint8_t uart_array[] = "welcome infrafon!\n";
    // Configure the UARTE(easy DMA) with no flow control, one parity bit and 115200 baud rate
    // Hardware flow control is employed to ensure reliable data transmission, particularly in cases of high-speed communication and sensitivity to data loss.
  NRF_UARTE0->CONFIG = (UART_CONFIG_HWFC_Disabled   << UART_CONFIG_HWFC_Pos) |
                       (UART_CONFIG_PARITY_Included << UART_CONFIG_PARITY_Pos); 
  
  NRF_UARTE0->BAUDRATE = UARTE_BAUDRATE_BAUDRATE_Baud115200 << UARTE_BAUDRATE_BAUDRATE_Pos;
  
  // Select TX and RX pins
  NRF_UARTE0->PSEL.TXD = PIN_TXD;
  NRF_UARTE0->PSEL.RXD = PIN_RXD;
  
  // Enable the UART (starts using the TX/RX pins)
  NRF_UARTE0->ENABLE = UARTE_ENABLE_ENABLE_Enabled << UARTE_ENABLE_ENABLE_Pos;
  
  // Configure transmit buffer and start the transfer
  NRF_UARTE0->TXD.MAXCNT = sizeof(uart_array);
  NRF_UARTE0->TXD.PTR = (uint32_t)&uart_array[0];
  NRF_UARTE0->TASKS_STARTTX = 1;
  
  // Wait until the transfer is complete
  while (NRF_UARTE0->EVENTS_ENDTX == 0)
  {
  }
  
  // Stop the UART TX
  NRF_UARTE0->TASKS_STOPTX = 1;
  // Wait until we receive the stopped event
  while (NRF_UARTE0->EVENTS_TXSTOPPED == 0);
  
  // Disable the UARTE (pins are now available for other use)
  NRF_UARTE0->ENABLE = UARTE_ENABLE_ENABLE_Disabled << UARTE_ENABLE_ENABLE_Pos;
}