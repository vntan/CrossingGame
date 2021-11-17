#include"ListTrucks.h"

ListTrucks::ListTrucks(int lane, bool direction, int numberCars) {
	setLane(lane);
	setRedLight(false);
	setDirection(direction);
	addTrucks(numberCars);
}

ListTrucks::ListTrucks(int lane, bool direction, int numberCars, int carDistance) {

	setLane(lane);
	setRedLight(false);
	setDirection(direction);
	addTrucks(numberCars, carDistance);
}

ListTrucks::~ListTrucks() {
	deleteListCar();
	for (int i = 0; i < listTrucks.size(); ++i) {
		listTrucks[i].freeMemory();
	}
	listTrucks.resize(0);
}

void ListTrucks::addTrucks(int numberCars, int distance) {
	this->numberOfCars = numberCars;
	for (int i = 0; i < numberOfCars; ++i) {
		Truck newTruck;
	
		if (direction == 0) {
			if (i % 2 == 0) {
				newTruck.setX(x + ((distance + 1) * 3) * i);
			}
			else {
				newTruck.setX(x + ((distance + 2) * 3) * i);
			}
			newTruck.setY(y);
		}
		else {
			if (i % 2 == 0) {
				newTruck.setX(x - ((distance + 1) * 3) * i);
			}
			else {
				newTruck.setX(x - ((distance + 2) * 3) * i);

			}
			newTruck.setY(y);
			newTruck.reverseShapeCar();

		}
		newTruck.setCarWidth(8);
		newTruck.setDirection(direction);
		this->listTrucks.push_back(newTruck);
	}
}

void ListTrucks::setLane(int lane) {
	this->lane = lane;
	switch (lane) {
	case 1: {
		y = 22;
		break;
	}
	case 2: {
		y = 18;
		break;
	}
	case 3: {
		y = 14;
		break;
	}
	case 4: {
		y = 10;
		break;
	}
	case 5: {
		y = 6;
		break;
	}
	default:
		y = 22;
	}
}

void ListTrucks::setDirection(bool direction) {
	this->direction = direction;
	if (direction == 0) {
		this->x = 4;
		this->maxX = 86;
	}
	else {
		this->x = 86;
		this->maxX = 4;
	}
}

void ListTrucks::setRedLight(bool redlight) {
	this->redLight = redlight;
}

int ListTrucks::getNumberOfCars() {
	return numberOfCars;
}

bool ListTrucks::getRedLight() {
	return this->redLight;
}

int ListTrucks::getLane() {
	return this->lane;
}

bool ListTrucks::getDirection() {
	return this->direction;
}

void ListTrucks::drawListCar() {
	UIHelper* helper = UIHelper::getUIHelper();

	for (int i = 0; i < listTrucks.size(); ++i) {
		int newX;
		if (direction == 0) {
			newX = listTrucks[i].getX() + 1;
		}
		else {
			newX = listTrucks[i].getX() - 1;
		}
		listTrucks[i].drawCar(newX, y);
	}
	
}

void ListTrucks::deleteListCar() {
	UIHelper* helper = UIHelper::getUIHelper();
	for (int i = 0; i < listTrucks.size(); ++i) {
		listTrucks[i].deleteCar(listTrucks[i].getX(), y);
	}
	
}

void ListTrucks::updateListCar() {
	for (int i = 0; i < listTrucks.size(); ++i) {
		if (direction == 0) {
			if (listTrucks[i].getX() > this->maxX || listTrucks[i].getX() < x) {
				for (int h = 0; h < 8; ++h) {
					listTrucks[i].deleteCar(listTrucks[i].getX() + h, y);
				}
		
				listTrucks[i].freeMemory();
				listTrucks.erase(listTrucks.begin() + i);
				Truck newTruck(x,y,direction);
				newTruck.setCarWidth(8);
				listTrucks.push_back(newTruck);
			}
		}
		else {
			if (listTrucks[i].getX() < this->maxX) {
				for (int h = 0; h < 8; ++h) {
					listTrucks[i].deleteCar(listTrucks[i].getX() - h, y);
				}

				listTrucks[i].freeMemory();
				listTrucks.erase(listTrucks.begin() + i);
				Truck newTruck(x, y, direction);
				newTruck.setCarWidth(8);
				newTruck.reverseShapeCar();

				listTrucks.push_back(newTruck);
			}
		}
	}

}

bool ListTrucks::isCollision(Character* character) {
	for (int i = 0; i < listTrucks.size(); ++i) {
		if (listTrucks[i].getX() <= character->getX() && character->getX() <= listTrucks[i].getX() + 7 && character->getY() >= y && character->getY() <= y + 3) {
			return true;
		}
	}
	return false;
}

void ListTrucks::trafficColor() {
	UIHelper* helper = UIHelper::getUIHelper();


	if (redLight == 0) helper->setTextColor(250);
	else helper->setTextColor(252);

	UIHelper::getUIHelper()->gotoXY(99, 3 + lane * 4);
	cout << (char)219 << (char)219;

	helper->setTextColor(244);
}

