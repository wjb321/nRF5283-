.. _GPIO_input: ..

gpio input for led on off
###########

Overview
********

A simple sample that can be used with any :ref:`supported board <boards>` and
when pressing the button 1(nrf52), the led1 will be on.

Building and Running
********************

This application can be built and executed on QEMU as follows:

.. zephyr-app-commands::
   :zephyr-app: samples/gpio_input
   :host-os: linux
   :board: nrf5283
   :goals: run
   :compact:

To build for another board, change "qemu_x86" above to that board's name.

Sample Output
=============

.. code-block:: console

   press on/unpress off

Exit QEMU by pressing :kbd:`CTRL+A` :kbd:`x`.
