#pragma once
#include "Character.h"
#include "ListRedCar.h"
#include "Account.h"
#include "ListFastAFCars.h"
#include "ListChickens.h"
#include <thread> 
#include <mutex>
#include "Truck.h"
#include <thread> 
#include <mutex>
#include "ListTrucks.h"
#include <fstream>

#include <stdlib.h>     /* srand, rand */


class Traffic
{
	bool isStop;
	bool isExit;
	bool isSave;
	bool isLoad;

	string result;

	Character* character;
	User user;

	mutex m;
	void carInLane(int lane);
	void redCarProcess(int lane);
	void truckCarProcess(int lane);
	void fastAFCarProcess(int lane);
	void chickenProcess(int lane);
	
	void saveUser();
public:
	Traffic(User user, bool isContinue);
	~Traffic();

	string startTraffic();
	void stopTraffic();
	//void resetTraffic();

	void processCharacter();
};

