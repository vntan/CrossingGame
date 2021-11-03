#include "MainGame.h"

int main(int argc, char* argv[]) {
	
	UIHelper::getUIHelper()->setFilePath(argv[0]);
	Account::getInstance();

	//Open the main menu.
	MainGame main;
	main.mainMenu();

	/*PlayGame playgame;
	playgame.drawPlayGame(0);*/

	return 0;
}