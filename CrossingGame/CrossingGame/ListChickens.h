#pragma once
#include "ListCars.h"
#include "Chicken.h"
#include<fstream>
#include<vector>
class ListChickens : public ListCars {
	vector<Chicken> listChicken;
	int lane;
	bool direction;
	int x, y;
	int level;
	int maxX;
	int numberOfChicks;
	bool redLight;

public:
	ListChickens();
	ListChickens(int lane, int level);
	void drawListCar();
	void updateListCar();
	void deleteListCar();
	void trafficColor();
	bool isCollision(Character* character);
	void addChicken(int numChicks, int distance);
	bool getDirection();
	void setDirection(bool direction);
	void setRedlight(bool redlight);
	bool getRedlight();
	void setNumChicks(int numchicks);
	int getNumChicks();
	int getLane();
	void setLane(int lane);
	void setLevel(int level);
	int getLevel();
	void setAddChicken();
	int RedLight();
	void addTimeDelay();
	void saveToFile(string filePath);
	void loadFromFile(string filePath);
	~ListChickens();
};


