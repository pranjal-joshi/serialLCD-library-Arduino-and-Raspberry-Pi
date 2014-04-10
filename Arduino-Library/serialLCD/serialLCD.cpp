/*
	serialLCD using ATmega8 (arduino compatible)
	Type:	Source File
	Author: Pranjal Joshi
	Date:	7-12-2013
	License:GNU GPL v2 (Relased in public domain as open-source).
*/
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "serialLCD.h"

SoftwareSerial port(7,6);

serialLCD::serialLCD(void)
{
}

void serialLCD::begin(long baud)
{
	port.begin(baud);
}

void serialLCD::reset(void)
{
	port.print("$0");
}

void serialLCD::clear(void)
{
	port.print("$1");
}

void serialLCD::displayOn(void)
{
	port.print("$2");
}

void serialLCD::displayOff(void)
{
	port.print("$3");
}

void serialLCD::cursorOn(void)
{
	port.print("$4");
}

void serialLCD::cursorOff(void)
{
	port.print("$5");
}

void serialLCD::cursorBlink(void)
{
	port.print("$6");
}

void serialLCD::cursorNoBlink(void)
{
	port.print("$7");
}

void serialLCD::scrollLeft(void)
{
	port.print("$8");
}

void serialLCD::scrollRight(void)
{
	port.print("$9");
}

void serialLCD::setCursor(uint8_t row, uint8_t col)
{
	port.print("$s");
	delay(1);
	port.write(col);
	delay(1);
	port.write(row);
}

void serialLCD::backLight(uint8_t pwm)
{
	port.print("$p");
	port.write(pwm);
}

void serialLCD::print(char *str)
{
	port.print(str);
	port.flush();
}

void serialLCD::println(char *str)
{
	port.print(str);
	port.flush();
	port.print('\n');
	port.flush();
}

void serialLCD::printNum(unsigned long num)
{
	port.print(num);
	port.flush();
}
