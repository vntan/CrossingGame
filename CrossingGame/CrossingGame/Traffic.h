#pragma once
#include "Character.h"
#include "Account.h"
#include "ListFastAFCars.h"
#include <thread> 
#include <mutex>
#include "Truck.h"
#include <thread> 
#include <mutex>
#include "ListTrucks.h"
#include"ListChickens.h"

#include <stdlib.h>     /* srand, rand */


class Traffic
{
	bool* isStop;
	bool* isExit;
	Character* character;
	User user;
	int accountPos;

	mutex m;
	void carInLane(int lane);
	void truckCarProcess(int lane);
	void fastAFCarProcess(int lane);
	void chickenProcess(int lane);
public:

	Traffic(User user, int pos);

	void startTraffic();
	void stopTraffic();
	void resetTraffic();

	void processCharacter();
};

