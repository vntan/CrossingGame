#include "FastAFCar.h"
#include "ListCars.h"
#include "Character.h"

class ListFastAFCars : public ListCars {
private:
	FastAFCar car;
	int posX;
	int posY;
	int lane;
	int level;
	bool stop;
	int turncount;
	bool firstdraw;
	int countstep;
	bool reverse;
public: 
	ListFastAFCars();
	void resetStatus();
	int getSleepTime();
	void setLane(int lane);
	void setLevel(int level);
	void drawListCar();
	void updateListCar();
	void deleteListCar();
	void drawListCarReverse();
	void deleteListCarReverse();
	void trafficColor();
	bool isCollision(Character* character);
};