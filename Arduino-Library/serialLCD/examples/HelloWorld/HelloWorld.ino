/*
The First basic hello world example.
NOTE:	The serialLCD library uses SoftwareSerial library internally
		So please DON'T INCLUDE SoftwareSerial.h in your sketch.
		But you CAN use SoftwareSerial to create other serial ports in sketch.
		So use it as you wish without including header file.
The LCD must be connected to following Arduino pins(uno/duemilanove)
	Arduino 6(tx) ---> LCD Rx
	Arduino 7(rx) ---> NO USE (can be left floating/un-connected)
	
Author:	Pranjal Joshi
Date:	7-12-2013
License:GNU GPL v2 (Relased in public domain as open-source).
	
Description:	The program will simply print text on LCD.
*/
#include <serialLCD.h>
// DONT INCLUDE SoftwareSerial.h ITS INTERNALLY INCLUDED
// Including SoftwareSerial.h will give error.

serialLCD lcd;			//define lcd as serialLCD object

void setup()
{
	lcd.begin(9600);		// baudrate=9600
	delay(10);				// some delay for slower LCDs.
	lcd.reset();			// reset LCD board.
	delay(2100);			// wait for LCD controller to initialize.
	lcd.clear();				// Clear LCD.
	lcd.setCursor(1,1);		// set cursor to 1st row & 1st coloumn.
	lcd.backLight(60);		// set backlight brightness to 60% (number must be between 1-100 as its in %)
	lcd.print("Hello World");	// print the text on lcd
}

void loop()
{
	// Do nothing...!
}