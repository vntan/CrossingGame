#include "FastAFCar.h"
#include "ListCars.h"
#include "Character.h"
#include <fstream>

class ListFastAFCars : public ListCars {
private:
	FastAFCar* car;
	int *posX;
	int *countstep;
	bool *firstdraw;
	int posY;
	int numofcars;
	int lane;
	int level;
	bool stop;
	bool reverse;
	int distance;
	bool isRed;
public: 
	~ListFastAFCars();
	ListFastAFCars();
	void saveCar();
	void loadCar();
	void setTraffic(bool isRed);
	bool getTraffic();
	void setStop(bool stop);
	void addCars(int n, int distance);
	void resetStatus();
	int getSleepTime();
	void setLane(int lane);
	void setLevel(int level);
	void drawListCar(int i);
	void drawListCar();
	void updateListCar();
	void deleteListCar();
	void deleteListCar(int i);
	void drawListCarReverse(int i);
	void deleteListCarReverse(int i);
	void trafficColor();
	bool isCollision(Character* character);
};