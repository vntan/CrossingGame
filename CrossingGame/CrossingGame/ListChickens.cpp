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
	if (this->direction = true) {
		this->lane = lane;
		this->level = level;
		this->redLight = true;
		this->numberOfChicks = 0;
		setLane(lane);
		x = 5;
	}
	else {
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
	//deleteListCar();
	for (int i = 0; i < listChicken.size(); ++i) {
		listChicken[i].deleteMemory();
	}
	listChicken.resize(0);
}
void ListChickens::setLane(int lane) {
	this->lane = lane;
	y = 26 - (lane * 4);
}
void ListChickens::setLevel(int level)
{
	this->level = level;
}
void ListChickens::setAddChicken() {
	if (level < 5 && level >= 1) {
		this->numberOfChicks = 2;
		addChicken(numberOfChicks, 5);
	}
	else if (level < 15 && level >= 5) {
		this->numberOfChicks = 3;
		addChicken(numberOfChicks, 5);
	}
	else if (level >= 15) {
		this->numberOfChicks = 4;
		addChicken(numberOfChicks, 5);
	}
}
int ListChickens::RedLight() {
	if (level < 5 && level >= 1) {
		return 10;
	}
	else if (level < 15 && level >= 5) {
		return 15;
	}
	else {
		return 20;
	}
}
void ListChickens::addTimeDelay() {
	if (level > 9) {
		Sleep(100);
	}
	else {
		Sleep(300 - level * 5);
	}

}
void ListChickens::saveToFile(string filePath) {
	fstream f;
	f.open(filePath, ios::out);
	f << numberOfChicks << " " << lane << " " << direction << " " << level << " " << redLight << endl;

	for (int i = 0; i < listChicken.size(); ++i) {
		f << listChicken[i].getX() << " " << listChicken[i].getY() << " ";
	}
	f.close();
}
void ListChickens::loadFromFile(string filePath) {
	fstream f;
	f.open(filePath, ios::in);
	int num, la, le;
	bool di, red;
	f >> num >> la >> di >> le >> red;
	setNumChicks(num);
	setLane(la);
	setDirection(di);
	setLevel(le);
	setRedlight(red);

	for (int i = 0; i < listChicken.size(); ++i) {
		int x, y;
		f >> x;
		f >> y;
		listChicken[i].setX(x);
		listChicken[i].setY(y);
	}
	drawListCar();
	updateListCar();
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
	UIHelper* helper = UIHelper::getUIHelper();
	for (int i = 0; i < listChicken.size(); ++i) {
		listChicken[i].deleteCar(listChicken[i].getX(), y);
	}
}

void ListChickens::updateListCar() {
	for (int i = 0; i < listChicken.size(); ++i) {
		if (direction == true) {
			if (listChicken[i].getX() > this->maxX || listChicken[i].getX() < this->x) {
				listChicken[i].deleteCar(listChicken[i].getX(), y);
				listChicken[i].deleteMemory();
				listChicken.erase(listChicken.begin() + i);
				Chicken chick(x, y, direction);
				chick.setCarWidth(6);
				listChicken.push_back(chick);
			}
		}
		else {
			if (listChicken[i].getX() < this->maxX) {
				listChicken[i].deleteCar(listChicken[i].getX(), y);
				listChicken[i].deleteMemory();
				listChicken.erase(listChicken.begin() + i);
				Chicken chick(x, y, direction);
				chick.setCarWidth(6);
				chick.drawReverseChick();
				listChicken.push_back(chick);
			}
		}
	}
}

bool ListChickens::isCollision(Character* character) {
	for (int i = 0; i < listChicken.size(); ++i) {
		if (direction == true) {
			if (listChicken[i].getX() <= character->getX() && listChicken[i].getX() + 5 >= character->getX() && character->getY() >= y && character->getY() <= y + 3) {
				return true;
			}
		}
		else {
			if (listChicken[i].getX() >= character->getX() && listChicken[i].getX() - 5 <= character->getX() && character->getY() >= y && character->getY() <= y + 3) {
				return true;
			}
		}
	}
	return false;
}

void ListChickens::trafficColor() {
	UIHelper* helper = UIHelper::getUIHelper();
	UIHelper::getUIHelper()->gotoXY(99, 4 * (7 - lane) - 1);

	if (redLight) {
		UIHelper::getUIHelper()->setTextColor(250); // red
		cout << (char)219 << (char)219;
	}
	else {
		UIHelper::getUIHelper()->setTextColor(252); // green
		cout << (char)219 << (char)219;
	}
}
void ListChickens::deleteEverything() {
	UIHelper* p;
	p->getUIHelper()->gotoXY(3, this->y);
	cout << "                                                                                    ";
	p->getUIHelper()->gotoXY(3, this->y + 1);
	cout << "                                                                                    ";
	p->getUIHelper()->gotoXY(3, this->y + 2);
	cout << "																				     ";
}