#pragma once
#include "ListCars.h"

class ListRedCar : public ListCars
{
	int lane, level;
	int x, y;
	bool flag;
	int count, numberOfCar;
	RedCar r[6];
public:
	void setLane(int lane);
	void setLevel(int level);
	int getSleep();
	void drawListCar();
	void updateListCar();
	void deleteListCar();
	void trafficColor();
	bool isCollision(Character* character);
};