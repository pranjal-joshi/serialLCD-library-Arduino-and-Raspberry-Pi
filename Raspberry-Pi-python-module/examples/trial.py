#!/usr/bin/python
from serialLCD import *

lcdReset()
sleep(2.1)
while True:
	lcdClear()
	lcdCursorNoBlink()
	lcdprint("Raspberry Pi\nWorking...!")
	sleep(2)
	lcdClear()
	lcdprintDelayed("Typewritter",350)
	sleep(2)
	lcdClear()
	lcdPrintIP()
	lcdprint("\n")
	lcdPrintDate()
	sleep(2)
