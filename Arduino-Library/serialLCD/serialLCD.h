/*
	serialLCD using ATmega8 (arduino compatible)
	Type:	Header File
	Author: Pranjal Joshi
	Date:	7-12-2013
	License:GNU GPL v2 (Relased in public domain as open-source).
*/
#ifndef serialLCD_H
#define serialLCD_H

#include "Arduino.h"
#include "SoftwareSerial.h"

class serialLCD
{
	public:
		serialLCD(void);
		void begin(long baud);
		void reset();
		void clear();
		void displayOn();
		void displayOff();
		void cursorOn();
		void cursorOff();
		void cursorBlink();
		void cursorNoBlink();
		void scrollLeft();
		void scrollRight();
		void setCursor(uint8_t row, uint8_t col);
		void backLight(uint8_t pwm);
		void print(char *str);
		void println(char *str);
		void printNum(unsigned long num);
};

#endif