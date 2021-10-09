#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "ConsoleHelper.h"


using namespace std;

class UIHelper
{
private:
	ConsoleHelper* consoleHelper;
	static UIHelper* uiHelper;

	int selectionColor = 189;

	const vector<vector<int>> styleRectangle{
		{ 218, 191, 192, 217, 196, 179, 1 }, //'┌', '┐','└','┘','─','│' <width: 1>
		{ 201, 187, 200, 188, 205, 186, 1 }, //'╔', '╗','╚','╝','═','║' <width: 1>
		{ 176, 176, 176, 176, 176, 176, 2 }, //'░', '░','░','░','░','░' <width: 2>
		{ 177, 177, 177, 177, 177, 177, 2 }, //'▒', '▒','▒','▒','▒','▒' <width: 2>
		{ 178, 178, 178, 178, 178, 178, 2 } // '▓', '▓','▓','▓','▓','▓' <width: 2>
	};
	
	UIHelper();
	~UIHelper();
public:
	static UIHelper* getUIHelper();

	int createMenu(int startX, int startY, vector<string> listNameSelection, int defaultChoice);
	void drawRectangle(int startX, int startY, int width, int height);
	void drawRectangle(int startX, int startY, int width, int height, int optionStyleRec);
	
};

