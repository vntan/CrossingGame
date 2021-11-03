#pragma once
#include "Character.h"
#include "Account.h"
#include <thread> 
#include <mutex>

class Traffic
{
	bool* isStop;
	bool* isExit;
	Character* character;
	User user;
	int accountPos;

	mutex m;
	void carInLane(int lane);
public:

	Traffic(User user, int pos);

	void startTraffic();
	void stopTraffic();
	void resetTraffic();

	void processCharacter();
};

