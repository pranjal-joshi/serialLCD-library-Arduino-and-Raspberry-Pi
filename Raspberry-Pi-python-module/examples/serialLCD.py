#!/usr/bin/python
from time import sleep, strftime	# import required modules
import serial
from datetime import datetime
import socket
import sys
from subprocess import *
from array import array

lcd = serial.Serial("/dev/ttyAMA0",baudrate=9600)	# open serial port
hostname = socket.gethostname()				# get my IP

def lcdReset():			# reset lcd (must require sleep of 2.1 sec
	lcd.write("$0")		# to initialize lcd)

def lcdClear():			# clear lcd
	lcd.write("$1")

def lcdDisplay():		# lcd display on
	lcd.write("$2")

def lcdNoDisplay():		# lcd display off
	lcd.write("$3")

def lcdCursorOn():		# lcd static cursor on
	lcd.write("$4")

def lcdCursorOff():		# lcd static cursor off
	lcd.write("$5")

def lcdCursorBlink():		# lcd blinking cursor on
	lcd.write("$6")

def lcdCursorNoBlink():		# lcd blinking cursor off
	lcd.write("$7")

def lcdScrollDisplayLeft(howmany, time):# shift display left by given number & delay in ms.
	for howmany in range(0,howmany):
		lcd.write("$8")
		sleep(time/1000.0)

def lcdScrollDisplayRight(howmany, time):# shift display left by given number & delay in ms.
	for howmany in range(0,howmany):
		lcd.write("$9")
		sleep(time/1000.0)


def lcdSetCursor(col,row):	# set cursor to given coloumn & row
	lcd.write("$s")
	COL = array('B',[col]).tostring()
	lcd.write(COL)
	ROW = array('B',[row]).tostring()
	lcd.write(ROW)

def lcdBacklight(pwm):		# set backlight brigtness between 1-100%
	if(pwm>100 or pwm<0):
		sys.exit("ERROR: pwm must between 0-100 as it is % of backlight brightness")
	lcd.write("$p")
	PWM = array('B',[pwm]).tostring()
	lcd.write(PWM)

def lcdprint(str):		# print given string
	lcd.write(str)

def lcdprintln(str):		# print given string n goto 2nd row
	lcd.write(str)
	lcd.write('\n')

def lcdprintNum(num):		# print integer variable on lcd
	lcd.write(str(num))

def lcdprintDelayed(str, delay):# print string (one by one char. after given time)
	delay = delay/1000.0
	i = 0
	for i in range(0,len(str)):
		lcd.write(str[i])
		sleep(delay)

def lcdPrintIP():		# print IP addr on LCD
	p = Popen("ip addr show eth0 | grep inet | awk '{print $2}' | cut -d/ -f1", shell=True, stdout=PIPE)
	output = p.communicate()[0]
	lcd.write(output)

def lcdPrintHostname():		# print Hostname on LCD
	lcd.write(hostname)

def lcdPrintTime():		# print current time
	lcd.write(datetime.now().strftime('%r'))

def lcdPrintDate():		# print current date
	lcd.write(datetime.now().strftime('%a %d %b %Y'))

def lcdPrintRAM():		# print used & free RAM
	lcdClear()
	p = Popen("free -m | grep Mem: | awk '{print $3}'", shell=True, stdout=PIPE)
        output = p.communicate()[0]
	lcd.write("Used: " + output)
	p = Popen("free -m | grep Mem: | awk '{print $4}'", shell=True, stdout=PIPE)
        output = p.communicate()[0]
        lcd.write("Free: " + output)

