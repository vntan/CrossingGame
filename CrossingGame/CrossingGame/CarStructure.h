#pragma once
#include <iostream>
#include "UIHelper.h"
#include <vector>

class CarStructure
{
protected:
	int width;
public:
	virtual void setCarWidth(int width) = 0;
	virtual void drawCar(int x, int y) = 0;
	virtual void deleteCar(int x, int y) = 0;
};

