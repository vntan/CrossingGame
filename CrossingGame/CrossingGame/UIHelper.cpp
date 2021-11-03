#include "UIHelper.h"
#include <ctype.h>

UIHelper::UIHelper() {

}

UIHelper::~UIHelper() {
	delete uiHelper;
	uiHelper = nullptr;
}

UIHelper* UIHelper::uiHelper = nullptr;

UIHelper* UIHelper::getUIHelper() {
	if (uiHelper == nullptr) uiHelper = new UIHelper();
	return uiHelper;
}

int UIHelper::createMenu(int startX, int startY, vector<string> listNameSelection, int defaultChoice) {
	int choice = defaultChoice;
	int x, y; 
	while (true) {
		//draw Menu
		x = startX; y = startY;
		showConsoleCursor(false);
		gotoXY(x, y);

		for (int i = 0; i < listNameSelection.size(); i++) {
			if (i == choice) {
				setTextColor(selectionColor);
				cout << (char)16 << " " << listNameSelection[i] << endl;
			}
			else {
				setTextColor(default_ColorCode);
				cout << listNameSelection[i] << "  " << endl;
			}
			gotoXY(x, ++y);
		}
		showConsoleCursor(true);
		gotoXY(startX, startY+choice);

		//Handle when select or choose menu 
		bool isChange = false;
		while (true) {
			while (!_kbhit()) {}

			int key = getKey();
			if (key == 13) {
				setTextColor(default_ColorCode);
				return choice;
			}
			
			if (key == ArrowKey_DOWN) {
				if (choice + 1 >= listNameSelection.size()) choice = 0; else choice = choice + 1; 
				break;
			}

			if (key == ArrowKey_UP) {
				if (choice - 1 < 0) choice = listNameSelection.size() - 1; else choice = choice - 1;
				break;
			}

			if (key>=1 && key <= 255 && isdigit(key)) {
				if (key - '0' <= listNameSelection.size() && key - '0' > 0) choice = key - '0' - 1;
				break;
			}
		}
	}
}

void UIHelper::drawRectangle(int startX, int startY, int width, int height, int optionStyleRec) {
	showConsoleCursor(false);
	gotoXY(startX, startY);
	vector<int> recStyle = styleRectangle[optionStyleRec% styleRectangle.size()];

	cout << (char)recStyle[0];
	for (int i = 0; i < width * 2 - 2; i++) cout << (char)recStyle[4];
	cout << (char)recStyle[1];
	gotoXY(startX, ++startY);

	for (int i = 0; i < height - 2; i++) {
		for (int j = 0; j < recStyle[recStyle.size()-1]; j++) cout << (char)recStyle[5];
		for (int j = 0; j < (width - recStyle[recStyle.size() - 1]) * 2; j++) cout << " ";
		for (int j = 0; j < recStyle[recStyle.size() - 1]; j++) cout << (char)recStyle[5];
		gotoXY(startX, ++startY);
	}

	cout << (char)recStyle[2];
	for (int i = 0; i < width * 2 - 2; i++) cout << (char)recStyle[4];
	cout << (char)recStyle[3] << endl;
}

void UIHelper::drawRectangleWithAnimate(int startX, int startY, int width, int height, int optionStyleRec) {
	width = width * 2;
	gotoXY(startX, startY);

	vector<int> recStyle = styleRectangle[optionStyleRec % styleRectangle.size()];
	
	cout << (char)recStyle[0];
	for (int i = 0; i < width - 2; i++) {
		cout << (char)recStyle[4];
		Sleep(10);
	}
	cout << (char)recStyle[1];
	Sleep(25);
	
	for (int i = 1; i < height - 1; i++) {
		gotoXY(startX + width - recStyle[recStyle.size() - 1], startY + i);
		for (int j = 0; j < recStyle[recStyle.size() - 1]; j++) cout << (char)recStyle[5];
		Sleep(10);
	}

	gotoXY(startX + width - 1, startY + height - 1);
	cout << (char)recStyle[3];
	Sleep(25);
	
	for (int i = 2; i < width; i++) {
		gotoXY(startX + width - i, startY + height - 1);
		cout << (char)recStyle[4];
		Sleep(10);
	}

	gotoXY(startX, startY + height - 1);
	cout << (char)recStyle[2];
	Sleep(25);

	for (int i = 1; i < height - 1; i++) {
		gotoXY(startX, startY + height - 1 - i);
		for (int j = 0; j < recStyle[recStyle.size() - 1]; j++) cout << (char)recStyle[5];
		Sleep(10);
	}

	gotoXY(startX, startY);

}

void UIHelper::drawHeaderText() {
	cout << "     ______ .______        ______        _______.     _______. __  .__   __.   _______      _______      ___      .___  ___.  _______ " << endl;
	cout << "    /      ||   _  \\      /  __  \\      /       |    /       ||  | |  \\ |  |  /  _____|    /  _____|    /   \\     |   \\/   | |   ____|" << endl;
	cout << "   |  ,----'|  |_)  |    |  |  |  |    |   (----`   |   (----`|  | |   \\|  | |  |  __     |  |  __     /  ^  \\    |  \\  /  | |  |__   " << endl;
	cout << "   |  |     |      /     |  |  |  |     \\   \\        \\   \\    |  | |  . `  | |  | |_ |    |  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|" << endl;
	cout << "   |  `----.|  |\\  \\----.|  `--'  | .----)   |   .----)   |   |  | |  |\\   | |  |__| |    |  |__| |  /  _____  \\  |  |  |  | |  |____ " << endl;
	cout << "    \\______|| _| `._____| \\______/  |_______/    |_______/    |__| |__| \\__|  \\______|     \\______| /__/     \\__\\ |__|  |__| |_______|" << endl;
}