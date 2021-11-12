#include"ListTrucks.h"
ListTrucks::ListTrucks() {
	srand(time(NULL));
	this->level = 1;
	this->lane = 1;
	this->speed = level * 100;
	this->x = 4;
	this->y = 22;
	this->maxX = 86;
	this->numberOfCars = 4;
	this->direction = rand() % 2;
}

ListTrucks::ListTrucks(int lane, int level, int y, int numberOfCars) {
	srand(time(NULL));
	this->lane = lane;
	this->level = level;
	this->numberOfCars = numberOfCars;
	this->speed = level * 100;
	this->direction = rand() % 2;
	if (direction == 0) {
		this->x = 4;
	}
	else {
		this->x = 86;
	}
	this->y = y;
	if (direction == 0) {
		this->maxX = 86;
	}
	else {
		this->maxX = 4;

	}
}

ListTrucks::ListTrucks(int lane, int level, bool direction, int numberOfCars ,int y) {
	this->lane = lane;
	this->numberOfCars = numberOfCars;
	this->level = level;
	this->speed = level * 100;
	this->direction = direction;
	if (direction == 0) {
		this->x = 4;
	}
	else {
		this->x = 86;
	}
	this->y = y;
	if (direction == 0) {
		this->maxX = 86;
	}
	else {
		this->maxX = 4;
	}
}



void ListTrucks::addTrucks() {
	int start;
	for (int i = 0; i < numberOfCars; ++i) {
		Truck newTruck;
		switch (i) {
		case 1:
			start = 20;
			break;
		case 2:
			start = 22;
			break;

		case 3:
			start = 24;
			break;
		case 4:
			start = 21;
			break;
		default:
			start = 20;
			break;
		}

		if (direction == 0) {
			newTruck.setX(x + start * i);
			newTruck.setY(y);
		}
		else {
			newTruck.setX(x - start * i);
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
}

void ListTrucks::setLevel(int level) {
	this->level = level;
}

void ListTrucks::setDirection(bool direction) {
	this->direction = direction;
	if (direction == 0) {
		this->x = 4;
	}
	else {
		this->x = 86;
	}
	if (direction == 0) {
		this->maxX = 86;
	}
	else {
		this->maxX = 4;

	}
}

void ListTrucks::setNumberOfCars(int numberOfCars) {
	this->numberOfCars = numberOfCars;
}

int ListTrucks::getNumberOfCars() {
	return numberOfCars;
}





int ListTrucks::getLane() {
	return this->lane;
}

int ListTrucks::getLevel() {
	return this->level;
}

int ListTrucks::getSpeed() {
	return this->speed;
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
		listTrucks[i].drawCar(newX,y);

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
				Truck newTruck;
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


