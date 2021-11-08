#pragma once
#include"ListCars.h"
#include"Truck.h"
class ListTrucks {
private:
	vector<Truck> listTrucks;
	int lane;
	int level;
	int speed;
	int x, y;
	int maxX;

public:
	ListTrucks();
	ListTrucks(int lane, int level, int speed, int x, int y);
	void addTrucks();
	void setLane(int lane);
	void setLevel(int level);
	void drawListCar();
	void updateListCar();
	void deleteListCar();
	//void trafficColor();
	bool isCollision(Character* character);


};