#include "MainGame.h"

void MainGame::mainMenu() {
	UIHelper* console = UIHelper::getUIHelper();
	console->clrscr();
	console->drawHeaderText();
	int maxX = console->getMaxX();
	int maxY = console->getMaxY();
	vector<string> menuNames{ "New game", "Load game", "High Score", "About", "Quit Game" };

	int choice = UIHelper::getUIHelper()->createMenu(maxX/2 - 6, maxY/2, menuNames);
	PlayGame playGame; 
	
	switch (choice)
	{
	case 0:
		//New Game
        console->clrscr();
		playGame.drawPlayGame(0);
		mainMenu();
		break;
	case 1:
		//Load Game
		console->clrscr();
		playGame.drawPlayGame(1);
		mainMenu();
		break;
	case 2:
		//High Score
		console->clrscr();
		HighScore highScore; highScore.drawUI();
		mainMenu();
		break;
	case 3:
		//About
		console->clrscr(); 
		About about; about.drawUI();
		mainMenu();
		break;
	case 4:
		//Quit Game
		Account::getInstance()->saveAccountToFile();
		console->clrscr();
		system("color F0");
		exit(0);
		break;
	default:
		break;
	}
}
