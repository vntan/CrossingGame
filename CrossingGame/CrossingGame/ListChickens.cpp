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
void ListChickens::setAddChicken(int level) {
	if (level < 5 && level >= 1) {
		addChicken(2, 5);
	}
	else if (level < 15 && level >= 5) {
		addChicken(3, 5);
	}
	else {
		addChicken(4, 5);
	}
}
int ListChickens::RedLight(int level) {
	if (level < 5 && level >= 1) {
		return 20;
	}
	else if (level < 15 && level >= 5) {
		return 30;
	}
	else {
		return 40;
	}
}
void ListChickens::addTimeDelay(int level) {
	if (level > 9) {
		Sleep(100);
	}
	else {
		Sleep(1000 - level * 100);
	}
	
}
void ListChickens::saveToFile() {
	fstream f;
	f.open("game.txt", ios::out);
	f << numberOfChicks << endl;
	f << lane << endl;
	f << direction << endl;
	f << level << endl;
	f << redLight;
	for (int i = 0; i < listChicken.size(); ++i) {
			f << listChicken[i].getX() << " " << listChicken[i].getY();
	}
	f.close();
}
void ListChickens::loadFromFile(){
	fstream f;
	f.open("game.txt", ios::in);
	f >> numberOfChicks ;
	cout << endl;
	f >> lane ;
	cout << endl;
	f >> direction;
	cout << endl;
	f >> level;
	cout << endl;
	f >> redLight;
	int x, y;
	for (int i = 0; i < listChicken.size(); ++i) {
		f >> x;
		cout << " ";
		f >> y;
		listChicken[i].setX(x);
		listChicken[i].setY(y);
		addChicken(numberOfChicks, 5);
	}
	f.close();
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
		if (this->direction == true) {
			chick.setX(x + (distance + 17) * i);
			chick.setY(y);
		}
		else {
			chick.setX(x - (distance + 17) * i);
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

	if (redLight) {
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