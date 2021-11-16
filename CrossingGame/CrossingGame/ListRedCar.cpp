#include"ListRedCar.h"

void ListRedCar::setLane(int lane) {
	this->lane = lane;
	if (lane == 1) {
		x = 88;
		y = 20;
	}
	else if (lane == 2) {
		x = 3;
		y = 16;
	}
	else if (lane == 3) {
		x = 88;
		y = 12;
	}
	else if (lane == 4) {
		x = 3;
		y = 8;
	}
	else if (lane == 5) {
		x = 88;
		y = 4;
	}
	else if (lane == 6) {
		x = 3;
		y = 0;
	}

	count = 0;
	numberOfCar = 0;
	flag = false;
	this->redLight = 0;
}

void ListRedCar::setLevel(int level) {
	this->level = level;
	if (level == 1 || level == 2 || level == 3) {
		maxCar = 5;
		timeRedLight = 60;
	}
	else if (level >= 4) {
		maxCar = 6;
		timeRedLight = 40;
	}
	r = new RedCar[maxCar];

	for (int i = 0; i < maxCar; i++) {
		r[i].carX = x;
		r[i].carY = y;
	}
}

int ListRedCar::getSleep() {
	if (level == 1)
		return 600;
	else if (level == 2)
		return 500;
	else if (level == 3)
		return 400;
	else if (level == 4)
		return 150;
	else if (level == 5)
		return 100;
	else if (level > 5)
		return 150 - 50 * (level - 5);
}

void ListRedCar::drawListCar() {
	for (int i = 0; i < numberOfCar + 1; i++) {
		if (numberOfCar < maxCar - 1) {
			if (count > 6) {
				numberOfCar++;
				count = 0;
			}
		}
		r[i].drawCar(r[i].carX, r[i].carY);
		if (i == 0) {
			count++;
		}
	}
}

void ListRedCar::updateListCar() {
	deleteListCar();
	drawListCar();
}

void ListRedCar::deleteListCar() {
	for (int i = 0; i < numberOfCar + 1; i++) {
		if (flag == true) {
			r[i].deleteCar(r[i].carX, r[i].carY);
			if (lane == 2 || lane == 4 || lane == 6) {
				if (r[i].carX + 2 <= 88)
					r[i].carX += 2;
				else
					r[i].carX = 3;
			}
			else if (lane == 1 || lane == 3 || lane == 5) {
				if (r[i].carX - 2 >= 3)
					r[i].carX -= 2;
				else
					r[i].carX = 88;
			}
		}
		else
			flag = true;
	}
}
void ListRedCar::setRedLight(bool redLight) {
	this->redLight = redLight;
}

bool ListRedCar::getRedLight() {
	return redLight;
}

int ListRedCar::getTimeRedLight() {
	return timeRedLight;
}

void ListRedCar::trafficColor() {
	UIHelper* helper = UIHelper::getUIHelper();


	if (redLight == 0) helper->setTextColor(250);
	else helper->setTextColor(252);

	UIHelper::getUIHelper()->gotoXY(99, 3 + lane * 4);
	cout << (char)219 << (char)219;

	helper->setTextColor(244);
}

bool ListRedCar::isCollision(Character* character) {
	for (int i = 0; i < numberOfCar + 1; i++) {
		if (((character->getX() >= r[i].carX && character->getX() <= r[i].carX + 7)
			|| (character->getX() + 2 >= r[i].carX && character->getX() <= r[i].carX + 7))
			&& ((character->getY() - 1 >= y + 2 && character->getY() - 1 <= y + 4)
				|| (character->getY() >= y + 2 && character->getY() <= y + 4)))
			return true;
	}
	return false;
}