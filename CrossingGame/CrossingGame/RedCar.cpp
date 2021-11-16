#include "RedCar.h"
void RedCar::setCarWidth(int width) {
	this->width = width;
}

void RedCar::drawCar(int x, int y) {
	carX = x;
	carY = y;
	UIHelper* helper = UIHelper::getUIHelper();
	if (y == 0 || y == 8 || y == 16) {
		helper->gotoXY(x, y += 2);
		cout << " _____ " << endl;
		helper->gotoXY(x, ++y);
		cout << "|___|_\\" << endl;
		helper->gotoXY(x, ++y);
		cout << " 00 00 " << endl;
	}
	else if (y == 4 || y == 12 || y == 20) {
		helper->gotoXY(x, y += 2);
		cout << " _____ " << endl;
		//if ()
		helper->gotoXY(x, ++y);
		cout << "/_|___|" << endl;
		helper->gotoXY(x, ++y);
		cout << " 00 00 " << endl;
	}

}

void RedCar::deleteCar(int x, int y) {
	UIHelper* helper = UIHelper::getUIHelper();
	helper->gotoXY(x, y += 2);
	cout << "       " << endl;
	helper->gotoXY(x, ++y);
	cout << "       " << endl;
	helper->gotoXY(x, ++y);
	cout << "       " << endl;
}