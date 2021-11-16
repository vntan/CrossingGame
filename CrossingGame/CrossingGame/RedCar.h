#pragma once
#include "CarStructure.h"

class RedCar: public CarStructure
{
public:
	int carX, carY;
public:
	void setCarWidth(int width);
	void drawCar(int x, int y);
	void deleteCar(int x, int y);
};

