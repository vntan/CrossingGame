#include "MainGame.h"

void MainGame::mainMenu() {
	UIHelper::getUIHelper()->drawHeaderText();
	int maxX = ConsoleHelper::getConsoleUtilities()->getMaxX();
	int maxY = ConsoleHelper::getConsoleUtilities()->getMaxY();
	vector<string> menuNames{ "New game", "Load game", "High Score", "About", "Quit Game" };

	int choice = UIHelper::getUIHelper()->createMenu(maxX/2 - 6, maxY/2, menuNames);
	PlayGame playGame; 
	
	switch (choice)
	{
	case 0:
		//New Game
        ConsoleHelper::getConsoleUtilities()->clrscr();
		playGame.drawPlayGame(0);
		mainMenu();
		break;
	case 1:
		//Load Game
		ConsoleHelper::getConsoleUtilities()->clrscr();
		playGame.drawPlayGame(1);
		mainMenu();
		break;
	case 2:
		//High Score
		ConsoleHelper::getConsoleUtilities()->clrscr();
		//HighScore highScore; highScore.drawUI();
		mainMenu();
		break;
	case 3:
		//About
		ConsoleHelper::getConsoleUtilities()->clrscr(); 
		About about; about.drawUI();
		mainMenu();
		break;
	case 4:
		//Quit Game
		Account::getInstance()->saveAccountToFile();
		ConsoleHelper::getConsoleUtilities()->clrscr();
		system("F0");
		exit(0);
		break;
	default:
		break;
	}
}
