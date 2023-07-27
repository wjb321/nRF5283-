.. _Toggle_Led:

Toggle LED
################

.. contents::
   :local:
   :depth: 2

The main objective is to drive LED toggle, configure the analysis pins as output ports, and understand the relevant electrical characteristics

Some configurations
************
a. Pin sensing mechanism: high, low, dis, mask
b. Pull configuration: 
c. Connect or disconnect input buffer
d. Drive configuration: s0/h0/d0|s1/h1/d1

Regarding driving issues
************
The different options specify how a configured GPIO pin sinks current when you set it low (write 0 to the pin) and how a configured pin sources current when you set it high (write 1 to the pin).

| Standard means the pin will be sourced or sinked with up to 0.5 mA for the assigned signal (high or low)
| High source means the pin will be sourced with up to 5.0 mA for high signal
| High sink means the pin will be sinked with up to 15.0 mA for low signal
| Disconnected means there is no drive, the pin is high impedance. Consequently, there is no current flowing to or from the pin, no matter the drive of any external circuit connected to the pin.

The sample supports the dev board:
************
nrf52_nrf52832

Testing
=======

.. code-block:: console

    LED1 is toggling 
