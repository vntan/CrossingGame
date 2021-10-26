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

	void drawInformation();
	void drawInputName(int gameMode);
	void drawTableGame();
	void drawFrame();
	//void processGame();

public:
	void drawPlayGame(int gameMode);
};

