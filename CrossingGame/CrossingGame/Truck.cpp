#include"Truck.h"

void Truck::setCarWidth(int width) {
	this->width = width;
}

int Truck::getX() {
	return x;
}
int Truck::getY() {
	return y;
}

void Truck::setX(int x) {
	this->x = x;
}

void Truck::setY(int y) {
	this->y = y;
}

Truck::Truck() {
	this->x = 4;
	this->y = 0;

	this->car = new char* [3];
	for (int i = 0; i < 3; ++i) {
		car[i] = new char[8];
	}
	// Row 1
	car[0][0] = char(218);
	for (int i = 1; i < 7; ++i)
		car[0][i] = char(196);
	car[0][7] = char(191);
	// Row 2
	car[1][0] = char(179);
	for (int i = 1; i < 8; ++i) {
		if (i == 6) car[1][i] = char(254);
		else if (i == 7) car[1][i] = char(179);
		else
			car[1][i] = ' ';
	}
	// Row 3
	car[2][0] = char(192);
	for (int i = 1; i < 7; ++i) {
		if (i == 1 || i == 6) car[2][i] = 'O';
		else
			car[2][i] = char(196);
	}
	car[2][7] = char(217);
}


void Truck::drawCar(int x, int y) {
	UIHelper* helper = UIHelper::getUIHelper();
	this->x = x;
	this->y = y;

	for (int i = 0; i < 3; ++i) {
		helper->gotoXY(x, y + i);
		for (int j = 0; j < 8; ++j) {
			cout << car[i][j];
		}
		cout << endl;
	}



}

void Truck::deleteCar(int x, int y) {

	UIHelper* helper = UIHelper::getUIHelper();
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 8; ++j) {
			helper->gotoXY(x - j, y + i);
			if (helper->getCursorX() == 2) continue;
			cout << " ";
		}
		cout << endl;
	}
}

//Truck::~Truck() {
//	for (int i = 0; i < 3; ++i) {
//		delete car[i];
//	}
//	delete[] car;
//}

void Truck::reverseShapeCar() {
	for (int i = 0; i < 3; ++i) {
		reverse(car[i] + 1, car[i] + 7);
	}
}

void Truck::freeMemory() {
	for (int i = 0; i < 3; ++i) {
		delete car[i];
	}
	delete[] car;
}