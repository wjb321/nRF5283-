#include <nrf.h>
#include "gpio.h"


int main(void)
{
  gpio_config();
  LED_config();

  // Read the input value, and use it to set the output of the LED.
  // If the button is pressed, the LED turns on, otherwise it is off.
  while (1)
  {
    uint32_t volatile input;

	// Get the value set in the 13th bit and shift it to get 1 or 0
    input = (NRF_GPIO->IN >> BUTTON_GPIO) & 1UL;
	if(input)
		NRF_GPIO->OUTSET = (1UL << LED_GPIO);
    else
		NRF_GPIO->OUTCLR = (1UL << LED_GPIO);
  }
}