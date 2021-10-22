#pragma once
#include "MainGame.h"

class PlayGame
{
private:
	int gameMode;
	Account* account;
	int accountPosition = -1;
	User player;
private:
	void addNewPlayer(string name, int score);
	bool getPlayer(string name);

	void drawInformation();
	void drawInputName(int gameMode);
	void drawTableGame();
	//void processGame();

public:
	PlayGame(int gameMode);
	void drawPlayGame(int gameMode);
};

