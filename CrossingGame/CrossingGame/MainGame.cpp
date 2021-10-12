#include "MainGame.h"

void MainGame::mainMenu() {
	UIHelper::getUIHelper()->drawHeaderText();
	int maxX = ConsoleHelper::getConsoleUtilities()->getMaxX();
	int maxY = ConsoleHelper::getConsoleUtilities()->getMaxY();
	vector<string> menuNames{ "New game", "Load game", "High Score", "About", "Quit Game" };

	int choice = UIHelper::getUIHelper()->createMenu(maxX/2 - 6, maxY/2, menuNames);

	switch (choice)
	{
	case 0:
		//New Game
		break;
	case 1:
		//Load Game
		break;
	case 2:
		//High Score
		ConsoleHelper::getConsoleUtilities()->clrscr();
		HighScore highScore; highScore.drawUI();
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
		ConsoleHelper::getConsoleUtilities()->clrscr();
		exit(0);
		break;
	default:
		break;
	}
}