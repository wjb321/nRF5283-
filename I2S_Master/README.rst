.. _i2s_litex_example:

#####################
I2S example
#####################

Overview
********

This is a simple code that takes an "xx.wav" music file, converts it to "xx.h", and then performs audio playback and testing.

Audio Format
************

The driver requires and provides Audio data with the following parameters:

* 8 kHz sample rate
* Signed 16 bit PCM
* Stereo
* Little endian

nRF to MAX98357A
********
        nRF           ------ MAX98357A   

#define PIN_MCK    (13) ------ Clock for SCK and LRCK  

#define PIN_SCK    (14) ------ BCLK  

#define PIN_LRCK   (15) ------ LRC  

#define PIN_SDOUT  (16) ------ DIN  


Tools
********
1. `wavetocode <https://colinjs.com/software.htm>`__
2. `audacity <https://www.audacityteam.org/>`__
3. `nRF command line tools <https://www.nordicsemi.com/Products/Development-tools/nRF-Command-Line-Tools>`__
4. `nRF connect for desktop <https://www.nordicsemi.com/Products/Development-tools/nrf-connect-for-desktop>`__

Reference videos/pdfs
************
1. `Get started <https://infocenter.nordicsemi.com/pdf/getting_started_NCS_nRF52_20210211.pdf>`__  
2. `nRF Connect for VS Code <https://www.nordicsemi.com/Products/Development-tools/nRF-Connect-for-VS-Code/Tutorials>`__  
3. `Index to nrf52832 <https://infocenter.nordicsemi.com/index.jsp>`__  

Building(nRF Connect)
********
1. Create a new application in WELCOME  
2. FreeStanding/Workspace  
3. build after creating APPLICATION  
4. flash in ACTION  
