#include "ConsoleHelper.h"

ConsoleHelper::ConsoleHelper() {
	fixConsoleWindow();
}

//--------------------Get filePath-------------------------
string ConsoleHelper::getFilePath() {
	return filePath;
}

void ConsoleHelper::setFilePath(char* path) {
	string temp(path);
	int pos = temp.find_last_of('\\');
	filePath = temp.substr(0, pos + 1);
}

//--------------------Get key on click-------------------------
int ConsoleHelper::getKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)	// special key Arrow
		{
			key = _getch();
			return key + 1000;
		}

		if (key == 0)	// special key F1 F2 F3 F4 ....
		{
			key = _getch();
			return key + 2000;
		}

		return key;
	}
	else return -1;
}

//-------------------------Screen-------------------------
void ConsoleHelper::clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	system("F0");
	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}


//screen: goto [x,y]
void ConsoleHelper::gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


//screen: get [x]
int ConsoleHelper::getCursorX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}

//screen: get max [x]
int ConsoleHelper::getMaxX() {
	return maxScreenX;
}

//screen: get [y]
int ConsoleHelper::getCursorY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}

//screen: get max [y]
int ConsoleHelper::getMaxY() {
	return maxScreenY;
}

void ConsoleHelper::setTextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void ConsoleHelper::getAllTextColor()
{
	for (int i = 1; i < 255; i++) {
		setTextColor(i);
		printf("Color: %d\n", i);
	}
	setTextColor(default_ColorCode);
	printf("\n");
}

void ConsoleHelper::removeScrollbar()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}


void ConsoleHelper::fixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);

	RECT ConsoleRect;
	GetWindowRect(consoleWindow, &ConsoleRect);
	MoveWindow(consoleWindow, ConsoleRect.left, ConsoleRect.top, 1130, 540, TRUE);

	//remove ScrollBar
	removeScrollbar();

	//Set Background
	system("color F0");

	//force mouse click to console
	DWORD prev_mode;
	GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &prev_mode);
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS | (prev_mode & ~ENABLE_QUICK_EDIT_MODE));
}

void ConsoleHelper::showConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

/*
 0 = Black, 1 = Blue, 2 = Green, 3 = Aqua, 4 = Red, 5 = Purple, 6 = Yellow, 7 = White, 8 = Gray, 9 = Light Blue,
 A = Light Green, B = Light Aqua, C = Light Red, D = Light Purple, E = Light Yellow, F = Bright White.
*/