﻿#include "MainGame.h"

int main(int argc, char* argv[]) {
	srand(time(NULL));
	UIHelper::getUIHelper()->setFilePath(argv[0]);
	Account::getInstance();

	//Open the main menu.
	MainGame main;
	main.mainMenu();

	delete UIHelper::getUIHelper();
	delete Account::getInstance();
	return 0;
}