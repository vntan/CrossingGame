#pragma once
#include <windows.h>
#include <stdio.h>
#include <conio.h>

class ConsoleHelper
{
private:
	static ConsoleHelper* consoleUtilities;

	const int maxScreenX = 136;
	const int maxScreenY = 30;

private:
	ConsoleHelper();
	~ConsoleHelper();

	void fixConsoleWindow();
	void removeScrollbar();
public:
	static ConsoleHelper* getConsoleUtilities();

	int getKey();

	//-------------------------Screen-------------------------
	void clrscr();

	//screen: goto [x,y]
	void gotoXY(int column, int line);

	//screen: get [x]
	int getCursorX();

	//screen: get max [x]
	int getMaxX();

	//screen: get [y]
	int getCursorY();

	//screen: get max [y]
	int getMaxY();

	//Change Text Color
	void setTextColor(int color);

	//Get All Text Color
	void getAllTextColor();

	// Show console's cursor
	void showConsoleCursor(bool showFlag);

	enum Colors {
		ColorCode_White = 240,
		ColorCode_DarkBlue = 241,
		ColorCode_DarkGreen = 242,
		ColorCode_DarkCyan = 243,
		ColorCode_DarkRed = 244,
		ColorCode_DarkPink = 245,
		ColorCode_DarkYellow = 246,
		ColorCode_DarkWhite = 247,
		ColorCode_Grey = 248,
		ColorCode_Blue = 249,
		ColorCode_Green = 250,
		ColorCode_Cyan = 251,
		ColorCode_Red = 252,
		ColorCode_Pink = 253,
		ColorCode_Yellow = 254,
		default_ColorCode = 240,
	};

	enum ArrowKey {
		ArrowKey_UP = 1072,
		ArrowKey_DOWN = 1080,
		ArrowKey_LEFT = 1075,
		ArrowKey_RIGHT = 1077
	};
};

