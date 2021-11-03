#include "RedCar.h"
void RedCar::setCarWidth(int width) {
	this->width = width;
}

void RedCar::drawCar(int x, int y) {
	int x2 = x + width;
	int y2 = y + 2;

	UIHelper* helper = UIHelper::getUIHelper();
	helper->gotoXY(x, y2);
	cout << "--" << endl;
}

void RedCar::deleteCar(int x, int y) {
	int x2 = x + width;
	int y2 = y + 2;

	UIHelper* helper = UIHelper::getUIHelper();
	for (int i = y; i <= y2; i++) {
		helper->gotoXY(x, i);
		for (int j = x; j <= x2; j++) cout << " ";
	}
}