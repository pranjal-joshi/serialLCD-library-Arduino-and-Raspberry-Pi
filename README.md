Project : Serial LCD module(ATmega8 at 8Mhz internal osc. (no-xtal bootloader)).

Author  : Pranjal Joshi

Date    : 7-12-2013

License : GNU GPL v2 (Relased in public domain as open-source).

This is open-source hardware & software. Feel free to edit/improve/share/use it.

Instruction to build serialLCD:
-------------------------

------------------------------------------------------------------------
atmega8_noxtal:

This is a bootloader for ATmega8 to run @ 8Mhz internal osc. (This bootloader is not written by me.)

copy this folder into arduino/hardware/arduino/bootloader
restart arduino IDE.

---*** FOR ATmega8 in serialLCD module ***---

---*** Only For 1st time:

1. burn arduinoISP sketch (given in File->Example->ArduinoISP) into your arduino.
2. connect atmega8 to arduino through SPI. google it if you are burning bootloader for 1st time.
3. Now in arduino IDE->tools->Board & select atmega8-noxtal.
4. Now burn bootloader, Tools->Burn bootloader. If your connections are ok then bootloader will be loaded without any error.
5. opne Firmware-8/168/328.ino file in arduino IDE, select board as atmega8-noxal.
6. Goto file->Upload using programmer (I assumed that your arduino contains arduinoISP sketch..)
7. Congrats..! Firmware file is loaded into your ATmega8.
(If you wish to use atmega168/328, you must choose proper bootloader & Board before uploading. Sketch is compatible with all these microcontrollers.)

Firmware File:

The Firmware file contains a sketch for slave/UART to LCD Controller ATmega8/168/328. (Burn this sketch to ATmega8 in serialLCD module.)

---- No Need to burn Firmware & bootloader every time. It requires only for 1st time ----
----------------------------------------------------------------------------------------

Hardware Overview:
 
Serial port at 9600 baudrate.
The following pin mapping is for arduino duemilanove/uno/standlone AVR chips. (Please see pin mapping given image.)
Arduino Mega/Due are NOT SUPPORTED this sketch.

----------------------------------------------------------
	arduino(in serialLCD module)pins      LCD pins
----------------------------------------------------------
						9(PWM)          15(LED brightness control)
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

FOR ARDUINO:
-------------

serialLCD folder:

The serialLCD folder is arduino library. Copy this folder in arduino/libraries & restart arduino
IDE to use this library.
****************************************************************************************
NOTE:
	Please dont include SoftwareSerial.h file in sketch as this library internally include the
file but you can use SoftwareSerial as usual if you want.
****************************************************************************************

(The pin 6,7 on arduino are used by this library.)

Arduino 6(tx) ---> LCD Rx (2nd pin of microcontroller IC in serialLCD module or DigitalPin 1 according to arduino map)
-----------------------------------------------------------------------------------------
Arduino 7(rx) ---> NO USE (can be left floating/un-connected)
-----------------------------------------------------------------------------------------

Instructions for Raspberry Pi:
------------------------------

Raspberry Pi Python Module for serialLCD using ATmega8 (arduino compatible)
Type:	Module/python File
Author: Pranjal Joshi
Date:	13-12-2013
License:GNU GPL v2 (Relased in public domain as open-source).

----------------------------- NOTE -----------------------------------

1. Please make sure that serialLCD.py file is in the same folder/directory where you are creating your python source file.
2. serialLCD.pyc file will be generated automatically.
3. Possible Reasons of error are:
	a. You didn't installed requied python libraries.
	b. the serialLCD.py file is not in same directory of source file.
4. This project is still under development. So to report any bug please contact me at joshi.pranjal5@gmail.com

----------------------------------------------------------------------