#include "ListChickens.h"
ListChickens::ListChickens() {
	srand(time(NULL));
	if (rand() % 2 == 1) {
		this->direction = true;
		this->lane = 1;
		this->level = 1;
		this->redLight = true;
		this->numberOfChicks = 0;
		setLane(lane);
		x = 5;
	}
	else {
		this->direction = false;
		this->lane = 1;
		this->level = 1;
		this->redLight = true;
		this->numberOfChicks = 0;
		setLane(lane);
		x = 85;
	}
}
ListChickens::ListChickens(int lane, int level) {
	srand(time(NULL));
	if (rand() % 2 == 1) {
		this->direction = true;
		this->lane = lane;
		this->level = level;
		this->redLight = true;
		this->numberOfChicks = 0;
		setLane(lane);
		x = 5;
	}
	else{
		this->direction = false;
		this->lane = lane;
		this->level = level;
		this->redLight = true;
		this->numberOfChicks = 0;
		setLane(lane);
		x = 85;
	}
}
ListChickens::~ListChickens() {
	deleteListCar();
	for (int i = 0; i < listChicken.size(); ++i) {
		listChicken[i].deleteMemory();
	}
}
void ListChickens::setLane(int lane) {
	this->lane = lane;
	y = 26 - (lane * 4);
}
void ListChickens::setLevel(int level)
{
	this->level = level;
}
int ListChickens::getLane() {
	return this->lane;
}
int ListChickens::getLevel() {
	return this->level;
}
void ListChickens::addChicken(int numChicks, int distance) {
	this->numberOfChicks = numChicks;
	distance = 5;
	for (int i = 0; i < numChicks; ++i) {
		Chicken chick;
		if (direction == true) {
			chick.setX(x + (distance + 15) * i);
			chick.setY(y);
		}
		else {
			chick.setX(x - (distance + 15) * i);
			chick.setY(y);
			chick.drawReverseChick();
		}
		chick.setCarWidth(6);
		chick.setDirect(direction);
		this->listChicken.push_back(chick);
	}
}

bool ListChickens::getDirection() {
	return this->direction;
}

void ListChickens::setDirection(bool direction) {
	this->direction = direction;
	if (direction == true) {
		this->x = 5;
		this->maxX = 86;
	}
	else {
		this->x = 86;
		this->maxX = 5;
	}
}

void ListChickens::setRedlight(bool redlight) {
	this->redLight = redlight;
}
bool ListChickens::getRedlight() {
	return this->redLight;
}
void ListChickens::setNumChicks(int numchicks) {
	this->numberOfChicks = numchicks;
}
int ListChickens::getNumChicks() {
	return this->numberOfChicks;
}

void ListChickens::drawListCar() {
	for (int i = 0; i < listChicken.size(); ++i) {
		if (this->direction == true) {
			listChicken[i].drawCar(listChicken[i].getX() + 1, y);
		}
		else {
			listChicken[i].drawCar(listChicken[i].getX() - 1, y);
		}
	}
}
void ListChickens::deleteListCar() {
	for (int i = 0; i < listChicken.size(); ++i) {
		listChicken[i].deleteCar(listChicken[i].getX(), y);
	}
}
void ListChickens::updateListCar() {
	for (int i = 0; i < listChicken.size(); ++i) {
		if (direction == true) {
			if (listChicken[i].getX() > this->maxX  || listChicken[i].getX() < this->x) {
				listChicken[i].deleteCar(listChicken[i].getX(),y);
				
				listChicken.erase(listChicken.begin() + i);
				Chicken chick(x, y, direction);
				chick.setCarWidth(6);
				listChicken.push_back(chick);
			}
		}
		else {
			if (listChicken[i].getX() < this->maxX ) {
				listChicken[i].deleteCar(listChicken[i].getX(), y);
				
				listChicken.erase(listChicken.begin() + i);
				Chicken chick(listChicken[i].getX(), y, direction);
				chick.drawReverseChick();
				chick.setCarWidth(6);
				listChicken.push_back(chick);
			}
		}
	}
}
bool ListChickens::isCollision(Character* character) {
	for (int i = 0; i < listChicken.size(); ++i) {
		if (listChicken[i].getX() >= character->getX() && listChicken[i].getX() <= character->getX() + 5 && character->getY() >= y && character->getY() <= y + 3) {
			return true;
		}
	}
	return false;
}

void ListChickens::trafficColor() {
	UIHelper* helper = UIHelper::getUIHelper();


	if (redLight == true) {
		helper->setTextColor(250);
	}
	else {
		helper->setTextColor(252);

	}
	if (direction == true) {
		helper->gotoXY(maxX + 11, y);
	}
	else {
		helper->gotoXY(maxX - 3, y);
	}
	cout << (char)254;
	helper->setTextColor(244);
}