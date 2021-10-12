#include <iostream>
#include "ConsoleHelper.h"
#include "UIHelper.h"
#include "MainGame.h"

using namespace std;

int main(int argc, char* argv[]) {
	ConsoleHelper::getConsoleUtilities();
	UIHelper::getUIHelper();

	ConsoleHelper::getConsoleUtilities()->setFilePath(argv[0]);
	
	//Open the main menu.
	MainGame main;
	main.mainMenu();

	return 0;
}