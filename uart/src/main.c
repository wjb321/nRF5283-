#include <nrf.h>
#include "uart.h"

int main(void)
{
  uart_configuration();
  while (1)
  {
    __WFE();
  }
}
