#include "ListFastAFCars.h"

ListFastAFCars::ListFastAFCars(){
	if (rand() % 2 == 0) {
		lane = 1;
		posY = 7;
		reverse = true;
		posX = 94;
		level = 1;
		stop = false;
		turncount = (rand() % 10) + 1;
		firstdraw = true;
		countstep = 1;
	}
	else {
		lane = 1;
		posY = 7;
		posX = 3;
		level = 1;
		stop = false;
		turncount = (rand() % 10) + 1;
		firstdraw = true;
		countstep = 1;
		reverse = false;
	}
}

void ListFastAFCars::resetStatus() {
	if (rand() % 2 == 0) {
		reverse = true;
		setLane(this->lane);
		posX = 95;
		level = 1;
		stop = false;
		turncount = (rand() % 10) + 1;
		firstdraw = true;
		countstep = 1;
	}
	else {
		setLane(this->lane);
		posX = 3;
		level = 1;
		stop = false;
		turncount = (rand() % 10) + 1;
		firstdraw = true;
		countstep = 1;
		reverse = false;
	}
}

int ListFastAFCars::getSleepTime() {
	if (stop)
		return 1100 - 200 * level;
	else
		return 110 - 20 * level;
}

void ListFastAFCars::setLane(int lane) {
	this->lane = lane;
	posY = 6 + 4 * (lane - 1);
}

void ListFastAFCars::setLevel(int level) {
	this->level = level;
}

void ListFastAFCars::drawListCar() {
	if (posX == 3) {
		car.drawCar(posX, posY, countstep);
	}
	else {
		car.drawCar(posX, posY, 95 - posX);
	}
}

void ListFastAFCars::updateListCar() {
	if (stop) {
		turncount--;
		if (turncount < 0) {
			stop = false;
			trafficColor();
		}
	}
	else {
		if (reverse) {
			if (firstdraw) {
				drawListCarReverse();
				firstdraw = false;
			}
			else {
				deleteListCarReverse();
				drawListCarReverse();
			}
			if (posX == 2) {
				resetStatus();
				stop = true;
				trafficColor();
			}
		}
		else {
			if (firstdraw) {
				drawListCar();
				firstdraw = false;
			}
			else {
				deleteListCar();
				drawListCar();
			}
			if (posX == 95) {
				resetStatus();
				stop = true;
				trafficColor();
			}
		}
	}
}

void ListFastAFCars::deleteListCar() {
	if (posX == 3) {
		car.deleteCar(posX, posY, countstep);
		countstep++;
		if (countstep > 9) {
			posX++;
			countstep = 9;
		}
	}
	else {
		car.deleteCar(posX, posY, 95 - posX);
		posX++;
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
	if (reverse) {
		if (character->getY() == posY || character->getY() == posY + 1 || character->getY() == posY + 2) {
			if (character->getX() >= posX && character->getX() <= posX - countstep + 9)
				return true;
			else if (character->getX() + 2 >= posX && character->getX() + 2 <= posX - countstep + 9)
				return true;
			else
				return false;
		}
		else if (character->getY() == posY + 3) {
			if (character->getX() + 1 >= posX && character->getX() + 1 <= posX - countstep + 9)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else {
		if (character->getY() == posY || character->getY() == posY + 1 || character->getY() == posY + 2) {
			if (character->getX() >= posX && character->getX() <= posX + countstep - 1)
				return true;
			else if (character->getX() + 2 >= posX && character->getX() + 2 <= posX + countstep - 1)
				return true;
			else
				return false;
		}
		else if (character->getY() == posY + 3) {
			if (character->getX() + 1 >= posX && character->getX() + 1 <= posX + countstep - 1)
				return true;
			else
				return false;
		}
		else
			return false;
	}
}

void ListFastAFCars::drawListCarReverse() {
	if (posX <= 3) {
		car.drawCarReverse(posX, posY, 9 - countstep);
	}
	else {
		car.drawCarReverse(posX, posY, 95 - posX);
	}
}

void ListFastAFCars::deleteListCarReverse() {
	if (posX <= 3) {
		car.deleteCarReverse(posX, posY, 9 - countstep);
		countstep++;
		if (countstep > 9) {
			posX--;
			countstep = 9;
		}
	}
	else {
		car.deleteCarReverse(posX, posY, 95 - posX);
		posX--;
	}
}