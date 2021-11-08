#include"ListTrucks.h"
ListTrucks::ListTrucks() {
	this->level = 1;
	this->lane = 1;
	this->speed = level * 2;
	this->x = 4;
	this->y = 22;
	this->maxX = 86;
}

ListTrucks::ListTrucks(int lane, int level, int speed, int x, int y) {
	this->lane = lane;
	this->level = level;
	this->speed = speed;
	this->x = x;
	this->y = y;
	this->maxX = 86;
}

void ListTrucks::addTrucks() {
	for (int i = 0; i < level + 3; ++i) {
		Truck newTruck;
		newTruck.setCarWidth(8);
		newTruck.setX(newTruck.getX() + 20*i);
		this->listTrucks.push_back(newTruck);
	}
}


void ListTrucks::setLane(int lane) {
	this->lane = lane;
}

void ListTrucks::setLevel(int level) {
	this->level = level;
}

void ListTrucks::drawListCar() {
	UIHelper* helper = UIHelper::getUIHelper();

	for (int i = 0; i < listTrucks.size(); ++i) {
		int newX = listTrucks[i].getX() + 1;
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
		if (listTrucks[i].getX() >= this->maxX) {
			listTrucks[i].deleteCar(listTrucks[i].getX() - 1 + 8, y);
			listTrucks[i].freeMemory();
			listTrucks.erase(listTrucks.begin() + i);
			Truck newTruck;
			newTruck.setCarWidth(8);
			listTrucks.push_back(newTruck);
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
