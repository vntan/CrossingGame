#pragma once
#include "CarStructure.h"

class RedCar: public CarStructure
{
public:
	int carX, carY;
	bool isReverse;
public:
	void setCarWidth(int width);
	void drawCar(int x, int y);
	void deleteCar(int x, int y);
};

