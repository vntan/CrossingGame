#pragma once
#include "ListCars.h"

class ListRedCar : public ListCars
{
private:
	int lane, level;
	int x, y;
	bool flag;
	int count, numberOfCar, maxCar;
	RedCar *r;
	bool redLight;
	int timeRedLight;
	int space;
	bool isReverse;
public:
	void setLane(int lane);
	void setLevel(int level);
	int getSleep();
	void drawListCar();
	void updateListCar();
	void deleteListCar();
	void setRedLight(bool redLight);
	bool getRedLight();
	void trafficColor();
	bool isCollision(Character* character);
	int getTimeRedLight();
	void loadCar(string nameFile);
	void saveCar(string nameFile);
	void setDirection(bool isReverse);
};