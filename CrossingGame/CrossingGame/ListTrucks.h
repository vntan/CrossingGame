#pragma once
#include"ListCars.h"
#include"Truck.h"
#include <math.h>
#include <time.h>
#include <fstream>
#include <mutex>
class ListTrucks {
private:
	vector<Truck> listTrucks;
	int lane;
	bool direction; // 0 left->right  || 1 right->left
	int x, y;
	int maxX;
	int numberOfCars; // <= 4 
	bool redLight; // 0: green, 1: red
	int timeToRed;
	int speed;
	int level;
	void setLane(int lane);
public:
	~ListTrucks();
	ListTrucks() = default;

	void setLane(int lane);
public:
	~ListTrucks();
	/// <summary>
	/// 
	/// </summary>
	/// <param name="lane">Lane</param>
	/// <param name="direction">0 left->right  || 1 right->left</param>
	/// <param name="numberCars">Number of cars <= 4 </param>
	/// <param name="carDistance">Distance of cars:  4->6</param>
	ListTrucks(int lane, bool direction, int level);

	void addTrucks(int numberCars, int distance = 5); // start: 4->6
	
	ListTrucks(int lane, bool direction, int numberCars, int carDistance);

	void addTrucks(int numberCars, int distance = 5); // start: 4->6
	
	void setLevel(int level);
	void setDirection(bool direction);
	void setRedLight(bool redlight);
	void setTimeToRed(int timeToRed);
	void setLevel(int level);

	bool getDirection();
	int getLane();
	bool getRedLight();
	int getNumberOfCars();

	int getTimeToRed();
	int getLevel();
	int getSpeed();


	void drawListCar();
	void updateListCar();
	void deleteListCar();
	void trafficColor();
	bool isCollision(Character* character);
	void saveCar(string fileName);
	void loadCar(string fileName);
};