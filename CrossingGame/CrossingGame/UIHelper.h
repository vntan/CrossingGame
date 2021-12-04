#pragma once
#include <iostream>
#include <vector>
#include "ConsoleHelper.h"


using namespace std;

class UIHelper: public ConsoleHelper
{
private:
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
	
public:
	static UIHelper* getUIHelper();

	/// <summary>
	/// Tạo một menu
	/// </summary>
	/// <param name="startX">Vị trí theo chiều ngang</param>
	/// <param name="startY">Vị trí theo chiều dọc</param>
	/// <param name="listNameSelection">Tên các lựa chọn trong Menu</param>
	/// <param name="defaultChoice">Lựa chọn mặc định</param>
	/// <returns></returns>
	int createMenu(int startX, int startY, vector<string> listNameSelection, int defaultChoice = 0);
	
	/// <summary>
	/// Vẽ Hình Chữ Nhật
	/// </summary>
	/// <param name="startX">Vị trí theo chiều ngang</param>
	/// <param name="startY">Vị trí theo chiều dọc</param>
	/// <param name="width">Chiều dài</param>
	/// <param name="height">Chiều rộng</param>
	/// <param name="optionStyleRec">Kiểu Hình Chữ Nhật</param>
	void drawRectangle(int startX, int startY, int width, int height, int optionStyleRec = 0);

	void drawRectangleWithAnimate(int startX, int startY, int width, int height, int optionStyleRec = 0);

	void drawHeaderText();

	~UIHelper();
};

