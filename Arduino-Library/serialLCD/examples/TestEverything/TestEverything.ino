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
	
Description: Presentation of every feature of serialLCD library & LCDmodule.
*/
#include <serialLCD.h>
// DONT INCLUDE SoftwareSerial.h ITS INTERNALLY INCLUDED
// Including SoftwareSerial.h will give error.

serialLCD lcd;			//define lcd as serialLCD object

void setup()
{
	lcd.begin(9600);		// baudrate=9600
	delay(10);			// some delay for slower LCDs.
	lcd.reset();			// reset LCD board.
	delay(2100);			// wait for LCD controller to initialize.
	lcd.clear();			// Clear LCD.
	lcd.setCursor(1,1);		// set cursor to 1st row & 1st coloumn.
	lcd.backLight(50);		// set backlight brightness to 50% (number must be between 1-100 as its in %)
}

void loop()
{
	int i,j;
	lcd.println("Tired of using");	// print the text on lcd & goto next line
	lcd.print("Typical LCD?");
	delay(3000);
	lcd.clear();
	lcd.print("Introducing\n");		// \n acts as println
	lcd.print("Smart SerialLCD");
	delay(3000);
	lcd.clear();
	lcd.print("blinking test");		// blink display
	for(i=0;i<7;i++)
	{
		lcd.displayOff();
		delay(250);
		lcd.displayOn();
		delay(250);
	}
	lcd.clear();
	lcd.print("Scrolling Test");		// scroll display
	for(i=0;i<10;i++)
	{
		lcd.scrollRight();
		delay(450);
	}
	for(i=0;i<10;i++)
	{
		lcd.scrollLeft();
		delay(450);
	}
	delay(500);
	lcd.clear();
	lcd.print("Cursor Test  ");			// diffrent cursors
	for(i=0;i<2;i++)
	{
		delay(1000);
		lcd.cursorOn();
		lcd.cursorNoBlink();
		delay(1000);
		lcd.cursorOff();
		delay(1000);
		lcd.cursorOn();
		delay(1000);
		lcd.cursorBlink();
	}
	lcd.clear();
	lcd.println("Backlight Test");
	for(j=0;j<101;j=j+5)
	{
		lcd.backLight(j);
		lcd.setCursor(1,2);
		lcd.print("brightness: ");
		lcd.printNum(j);
		delay(300);
	}
	delay(500);
	lcd.backLight(50);
	lcd.clear();
	lcd.print("Auto line change for long text");
	delay(3000);
	lcd.clear();
	lcd.println("Have a nice day.");
	lcd.print("Enjoy Arduino..");
	delay(5000);
	lcd.clear();
}