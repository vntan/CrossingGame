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
	bool direction;
	int x, y;
	int maxX;

public:
	ListTrucks();
	ListTrucks(int lane, int level, int speed, int y);
	void addTrucks();
	void setLane(int lane);
	void setLevel(int level);
	bool getDirection();
	int getLane();
	int getLevel();
	int getSpeed();
	void drawListCar();
	void updateListCar();
	void deleteListCar();
	//void trafficColor();
	bool isCollision(Character* character);


};