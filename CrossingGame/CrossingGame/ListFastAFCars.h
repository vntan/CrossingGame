#include "FastAFCar.h"
#include "ListCars.h"
#include "Character.h"

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
	int turncount;
	bool reverse;
public: 
	~ListFastAFCars();
	ListFastAFCars();
	void addCars(int n);
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