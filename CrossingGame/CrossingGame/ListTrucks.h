#pragma once
#include"ListCars.h"
#include"Truck.h"
#include <math.h>
#include <time.h>
class ListTrucks {
private:
	vector<Truck> listTrucks;
	int lane;
	int level;
	int speed;
	bool direction; // 0 left->right  || 1 right->left
	int x, y;
	int maxX;
	int numberOfCars; // <= 4 

public:
	ListTrucks();
	ListTrucks(int lane, int level, int y, int numberOfCars = 4);
	ListTrucks(int lane, int level,bool direction, int numberOfCars, int y);
	void addTrucks();
	void setLane(int lane);
	void setLevel(int level);
	void setDirection(bool direction);
	void setNumberOfCars(int numberOfCars);
	bool getDirection();
	int getLane();
	int getLevel();
	int getNumberOfCars();
	int getSpeed();
	void drawListCar();
	void updateListCar();
	void deleteListCar();
	//void trafficColor();
	bool isCollision(Character* character);


};