#include "ListFastAFCars.h"

ListFastAFCars::ListFastAFCars() {
	if (rand() % 2 == 0) {
		lane = 1;
		posY = 22;
		reverse = true;
		posX = nullptr;
		level = 1;
		stop = false;
		firstdraw = nullptr;
		countstep = nullptr;
		numofcars = 1;
		car = nullptr;
		distance = 10;
		isRed = false;
	}
	else {
		lane = 1;
		posY = 22;
		posX = nullptr;
		level = 1;
		stop = false;
		firstdraw = nullptr;
		countstep = nullptr;
		reverse = false;
		numofcars = 1;
		car = nullptr;
		distance = 10;
		isRed = false;
	}
}

ListFastAFCars::~ListFastAFCars() {
	delete[] car;
	delete[] posX;
	delete[] countstep;
	delete[] firstdraw;
}

void ListFastAFCars::addCars(int n, int distance) {
	car = new FastAFCar[n];
	posX = new int[n];
	countstep = new int[n];
	firstdraw = new bool[n];
	numofcars = n;
	if (distance < 10)
		this->distance = 10;
	else
		this->distance = distance;
	resetStatus();
}

void ListFastAFCars::setTraffic(bool isRed) {
	this->isRed = isRed;
	this->stop = isRed;
}

bool ListFastAFCars::getTraffic() {
	return isRed;
}

int ListFastAFCars::getTimeToRed() {
	if (stop)
		return (level * 100) / 2;
	else
		return (level * 100);
}

void ListFastAFCars::setStop(bool stop) {
	this->stop = stop;
}

void ListFastAFCars::resetStatus() {
	if (rand() % 2 == 0) {
		setLane(this->lane);
		for (int i = 0; i < numofcars; i++) {
			posX[i] = 95;
			firstdraw[i] = true;
			countstep[i] = 1;
		}
		stop = false;
		reverse = true;
		isRed = false;
	}
	else {
		setLane(this->lane);
		for (int i = 0; i < numofcars; i++) {
			posX[i] = 3;
			firstdraw[i] = true;
			countstep[i] = 1;
		}
		stop = false;
		reverse = false;
		isRed = false;
	}
}

int ListFastAFCars::getSleepTime() {
	if (stop)
		return 110 - 20 * level;
	else
		return 31 - 4 * level;
}

void ListFastAFCars::setLane(int lane) {
	this->lane = lane;
	posY = 22 - 4 * (lane - 1);
}

void ListFastAFCars::setLevel(int level) {
	if (level > 5)
		level = 5; // =))
	this->level = level;
	addCars(level, 10 + 5 * level);
}

void ListFastAFCars::saveCar(string fileName) {
	fstream fout(fileName, ios::out);
	fout << reverse << " " << distance << " " << posY << " " << numofcars << " " << level << " " << lane << " " << stop << " " << isRed << endl;
	for (int i = 0; i < numofcars; i++) {
		fout << posX[i] << " " << countstep[i] << " " << firstdraw[i] << endl;
	}
	fout.close();
}

void ListFastAFCars::loadCar(string fileName) {
	fstream fin(fileName, ios::in);
	fin >> reverse >> distance >> posY >> numofcars >> level >> lane >> stop >> isRed;
	delete[] car; car = nullptr;
	delete[] posX;
	delete[] countstep;
	delete[] firstdraw;


	if (car == nullptr) {
		car = new FastAFCar[numofcars];
		posX = new int[numofcars];
		countstep = new int[numofcars];
		firstdraw = new bool[numofcars];
	}
	for (int i = 0; i < numofcars; i++) {
		fin >> posX[i] >> countstep[i] >> firstdraw[i];
	}
	trafficColor();
	for (int i = 0; i < numofcars; i++) {
		if (reverse)
			drawListCarReverse(i);
		else
			drawListCar(i);
	}
	fin.close();
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
		if (stop) {}
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
			else {
				if (reverse) {
					if (posX[i] >= 3 && posX[i - 1] <= 95 - distance) {
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
					if (posX[i] <= 95 && posX[i - 1] >= 3 + distance / 2) {
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
	if ((reverse == true && posX[numofcars - 1] < 3) || (reverse == false && posX[numofcars - 1] >= 95))
		resetStatus();
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

void ListFastAFCars::deleteEverything() {
	UIHelper* p;
	p->getUIHelper()->gotoXY(3, this->posY);
	cout << "                                                                                            ";
	p->getUIHelper()->gotoXY(3, this->posY + 1);
	cout << "                                                                                            ";
	p->getUIHelper()->gotoXY(3, this->posY + 2);
	cout << "                                                                                            ";
}

void ListFastAFCars::trafficColor() {
	if (isRed) {
		UIHelper::getUIHelper()->setTextColor(252); // red
		UIHelper::getUIHelper()->gotoXY(99, 23 - 4 * (lane - 1));
		cout << (char)219 << (char)219;
	}
	else {
		UIHelper::getUIHelper()->setTextColor(250); // red
		UIHelper::getUIHelper()->gotoXY(99, 23 - 4 * (lane - 1));
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