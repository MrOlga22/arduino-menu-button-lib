/*
  Menu.h - Library for easy to generate menu buttons.
  Created by Jan Ole Gödeke, 2018.
*/

#ifndef Menu_h
#define Menu_h

#include "Arduino.h"
#include <Adafruit_TFTLCD.h>

#define rotation 2 //1-4

#define displaywidth 240
#define displayheight 320

#define textSize 3 //see Adafruit_TFTLCD doc
#define textdistotop 12 //distance from text to top button border

// The control pins for the LCD can be assigned to any digital or
// analog pins...but we'll use the analog pins as this allows us to
// double up the pins with the touch screen (see the TFT paint example).
#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0

#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin


class Menu {
  private:
	int _width = displaywidth;
	int _height = displayheight;
	int _buttonheight = _height / 4 - 10; 
	int _buttonwidth =  _width - 16;
	int _border = 8;
	int _textColor;
	int _buttonColor;
	int _backgroundColor;
	int _xB2 = 2 * _border + _buttonheight;
	int _xB3 = 3 * _border + 2 * _buttonheight;
	int _xB4 = 4 * _border + 3 * _buttonheight;
	static uint16_t bitcolor(char*);
  public:
	Menu();
	setTextColor(char* color);
	setButtonColor(char* color);
	setBackgroundColor(char* color);
	setColors(char* text, char* button, char* bg);
	uint16_t getTextColor();
	uint16_t getButtonColor();
	uint16_t getBackgroundColor();
	int getButtonHeight();
	int getButtonWidth();
	int getBorder();
	oneButton(char* b1, int sel);
	twoButtons(char* b1, char*b2, int sel);
	threeButtons(char* b1, char*b2, char* b3, int sel);
	fourButtons(char* b1, char*b2, char* b3, char* b4, int sel);
};

#endif
