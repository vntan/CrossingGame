#pragma once
#include "CarStructure.h"
class Chicken : public CarStructure
{
	char** chick;
	int x, y;
	bool direction;
public:
	void setCarWidth(int width);
	void drawCar(int x, int y);
	void deleteCar(int x, int y);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void setDirect(bool direct);
	Chicken();
	Chicken(int x, int y, bool direct);
	void drawReverseChick();
	void deleteMemory();
};


