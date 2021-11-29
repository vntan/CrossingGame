#include"ListTrucks.h"

ListTrucks::ListTrucks(int lane, bool direction, int level) {
	setLane(lane);
	setRedLight(false);
	setDirection(direction);
	setLevel(level);
}

ListTrucks::~ListTrucks() {
	//deleteListCar();
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

void ListTrucks::setTimeToRed(int timeToRed) {
	this->timeToRed = timeToRed;
}

void ListTrucks::setLevel(int level) {
	if (level > 5) level = 5;
	this->level = level;
	// Set number of cars
	if (level <= 2) {
		this->numberOfCars = 3;
		addTrucks(numberOfCars,6);
	}
	else if (level == 3) {
		this->numberOfCars = 4;
		addTrucks(numberOfCars);
	}
	else {
		this->numberOfCars = 5;
		addTrucks(numberOfCars);
	}

	// Set level
	if (level <= 2) {
		this->speed = 100 - level * 10;
	}
	else {
		this->speed = 90 - level * 10;
	}

	// Set time to red
	if (level <= 2) {
		this->timeToRed = -1;
	}
	else {
		switch (this->level) {
		case 3: 
		case 4: {
			this->timeToRed = 80;
			break;
		}
			  
		case 5: {
			this->timeToRed = 60;
			break;
		}
		};
	}

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

int ListTrucks::getTimeToRed() {
	return this->timeToRed;
}
int ListTrucks::getLevel() {
	return this->level;
}

int ListTrucks::getSpeed() {
	return this->speed;
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
		for (int j = 0; j < 8; ++j) {
			if (direction == 0) {
				listTrucks[i].deleteCar(listTrucks[i].getX() + j, y);
			}
			else {
				listTrucks[i].deleteCar(listTrucks[i].getX() - j, y);

			}
		}
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

	UIHelper::getUIHelper()->gotoXY(99, y + 1);
	cout << (char)219 << (char)219;

	helper->setTextColor(244);
}

void ListTrucks::saveCar(string fileName) {
	fstream fout(fileName, ios::out);
	fout << lane << " " << redLight << " " << direction << " " << level << endl;
	for (int i = 0; i < listTrucks.size(); ++i) {
		fout << listTrucks[i].getX() << " ";
	}
	fout.close();
}

void ListTrucks::loadCar(string fileName) {
	fstream fin(fileName, ios::in);
	if (numberOfCars != 0) {
		for (int i = 0; i < numberOfCars; ++i) {
			listTrucks[i].freeMemory();
		}
		listTrucks.clear();
	}
	int _lane, _level;
	bool _redLight, _direction;
	fin >> _lane >> _redLight >> _direction >> _level;
	setLane(_lane);
	setRedLight(_redLight);
	setDirection(_direction);
	setLevel(_level);
	for (int i = 0; i < numberOfCars; ++i) {
		int newX;
		fin >> newX;
		if (_direction) {
			listTrucks[i].setX(newX + 1);
		} else listTrucks[i].setX(newX - 1);
	}
	drawListCar();
	fin.close();
}