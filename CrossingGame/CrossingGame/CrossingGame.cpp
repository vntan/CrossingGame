#include "MainGame.h"

int main(int argc, char* argv[]) {
	ConsoleHelper::getConsoleUtilities();
	UIHelper::getUIHelper();

	ConsoleHelper::getConsoleUtilities()->setFilePath(argv[0]);
	Account::getInstance();

	//Open the main menu.
	MainGame main;
	main.mainMenu();

	return 0;
}