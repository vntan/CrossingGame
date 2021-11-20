#pragma once
#include"ListCars.h"
#include"Truck.h"
#include <math.h>
#include <time.h>
#include<fstream>
#include<mutex>

struct InfoStorage {
	int lane, numberOfCars, level, count;
	bool direction, redLight;
	int allX[20];
	InfoStorage() = default;
	InfoStorage(int lane, int numberOfCars, int level, bool direction, bool redLight, int allX[], int count) {
		this->lane = lane;
		this->numberOfCars = numberOfCars;
		this->level = level;
		this->direction = direction;
		this->redLight = redLight;
		for (int i = 0; i < numberOfCars; ++i) {
			this->allX[i] = allX[i];
		}
		this->count = count;
	}
};

class ListTrucks {
private:
	static vector<InfoStorage> allListTrucks;
	vector<Truck> listTrucks;
	int lane;
	int level;
	int speed;
	bool direction; // 0 left->right  || 1 right->left
	int x, y;
	int maxX;
	int numberOfCars; // <= 4 
	bool redLight; // 0: green, 1: red
	int count;

public:
	ListTrucks();
	~ListTrucks();
	ListTrucks(int lane, int level);
	ListTrucks(int lane, int level,bool direction, int y);

	void addTrucks(int numberOfCars, int start);
	void setStorage();
	void clearStorage();
	
	void setLane(int lane);
	void setLevel(int level);
	void setDirection(bool direction);
	void setNumberOfCars(int numberOfCars);
	void setRedLight(bool redlight);
	void setCount(int count);

	bool getDirection();
	int getCount();
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
	void saveTrucks(string fileName);
	void loadTrucks(string fileName, int cLane = -1);

};



