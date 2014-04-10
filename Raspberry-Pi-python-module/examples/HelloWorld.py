#!/usr/bin/python
from serialLCD import *

lcdReset()
sleep(2.1)
lcdClear()
while True:
	lcdprintDelayed("Hello World\nFrom Rasp.Pi",150)
	sleep(2)
	lcdClear()
	sleep(1)
