.. _Toggle_Led:

UARTE
################

.. contents::
   :local:
   :depth: 2

The main objective is to try on uartE(uart with easyDMA), configure the analysis pins as output ports, and understand the relevant electrical characteristics

Some configurations
************
| configure tx 6
| configure rx 8

Regarding driving issues
************
1. there are legacy uart and uarte
2. support blocking and non-blocking
3. support onging aborting rx and tx tansfers
4. double rx buffering
5. with and without hardware flow control
6. peripherals using EasyDMA can work only with buffers that are placed in the data RAM region, sometimes ,compliers might choose 
   to use a different region for data placement, for instance, place a constant buffer in the code flash, then the UARTE peripherals can 
   not be used to transfer data from the buffer.

The sample supports the dev board:
************
nrf52_nrf52832

Testing
=======

.. code-block:: console

    welcome to infrafon!
