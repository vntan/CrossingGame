#pragma once
#include "Character.h"
#include "Account.h"

#include <thread> 
#include <mutex>
#include <time.h>
#include <thread> 
#include <mutex>

#include "ListFastAFCars.h"
#include "ListTrucks.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

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
public:

	Traffic(User user, int pos);

	void startTraffic();
	void stopTraffic();
	void resetTraffic();

	void processCharacter();
};

