#!/usr/bin/python
from serialLCD import *

lcdReset()
sleep(2.1)
lcdClear()
while True:
	lcdSetCursor(1,1)
	lcdprint("IP: ")
	lcdPrintIP()
	lcdSetCursor(2,1)
	lcdPrintTime()
	sleep(1)
