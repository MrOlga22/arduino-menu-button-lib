This is a library to easy generate menu buttons. 
This library works only with Adafruit_TFTLCD library: 
	---->https://github.com/adafruit/TFTLCD-Library
	
Written by MrOlga22. 
 
Commands: 
Menu m; //initialize class instance m 
 
m.setTextColor("Color"); 
m.setButtonColor("color"); 
m.setBackgroundColor("color"); 
m.setColors("Text Color","Button Color","Background Color"); 
 
m.getTextColor(); //returns uint16_t (16 bit color code) 
m.getButtonColor(); //returns uint16_t (16 bit color code) 
m.getBackgroundColor(); //returns uint16_t (16 bit color code) 
 
m.getButtonHeight(); //returns int (px) 
m.getButtonWidth(); //returns int (px) 
m.getBorder(); //returns int (px) 
 
m.oneButton("Btn Text", Selected Btn (0 for none, 1 for first Btn); 
m.twoButtons("Btn1 Text", "Btn2 Text", Selected Btn); 
m.threeButtons("Btn1 Text", "Btn2 Text" , "Btn3 Text", Selected Btn); 
m.fourButtons("Btn1 Text", "Btn2 Text" , "Btn3 Text", "Btn4 Text", Selected Btn); 
