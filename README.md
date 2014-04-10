
Project : Serial LCD module(ATmega8 at 8Mhz internal osc. (no-xtal bootloader)).
Author  : Pranjal Joshi
Date    : 7-12-2013
License : GNU GPL v2 (Relased in public domain as open-source).

This is open-source hardware & software. Feel free to edit/improve/share/use it.

----------------------------------------------------------------------------------------
Firmware File:

The Firmware file contains a sketch for slave/UART to LCD Controller ATmega8/168/328.

Hardware Overview:
 
 
Serial port at 9600 baudrate.
The following pin mapping is for arduino duemilanove/uno/standlone AVR chips.
Arduino Mega/Due are NOT SUPPORTED this sketch.
----------------------------------------------------------
	arduino pins      LCD pins
----------------------------------------------------------
	9(PWM)         15(LED brightness control)
	10              D7
	11              D6
	12              D5
	13              D4
	A3              RS
	A2              R/W
	A1              E
----------------------------------------------------------

----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------
serialLCD folder:

The serialLCD folder is arduino library. Copy this folder in arduino/libraries & restart arduino
IDE to use this library.
****************************************************************************************
NOTE:
	Please dont include SoftwareSerial.h file in sketch as this library internally include the
file but you can use SoftwareSerial as usual if you want.
****************************************************************************************

(The pin 6,7 on arduino are used by this library.)

Arduino 6(tx) ---> LCD Rx
Arduino 7(rx) ---> NO USE (can be left floating/un-connected)
-----------------------------------------------------------------------------------------