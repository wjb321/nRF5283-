/* FILE *pcmfile
int16_t *pcmdata;
pcmfile = fopen(your pcm data file);
pcmdata = malloc(size of the file);
fread(pcmdata, sizeof(int16_t), sizeof file / sizeof(int16_t), pcmfile); */
#include <stdint.h>
#include <nrf.h>//C:/ncs/v2.3.0/modules/hal/nordic/nrfx/mdk/nrf.h
#include "configure.h"
int main(void)
{
  I2Sconfiguration();
  while (1)
  {
   __WFE();
  }
}
