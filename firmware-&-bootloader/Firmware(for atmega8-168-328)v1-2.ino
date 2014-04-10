/*
  This is open-source hardware & software. Feel free to edit/improve/share/use it.
  Project : Serial LCD module(ATmega8 at 8Mhz internal osc. (no-xtal bootloader)).
  Author  : Pranjal Joshi
  Date    : 7-12-2013
  
  Hardware Overview:
  Serial port at 9600 baudrate.
  The following pin mapping is for arduino duemilanove/uno/standlone AVR chips.
  Arduino Mega/Due are NOT SUPPORTED this sketch.
  ------------------------------------------------
  arduino pins      LCD pins
  ------------------------------------------------
     9(PWM)         15(LED brightness control)
     10              D7
     11              D6
     12              D5
     13              D4
     A3              RS
     A2              R/W
     A1              E
  ----------------------------------------------

*/


#include <LiquidCrystal.h>
#include <avr/io.h>

LiquidCrystal lcd(A3,A1,13,12,11,10);
char c,cnt;

void (*reset)(void)=0;     // software reset atmega8

void debug()		// use if there is some bug in serial comm.
{
  Serial.print(c);
}

void setup()
{
  pinMode(A2, OUTPUT);
  digitalWrite(A2, LOW);    // R/W to ground
  analogWrite(9, 127);  //50% backlight
  delay(50);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  Serial.begin(9600);
  lcd.print("SerialLCD Module");
  lcd.setCursor(1,1);
  lcd.print("Baudrate:9600");
  delay(2000);
  lcd.clear();
  lcd.blink();
  cnt=0;
}

void loop()
{
  while(!Serial.available());
  c = Serial.read();
  if(c == '$')     // ASCII code of $. used $ as special Symbol
  {
    while(!Serial.available());
    c = (char)Serial.read();	//get next char
    switch(c)					//decode the input command
    {
	  case '$':
		lcd.print('$');
		break;
      case '0':
        reset();
        break;
      case '1':
        lcd.clear();
        break;
      case '2':
        lcd.display();
        break;
      case '3':
        lcd.noDisplay();
        break;
      case '4':
        lcd.cursor();
        break;
      case '5':
        lcd.noCursor();
        break;
      case '6':
        lcd.blink();
        break;
      case '7':
        lcd.noBlink();
        break;
      case '8':
        lcd.scrollDisplayLeft();
        break;
      case '9':
        lcd.scrollDisplayRight();
        break;
      case 's':				//set cursor position
      {
        char row,col;
        while(!Serial.available());
        col = Serial.read()-1;
        while(!Serial.available());
        row = Serial.read()-1;
        lcd.setCursor(row,col);
        break;     
    }
    case 'p':				//set backlight
    {
        char pwm;
        while(!Serial.available());
        pwm = Serial.read();
        pwm = map(pwm,0,100,0,255);
        analogWrite(9, pwm);
        break;
    }
    
    }
    cnt=0;
  }
  else
  {
    if(cnt<17)
    {
      if(c=='\n')			//if '\n' goto 2nd line
      {
        lcd.setCursor(0,1);
        cnt=0;
      }
      else
      {
        lcd.print(c);
        cnt++;
      }
    }
    if(cnt>=17)				// auto jump to 2nd line when 1st line ends
     { 
       lcd.setCursor(0,1);
       lcd.print(c);
       cnt = 0;
     }
  }
}
