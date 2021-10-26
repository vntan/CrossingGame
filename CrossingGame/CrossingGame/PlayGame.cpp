#include "PlayGame.h"

void PlayGame::drawPlayGame(int gameMode) {
	drawInformation();
	//drawInputName(gameMode);
	drawTableGame();
}

void PlayGame::addNewPlayer(string name, int score) {
	Account* account = Account::getInstance();
	if (account->findUser(name) == -1) account->addAccount(name, score);
	accountPos = account->getListAccount().size();
}

bool PlayGame::getPlayer(string name) {
	Account* account = Account::getInstance();
	int index = account->findUser(name);
	if (index == -1) {
		accountPos = -1;
		return false;
	}
	else {
		accountPos = index;
		player = account->getListAccount()[index];
	}
	return true;
}

void PlayGame::drawInformation() {
	ConsoleHelper* p;

	// score board
	// length 100 - 130
	// width 2 - 9
	p->getConsoleUtilities()->setTextColor(251); // set white-cyan
	UIHelper::getUIHelper()->drawRectangle(104, 2, 16, 8, 1);
	
	// score board inside score board
	// length 103 - 119
	// width 4 - 8
	p->getConsoleUtilities()->setTextColor(240); // set white-black
	UIHelper::getUIHelper()->drawRectangle(108, 4, 9, 5);
	p->getConsoleUtilities()->gotoXY(108, 6);
	cout << (char)195;
	for (int i = 104; i < 120; i++) // middle vertical edge
		cout << (char)196;
	cout << (char)180;
	p->getConsoleUtilities()->gotoXY(116, 4);
	cout << (char)194;
	p->getConsoleUtilities()->gotoXY(116, 8);
	cout << (char)193;
	for (int i = 5; i < 8; i++) { // middle horizontal edge
		p->getConsoleUtilities()->gotoXY(116, i);
		cout << (char)179;
	}
	p->getConsoleUtilities()->gotoXY(116, 6);
	cout << (char)197; // middle

	// output word
	p->getConsoleUtilities()->gotoXY(109, 3); // name spot
	cout << "Unknown";
	p->getConsoleUtilities()->gotoXY(109, 5); // score spot
	cout << "Score:";
	p->getConsoleUtilities()->gotoXY(109, 7); // level spot
	cout << "Level:";
	p->getConsoleUtilities()->gotoXY(117, 5); // score spot
	cout << "?";
	p->getConsoleUtilities()->gotoXY(117, 7); // level spot
	cout << "?";

	// how to play board
	// length 100 - 130
	// width 11 - 20
	p->getConsoleUtilities()->setTextColor(241); // set white-deep-blue
	UIHelper::getUIHelper()->drawRectangle(104, 11, 16, 11, 1);

	// output how to play
	p->getConsoleUtilities()->setTextColor(240); // set white-black
	p->getConsoleUtilities()->gotoXY(106, 13);
	cout << "How to play: ";
	p->getConsoleUtilities()->gotoXY(108, 14);
	cout << (char)248 << " Use arrow key or A, W, ";
	p->getConsoleUtilities()->gotoXY(110, 15);
	cout << "S, D to move.";
	p->getConsoleUtilities()->gotoXY(108, 16);
	cout << (char)248 << " Press p to pause or ";
	p->getConsoleUtilities()->gotoXY(110, 17);
	cout << "resume.";
	p->getConsoleUtilities()->gotoXY(108, 18);
	cout << (char)248 << " Press r to play again ";
}

void PlayGame::drawInputName(int gameMode) {
	ConsoleHelper* p;

	// board
	// length 38 - 61
	// width 7 - 12
	p->getConsoleUtilities()->setTextColor(244); // set white-red
	UIHelper::getUIHelper()->drawRectangle(28, 7, 23, 6, 1);

	// word
	p->getConsoleUtilities()->setTextColor(240); // set white-black
	p->getConsoleUtilities()->gotoXY(40, 9);
	cout << "Input your name: ";
	p->getConsoleUtilities()->gotoXY(40, 10);
	cout << "Meo..............";
}

void PlayGame::drawTableGame() {
	ConsoleHelper* p;
	// table 
	// length 2 - 92
	// width 2 - 28
	p->getConsoleUtilities()->setTextColor(253); // set white-red
	UIHelper::getUIHelper()->drawRectangle(2, 2, 47, 27, 1);
	// draw line
	p->getConsoleUtilities()->gotoXY(2, 5);
	cout << (char)199;
	for (int i = 3; i < 95; i++)
		cout << (char)196;
	cout << (char)182;
	p->getConsoleUtilities()->gotoXY(2, 9);
	cout << (char)199;
	for (int i = 3; i < 95; i++)
		cout << (char)196;
	cout << (char)182;
	p->getConsoleUtilities()->gotoXY(2, 13);
	cout << (char)199;
	for (int i = 3; i < 95; i++)
		cout << (char)196;
	cout << (char)182;
	p->getConsoleUtilities()->gotoXY(2, 17);
	cout << (char)199;
	for (int i = 3; i < 95; i++)
		cout << (char)196;
	cout << (char)182;
	p->getConsoleUtilities()->gotoXY(2, 21);
	cout << (char)199;
	for (int i = 3; i < 95; i++)
		cout << (char)196;
	cout << (char)182;
	p->getConsoleUtilities()->gotoXY(2, 25);
	cout << (char)199;
	for (int i = 3; i < 95; i++)
		cout << (char)196;
	cout << (char)182;

	// traffic light
	trafficColor(1);
	trafficColor(2, 1);
	trafficColor(3, 1);
	trafficColor(4);
	trafficColor(5, 1);

}

void PlayGame::trafficColor(int lane, int color) {
	ConsoleHelper* p;
	p->getConsoleUtilities()->gotoXY(99, 3 + lane * 4);
	if (color == 0) 
		p->getConsoleUtilities()->setTextColor(242); // set green
	else
		p->getConsoleUtilities()->setTextColor(244); // set red 
	cout << (char)219 << (char)219;
}
