#!/usr/bin/python
from serialLCD import *

lcdReset()
sleep(2.1)
lcdClear()
lcdCursorNoBlink()
while True:
	lcdPrintRAM()
	sleep(2)
	lcdClear()
