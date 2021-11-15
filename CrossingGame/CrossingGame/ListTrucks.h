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
	bool redLight; // 0: green, 1: red
public:
	ListTrucks();
	~ListTrucks();
	ListTrucks(int lane, int level);
	ListTrucks(int lane, int level,bool direction, int y);
	void addTrucks(int numberOfCars, int start);
	void setLane(int lane);
	void setLevel(int level);
	void setDirection(bool direction);
	void setNumberOfCars(int numberOfCars);
	void setRedLight(bool redlight);

	bool getDirection();
	int getLane();
	int getLevel();
	bool getRedLight();
	int getNumberOfCars();
	int getSpeed();
	void drawListCar();
	void updateListCar();
	void deleteListCar();
	void trafficColor();
	bool isCollision(Character* character);


};