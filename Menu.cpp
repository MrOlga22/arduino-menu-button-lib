/*
  Menu.cpp - Library for easy to generate menu buttons.
  Created by Jan Ole Gödeke, 2018.
*/
#include "Arduino.h"
#include "Menu.h"

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

//constructor
Menu::Menu() {
	//initialize instance of Adafruit_TFTLCS class called tft
	tft.reset();
	uint16_t identifier = tft.readID(); //read lcd chip
	tft.begin(identifier);
	tft.setRotation(rotation);
}

Menu::setTextColor(char* color) {
	_textColor = bitcolor(color);
}

Menu::setButtonColor(char* color) {
	_buttonColor = bitcolor(color);
}

Menu::setBackgroundColor(char* color) {
	_backgroundColor = bitcolor(color);
}

Menu::setColors(char* text, char* button, char* bg) {
	_textColor = bitcolor(text);
	_buttonColor = bitcolor(button);
	_backgroundColor = bitcolor(bg);
}

uint16_t Menu::getTextColor() { return _textColor; }
uint16_t Menu::getButtonColor() { return _buttonColor; }
uint16_t Menu::getBackgroundColor() { return _backgroundColor; }

int Menu::getButtonHeight() { return _buttonheight; }
int Menu::getButtonWidth() { return _buttonwidth; }
int Menu::getBorder() { return _border; }

//convert char to 16bit color code
uint16_t Menu::bitcolor(char* color) {
	uint16_t BLACK	 = 0x0000;
	uint16_t BLUE	   = 0x001F;
	uint16_t RED	   = 0xF800;
	uint16_t GREEN	 = 0x07E0;
	uint16_t CYAN	   = 0x07FF;
	uint16_t MAGENTA = 0xF81F;
	uint16_t YELLOW	 = 0xFFE0;
	uint16_t WHITE	 = 0xFFFF;
	if (color == "BLACK") {
		return BLACK;
	} else if (color == "BLUE") {
		return BLUE;
	} else if (color == "RED") {
		return RED;
	} else if (color == "GREEN") {
		return GREEN;
	} else if (color == "CYAN") {
		return CYAN;
	} else if (color == "MAGENTA") {
		return MAGENTA;
	} else if (color == "YELLOW") {
		return YELLOW;
	} else if (color == "WHITE") {
		return WHITE;
	}
}

//generate one button with given text, selected (1/0) and saved colors
Menu::oneButton(char* b1, int sel) {
	uint16_t bC;
	uint16_t tC;
	if (sel == 0) {
		bC = _buttonColor;
		tC = _textColor;
	} else {
		bC = _textColor;
		tC = _buttonColor;
	}
	tft.fillRect(0, 0, _width, _height, _backgroundColor);
	tft.fillRect(_border, _border,_buttonwidth, _buttonheight, bC);
	tft.setTextColor( tC);
	tft.setCursor(_border + textdistotop, _border + textdistotop);
	tft.setTextSize(textSize);
	tft.println(b1);
}
//generate two buttons with given text, selected (2/1/0) and saved colors
Menu::twoButtons(char* b1, char*b2, int sel) {
	tft.fillRect(0, 0, _width, _height, _backgroundColor);
	tft.fillRect(_border, _border, _buttonwidth, _buttonheight, _buttonColor);
	tft.setCursor(_border + textdistotop, _border + textdistotop);
	tft.setTextColor(_textColor);
	tft.setTextSize(textSize);
	tft.println(b1);
	tft.fillRect(_border, _xB2, _buttonwidth, _buttonheight, _buttonColor);
	tft.setCursor(_border + textdistotop, _xB2 + textdistotop);
	tft.setTextColor(_textColor);
	tft.setTextSize(textSize);
	tft.println(b2);
	if (sel == 1) {
		tft.fillRect(_border, _border, _buttonwidth, _buttonheight, _textColor);
		tft.setCursor(_border + textdistotop, _border + textdistotop);
		tft.setTextColor(_buttonColor);
		tft.setTextSize(textSize);
		tft.println(b1);
	} else if (sel == 2) {
		tft.fillRect(_border, _xB2,_buttonwidth, _buttonheight, _textColor);
		tft.setCursor(_border + textdistotop, _xB2 + textdistotop);
		tft.setTextColor(_buttonColor);
		tft.setTextSize(textSize);
		tft.println(b2);
	}
}
//generate three buttons with given text, selected (3/2/1/0) and saved colors
Menu::threeButtons(char* b1, char*b2, char* b3, int sel) {
	tft.fillRect(0, 0, _width, _height, _backgroundColor);
	tft.fillRect(_border, _border, _buttonwidth, _buttonheight, _buttonColor);
	tft.setCursor(_border + textdistotop, _border + textdistotop);
	tft.setTextColor(_textColor);
	tft.setTextSize(textSize);
	tft.println(b1);
	tft.fillRect(_border, _xB2, _buttonwidth, _buttonheight, _buttonColor);
	tft.setCursor(_border + textdistotop, _xB2 + textdistotop);
	tft.setTextColor(_textColor);
	tft.setTextSize(textSize);
	tft.println(b2);
	tft.fillRect(_border, _xB3, _buttonwidth, _buttonheight, _buttonColor);
	tft.setCursor(_border + textdistotop, _xB3 + textdistotop);
	tft.setTextColor(_textColor);
	tft.setTextSize(textSize);
	tft.println(b3);
	if (sel == 1) {
		tft.fillRect(_border, _border, _buttonwidth, _buttonheight, _textColor);
		tft.setCursor(_border + textdistotop, _border + textdistotop);
		tft.setTextColor(_buttonColor);
		tft.setTextSize(textSize);
		tft.println(b1);
	} else if (sel == 2) {
		tft.fillRect(_border, _xB2, _buttonwidth, _buttonheight, _textColor);
		tft.setCursor(_border + textdistotop, _xB2 + textdistotop);
		tft.setTextColor(_buttonColor);
		tft.setTextSize(textSize);
		tft.println(b2);
	} else if (sel == 3) {
		tft.fillRect(_border, _xB3,_buttonwidth, _buttonheight, _textColor);
		tft.setCursor(_border + textdistotop, _xB3 + textdistotop);
		tft.setTextColor(_buttonColor);
		tft.setTextSize(textSize);
		tft.println(b3);
	}
}
//generate four buttons with given text, selected (4/3/2/1/0) and saved colors
Menu::fourButtons(char* b1, char*b2, char* b3, char* b4, int sel) {
	tft.fillRect(0, 0, _width, _height, _backgroundColor);
	tft.fillRect(_border, _border, _buttonwidth, _buttonheight, _buttonColor);
	tft.setCursor(_border + textdistotop, _border + textdistotop);
	tft.setTextColor(_textColor);
	tft.setTextSize(textSize);
	tft.println(b1);
	tft.fillRect(_border, _xB2, _buttonwidth, _buttonheight, _buttonColor);
	tft.setCursor(_border + textdistotop, _xB2 + textdistotop);
	tft.setTextColor(_textColor);
	tft.setTextSize(textSize);
	tft.println(b2);
	tft.fillRect(_border, _xB3, _buttonwidth, _buttonheight, _buttonColor);
	tft.setCursor(_border + textdistotop, _xB3 + textdistotop);
	tft.setTextColor(_textColor);
	tft.setTextSize(textSize);
	tft.println(b3);
	tft.fillRect(_border, _xB4, _buttonwidth, _buttonheight, _buttonColor);
	tft.setCursor(_border + textdistotop, _xB4 + textdistotop);
	tft.setTextColor(_textColor);
	tft.setTextSize(textSize);
	tft.println(b4);
	if (sel == 1) {
		tft.fillRect(_border, _border, _buttonwidth, _buttonheight, _textColor);
		tft.setCursor(_border + textdistotop, _border + textdistotop);
		tft.setTextColor(_buttonColor);
		tft.setTextSize(textSize);
		tft.println(b1);
	} else if (sel == 2) {
		tft.fillRect(_border, _xB2, _buttonwidth, _buttonheight, _textColor);
		tft.setCursor(_border + textdistotop, _xB2 + textdistotop);
		tft.setTextColor(_buttonColor);
		tft.setTextSize(textSize);
		tft.println(b2);
	} else if (sel == 3) {
		tft.fillRect(_border, _xB3,_buttonwidth, _buttonheight, _textColor);
		tft.setCursor(_border + textdistotop, _xB3 + textdistotop);
		tft.setTextColor(_buttonColor);
		tft.setTextSize(textSize);
		tft.println(b3);
	} else if (sel == 4) {
		tft.fillRect(_border, _xB4, _buttonwidth, _buttonheight, _textColor);
		tft.setCursor(_border + textdistotop, _xB4 + textdistotop);
		tft.setTextColor(_buttonColor);
		tft.setTextSize(textSize);
		tft.println(b4);
	}
}
