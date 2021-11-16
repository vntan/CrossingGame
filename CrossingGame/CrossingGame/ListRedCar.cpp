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
	for (int i = 0; i < 6; i++) {
		r[i].carX = x;
		r[i].carY = y;
	}

	count = 0;
	numberOfCar = 0;
	flag = false;
}

void ListRedCar::setLevel(int level) {
	this->level = level;
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
		return 150 - 70 * (level - 5);
}

void ListRedCar::drawListCar() {
	for (int i = 0; i < numberOfCar + 1; i++) {
		if (numberOfCar < 5) {
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
	//r.drawCar(r.carX, r.carY);
	/*for (int i = 0; i < 2; i++) {
		if (i == 0)
			r[i].drawCar(r[i].carX, r[i].carY);
		else {
			if (r[i].carX + 7 < r[i - 1].carX || r[i].carX - 7 < r[i - 1].carX)
				r[i].drawCar(r[i].carX, r[i].carY);
		}
	}*/

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
	/*r.deleteCar(r.carX, r.carY);
	if (lane == 2 || lane == 4 || lane == 6) {
		if (r.carX + 2 <= 88)
			r.carX += 2;
		else
			r.carX = 3;
	}
	else if (lane == 1 || lane == 3 || lane == 5) {
		if (r.carX - 2 >= 0)
			r.carX -= 2;
		else
			r.carX = 88;
	}*/
	
}

void ListRedCar::trafficColor() {

}

bool ListRedCar::isCollision(Character* character) {
	for (int i = 0; i < numberOfCar + 1; i++) {
		/*if (((character->getX() >= r[i].carX && character->getX() <= r[i].carX + 7)
			|| (character->getX() + 2 >= r[i].carX && character->getX() <= r[i].carX + 7))
			&& ((character->getY() >= r[i].carY && character->getY() <= r[i].carY + 2)
				|| (character->getY() - 1 >= r[i].carY && character->getY() - 1 <= r[i].carY + 2)))
			return true;*/
		if (((character->getX() >= r[i].carX && character->getX() <= r[i].carX + 7)
			|| (character->getX() + 2 >= r[i].carX && character->getX() <= r[i].carX + 7))
			&& ((character->getY() - 1 >= y + 2 && character->getY() - 1 <= y + 4)
				|| (character->getY() >= y + 2 && character->getY() <= y + 4)))
			return true;
	}
	return false;
}