#include "Character.h"

Character::Character() {
	resetCharater();
}

int Character::getX() {
	return x;
}

int Character::getY() {
	return y;
}

void Character::setX(int x) {
	deleteCharacter();
	if (x > maxX) this->x = maxX;
	else {
		if (x < minX) this->x = minX;
		else this->x = x;
	}
	drawCharacter();
}

void Character::setY(int y) {
	deleteCharacter();
	if (y > maxY) this->y = maxY;
	else {
		if (y < minY) this->y = minY;
		else this->y = y;
	}
	drawCharacter();
}

void Character::increaseX(int delta) {
	setX(x + delta);
}

void Character::increaseY(int delta) {
	setY(y + delta);
}

void Character::drawLines(int y) {
	
	
	UIHelper* helper = UIHelper::getUIHelper();
	helper->setTextColor(253);
	helper->gotoXY(3, y);
	for (int i = 3; i < 95; i++)
		cout << (char)196;

	
}

void Character::drawLanes() {
	if (y <= 5 + height || y == 4) drawLines(5);
	if (y <= 9 + height || y == 8) drawLines(9);
	if (y <= 13 + height || y == 12) drawLines(13);
	if (y <= 17 + height || y == 16) drawLines(17);
	if (y <= 21 + height || y == 20) drawLines(21);
	if (y <= 25 + height || y == 24) drawLines(25);
}

void Character::drawCharacter() {
	drawLanes();
	UIHelper* helper = UIHelper::getUIHelper();
	helper->setTextColor(helper->ColorCode_DarkRed);
	helper->gotoXY(x, y);
	cout << (char)219 << (char)219 << (char)219;
	helper->gotoXY(x + 1, y - 1);
	cout << (char)2;
}

void Character::deleteCharacter() {
	UIHelper* helper = UIHelper::getUIHelper();
	helper->gotoXY(x - 1, y);
	cout << "    ";
	helper->gotoXY(x - 1, y - 1);
	cout << "    ";
	drawLanes();
}

void Character::resetCharater(bool isDraw) {
	this->x = 43;
	this->y = 27;
	if (isDraw) drawCharacter();
}