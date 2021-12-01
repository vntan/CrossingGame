#include "Chicken.h"
void Chicken::setCarWidth(int width) {
	this->width = width;
}
void Chicken::drawCar(int x, int y) {
	UIHelper* helper = UIHelper::getUIHelper();
	this->x = x;
	this->y = y;
	for (int i = 0; i < 3; ++i) {
		helper->gotoXY(x, y + i);
		for (int j = 0; j < 6; ++j) {
			cout << chick[i][j];
		}
		cout << endl;
	}
}
void Chicken::deleteCar(int x, int y) {
	UIHelper* helper = UIHelper::getUIHelper();
	this->x = x;
	this->y = y;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 6; ++j) {
			if (direction == true) {
				helper->gotoXY(x + j, y + i);
				cout << " ";
			}
			else {
				helper->gotoXY(x + 5 - j, y + i);
				cout << " ";
			}
		}
	}
}
int Chicken::getX() {
	return x;
}
int Chicken::getY() {
	return y;

}
void Chicken::setX(int x) {
	this->x = x;
}
void Chicken::setY(int y) {
	this->y = y;
}
void Chicken::setDirect(bool direct) {
	this->direction = direct;
}
Chicken::Chicken() {
	this->x = 4;
	this->y = 0;
	this->direction = true; //right
	this->chick = new char* [3];
	for (int i = 0; i < 3; ++i) {
		chick[i] = new char[6];
	}
	//Row1
	chick[0][0] = ' ';
	for (int i = 1; i < 6; i++)
	{
		if (i == 2 || i == 4) chick[0][i] = '.';
		else chick[0][i] = '~';
		if (i == 3) chick[0][i] = ' ';
	}
	//Row2
	chick[1][0] = '|';
	chick[1][1] = ']';
	chick[1][2] = ' ';
	chick[1][3] = '>';
	chick[1][4] = ' ';
	chick[1][5] = '|';
	//Row3
	for (int i = 0; i < 6; ++i) {
		if (i == 1 || i == 4) chick[2][i] = (char)94;
		else chick[2][i] = ' ';
	}
}

Chicken::Chicken(int x, int y, bool direct) {
	this->x = x;
	this->y = y;
	this->direction = direct;
	this->chick = new char* [3];
	for (int i = 0; i < 3; ++i) {
		chick[i] = new char[6];
	}
	if (direction == true) {
		//Row1
		chick[0][0] = ' ';
		for (int i = 1; i < 6; i++)
		{
			if (i == 2 || i == 4) chick[0][i] = '.';
			else chick[0][i] = '~';
			if (i == 3) chick[0][i] = ' ';
		}
		//Row2
		chick[1][0] = '|';
		chick[1][1] = ']';
		chick[1][2] = ' ';
		chick[1][3] = '>';
		chick[1][4] = ' ';
		chick[1][5] = '|';
		//Row3
		for (int i = 0; i < 6; ++i) {
			if (i == 1 || i == 4) chick[2][i] = (char)94;
			else chick[2][i] = ' ';
		}
	}
}
void Chicken::drawReverseChick() {
	//Row1
	chick[0][5] = ' ';
	for (int i = 0; i < 5; i++)
	{
		if (i == 1 || i == 3) chick[0][i] = '.';
		else chick[0][i] = '~';
		if (i == 2) chick[0][i] = ' ';
	}
	//Row2
	chick[1][0] = '|';
	chick[1][1] = ' ';
	chick[1][2] = '<';
	chick[1][3] = ' ';
	chick[1][4] = '[';
	chick[1][5] = '|';
	//Row3
	for (int i = 0; i < 6; ++i) {
		if (i == 1 || i == 4) chick[2][i] = (char)94;
		else chick[2][i] = ' ';
	}

}
void Chicken::deleteMemory() {
	for (int i = 0; i < 3; ++i) {
		delete chick[i];
	}
	delete[] chick;
}
