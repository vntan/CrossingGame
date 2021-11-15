#include "ListFastAFCars.h"

ListFastAFCars::ListFastAFCars(){
	if (rand() % 2 == 0) {
		lane = 1;
		posY = 7;
		reverse = true;
		posX = nullptr;
		level = 1;
		stop = false;
		turncount = (rand() % 30) + 1;
		firstdraw = nullptr;
		countstep = nullptr;
		numofcars = 1;
		car = nullptr;
	}
	else {
		lane = 1;
		posY = 7;
		posX = nullptr;
		level = 1;
		stop = false;
		turncount = (rand() % 30) + 1;
		firstdraw = nullptr;
		countstep = nullptr;
		reverse = false;
		numofcars = 1;
		car = nullptr;
	}
}

ListFastAFCars::~ListFastAFCars() {
	delete[] car;
	delete[] posX;
	delete[] countstep;
	delete[] firstdraw;
}

void ListFastAFCars::addCars(int n) {
	car = new FastAFCar[n];
	posX = new int[n];
	countstep = new int[n];
	firstdraw = new bool[n];
	numofcars = n;
	resetStatus();
}

void ListFastAFCars::resetStatus() {
	if (rand() % 2 == 0) {
		setLane(this->lane);
		for (int i = 0; i < numofcars; i++) {
			posX[i] = 95;
			firstdraw[i] = true;
			countstep[i] = 1;
		}
		level = 1;
		stop = false;
		turncount = (rand() % 30) + 1;
		reverse = true;
	}
	else {
		setLane(this->lane);
		for (int i = 0; i < numofcars; i++) {
			posX[i] = 3;
			firstdraw[i] = true;
			countstep[i] = 1;
		}
		level = 1;
		stop = false;
		turncount = (rand() % 30) + 1;
		reverse = false;
	}
}

int ListFastAFCars::getSleepTime() {
	if (stop)
		return 110 - 20 * level;
	else
		return 11 - 2 * level;
}

void ListFastAFCars::setLane(int lane) {
	this->lane = lane;
	posY = 6 + 4 * (lane - 1);
}

void ListFastAFCars::setLevel(int level) {
	this->level = level;
}

void ListFastAFCars::drawListCar(int i) {
	if (posX[i] == 3) {
		car[i].drawCar(posX[i], posY, countstep[i]);
	}
	else {
		car[i].drawCar(posX[i], posY, 95 - posX[i]);
	}
}

void ListFastAFCars::updateListCar() {
	for (int i = 0; i < numofcars; i++) {
		if (stop) {
			turncount--;
			if (turncount < 0) {
				stop = false;
				trafficColor();
				break;
			}
		}
		else {
			if (i == 0) {
				if (reverse) {
					if (posX[i] >= 3) {
						if (firstdraw[i]) {
							drawListCarReverse(i);
							firstdraw[i] = false;
						}
						else {
							deleteListCarReverse(i);
							drawListCarReverse(i);
						}
					}
				}
				else {
					if (posX[i] <= 95) {
						if (firstdraw[i]) {
							drawListCar(i);
							firstdraw[i] = false;
						}
						else {
							deleteListCar(i);
							drawListCar(i);
						}
					}
				}
			}
			else  {
				if (reverse) {
					if (posX[i] >= 3 && posX[i - 1] <= 85) {
						if (firstdraw[i]) {
							drawListCarReverse(i);
							firstdraw[i] = false;
						}
						else {
							deleteListCarReverse(i);
							drawListCarReverse(i);
						}
					}
				}
				else {
					if (posX[i] <= 95 && posX[i - 1] >= 13) {
						if (firstdraw[i]) {
							drawListCar(i);
							firstdraw[i] = false;
						}
						else {
							deleteListCar(i);
							drawListCar(i);
						}
					}
				}
			}
		}
	}
	if ((reverse == true && posX[numofcars - 1] < 3) || (reverse == false && posX[numofcars - 1] >= 95)) {
		resetStatus();
		stop = true;
		trafficColor();
	}
}

void ListFastAFCars::deleteListCar(int i) {
	if (posX[i] == 3) {
		car[i].deleteCar(posX[i], posY, countstep[i]);
		countstep[i]++;
		if (countstep[i] > 9) {
			posX[i]++;
			countstep[i] = 9;
		}
	}
	else {
		car[i].deleteCar(posX[i], posY, 95 - posX[i]);
		posX[i]++;
	}
}

void ListFastAFCars::trafficColor() {
	if (stop) {
		UIHelper::getUIHelper()->setTextColor(244); // red
		UIHelper::getUIHelper()->gotoXY(99, 3 + lane * 4);
		cout << (char)219 << (char)219;
	}
	else {
		UIHelper::getUIHelper()->setTextColor(242); // red
		UIHelper::getUIHelper()->gotoXY(99, 3 + lane * 4);
		cout << (char)219 << (char)219;
	}
}

bool ListFastAFCars::isCollision(Character* character) {
	for (int i = 0; i < numofcars; i++) {
		if (reverse) {
			if (character->getY() == posY || character->getY() == posY + 1 || character->getY() == posY + 2) {
				if (character->getX() >= posX[i] && character->getX() <= posX[i] - countstep[i] + 9)
					return true;
				else if (character->getX() + 2 >= posX[i] && character->getX() + 2 <= posX[i] - countstep[i] + 9)
					return true;
			}
			else if (character->getY() == posY + 3) {
				if (character->getX() + 1 >= posX[i] && character->getX() + 1 <= posX[i] - countstep[i] + 9)
					return true;
			}
		}
		else {
			if (character->getY() == posY || character->getY() == posY + 1 || character->getY() == posY + 2) {
				if (character->getX() >= posX[i] && character->getX() <= posX[i] + countstep[i] - 1)
					return true;
				else if (character->getX() + 2 >= posX[i] && character->getX() + 2 <= posX[i] + countstep[i] - 1)
					return true;
			}
			else if (character->getY() == posY + 3) {
				if (character->getX() + 1 >= posX[i] && character->getX() + 1 <= posX[i] + countstep[i] - 1)
					return true;
			}
		}
	}
	return false;
}

void ListFastAFCars::drawListCarReverse(int i) {
	if (posX[i] <= 3) {
		car[i].drawCarReverse(posX[i], posY, 9 - countstep[i]);
	}
	else {
		car[i].drawCarReverse(posX[i], posY, 95 - posX[i]);
	}
}

void ListFastAFCars::deleteListCarReverse(int i) {
	if (posX[i] <= 3) {
		car[i].deleteCarReverse(posX[i], posY, 9 - countstep[i]);
		countstep[i]++;
		if (countstep[i] > 9) {
			posX[i]--;
			countstep[i] = 9;
		}
	}
	else {
		car[i].deleteCarReverse(posX[i], posY, 95 - posX[i]);
		posX[i]--;
	}
}

void ListFastAFCars::drawListCar() {

}

void ListFastAFCars::deleteListCar() {

}