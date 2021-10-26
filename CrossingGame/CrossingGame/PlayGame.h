#pragma once
#include "MainGame.h"
#include "User.h"
#include "ConsoleHelper.h"

class PlayGame
{
private:
	int accountPos = -1;
	int gameMode;
	User player;
private:
	void addNewPlayer(string name, int score);
	bool getPlayer(string name);
	void trafficColor(int lane, int color = 0); // lane = {1, 2, 3, 4, 5}; 0 = deep green, others = red;
	void drawInformation();
	void drawInputName(int gameMode);
	void drawTableGame();
	//void processGame();

public:
	void drawPlayGame(int gameMode);
};

