#pragma once
#include"CarStructure.h"
class Truck : public CarStructure {
private:
	char** car;
	int x, y;
public:
	Truck();
	Truck(int x, int y);
	void setCarWidth(int width);
	void drawCar(int x, int y);
	void deleteCar(int x, int y);
	void reverseShapeCar();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void freeMemory();
	//~Truck();
};