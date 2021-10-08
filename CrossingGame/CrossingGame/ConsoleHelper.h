#pragma once
#include <windows.h>
#include <stdio.h>
#include <conio.h>

class ConsoleHelper
{
private:
	static ConsoleHelper* console;

	const int maxScreenX = 130;
	const int maxScreenY = 29;

private:
	ConsoleHelper() {};
	~ConsoleHelper() { 
		delete console;
		console = nullptr;
	};
public:
	static ConsoleHelper* getConsole();

	int getKey();

	//-------------------------Screen-------------------------
	void clrscr();

	//screen: goto [x,y]
	void gotoXY(int column, int line);

	//screen: get [x]
	int getCursorX();
	//screen: get [y]
	int getCursorY();

	void setTextColor(int color);

	void getAllTextColor();

	void fixConsoleWindow();

	void showConsoleCursor(bool showFlag);

	void removeScrollbar();
	
	enum Colors {
		ColorCode_DarkBlue = 1,
		ColorCode_DarkGreen = 2,
		ColorCode_DarkCyan = 3,
		ColorCode_DarkRed = 4,
		ColorCode_DarkPink = 5,
		ColorCode_DarkYellow = 6,
		ColorCode_DarkWhite = 7,
		ColorCode_Grey = 8,
		ColorCode_Blue = 9,
		ColorCode_Green = 10,
		ColorCode_Cyan = 11,
		ColorCode_Red = 12,
		ColorCode_Pink = 13,
		ColorCode_Yellow = 14,
		ColorCode_White = 15,
		default_ColorCode = 15,
	};

	enum ArrowKey {
		ArrowKey_UP = 1072,
		ArrowKey_DOWN = 1080,
		ArrowKey_LEFT = 1075,
		ArrowKey_RIGHT = 1077
	};
};

