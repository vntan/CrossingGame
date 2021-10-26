#include "PlayGame.h"

PlayGame::PlayGame() {
	player = User("Unknown", -1, -1);
	accountPos = -1;
}

void PlayGame::drawPlayGame(int gameMode) {
	drawInformation();
	drawInputName(gameMode);

	UIHelper::getUIHelper()->clrscr();
	drawInformation();
	drawTableGame();

	//traffic light
	trafficColor(1);
	trafficColor(2, 1);
	trafficColor(3, 1);
	trafficColor(4);
	trafficColor(5, 1);
	
	while (true);

	
	
}

bool PlayGame::addNewPlayer(string name, int score) {
	Account* account = Account::getInstance();
	if (account->findUser(name) == -1) {
		account->addAccount(name, score);
		accountPos = account->getListAccount().size() - 1;
		player = account->getInstance()->getAccount(accountPos);
		return true;
	}
	return false;
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
	UIHelper* console = UIHelper::getUIHelper();

	console->showConsoleCursor(false);
	// score board
	// length 100 - 130
	// width 2 - 9
	console->setTextColor(251); // set white-cyan
	UIHelper::getUIHelper()->drawRectangle(104, 2, 16, 8, 1);
	
	// score board inside score board
	// length 103 - 119
	// width 4 - 8
	console->setTextColor(240); // set white-black
	UIHelper::getUIHelper()->drawRectangle(108, 4, 9, 5);
	console->gotoXY(108, 6);
	cout << (char)195;
	for (int i = 104; i < 120; i++) // middle vertical edge
		cout << (char)196;
	cout << (char)180;
	console->gotoXY(116, 4);
	cout << (char)194;
	console->gotoXY(116, 8);
	cout << (char)193;
	for (int i = 5; i < 8; i++) { // middle horizontal edge
		console->gotoXY(116, i);
		cout << (char)179;
	}
	console->gotoXY(116, 6);
	cout << (char)197; // middle

	// output word
	console->gotoXY(109, 3); // name spot
	cout << player.getName();
	console->gotoXY(109, 5); // score spot
	cout << "Score:";
	console->gotoXY(109, 7); // level spot
	cout << "Level:";
	console->gotoXY(117, 5); // score spot
	if (player.getScore() > 0) cout << player.getScore(); else cout << "?";
	console->gotoXY(117, 7); // level spot
	if (player.getLevel() > 0) cout << player.getLevel(); else cout << "?";

	// how to play board
	// length 100 - 130
	// width 11 - 20
	console->setTextColor(241); // set white-deep-blue
	UIHelper::getUIHelper()->drawRectangle(104, 11, 16, 11, 1);

	// output how to play
	console->setTextColor(240); // set white-black
	console->gotoXY(106, 13);
	cout << "How to play: ";
	console->gotoXY(108, 14);
	cout << (char)248 << " Use arrow key or A, W, ";
	console->gotoXY(110, 15);
	cout << "S, D to move.";
	console->gotoXY(108, 16);
	cout << (char)248 << " Press p to pause or ";
	console->gotoXY(110, 17);
	cout << "resume.";
	console->gotoXY(108, 18);
	cout << (char)248 << " Press r to play again ";
}

void PlayGame::drawInputName(int gameMode) {
	UIHelper* console = UIHelper::getUIHelper();

	// board
	// length 38 - 61
	// width 7 - 12
	console->setTextColor(244); // set white-red
	UIHelper::getUIHelper()->drawRectangle(28, 7, 23, 6, 1);

	// word
	console->setTextColor(240); // set white-black
	char c = ' '; string name = "";

	do {
		console->showConsoleCursor(false);
		console->gotoXY(35, 9);

		
		if (!name.empty()) cout << "Input your name again: ";
		else cout << "Input your name: ";
		console->gotoXY(35, 10);
		for (int i = 0; i < name.length(); i++) cout << " ";
		name = ""; c = ' ';
		console->gotoXY(35, 10);
		console->showConsoleCursor(true);
		while (c != '\n') {
			c = getchar();
			if (c!= '\n') name += c;
		}
		
		console->showConsoleCursor(false);
		if (gameMode == 0 && addNewPlayer(name)) break;
		if (gameMode != 0 && getPlayer(name)) break;

	} while (true);
}

void PlayGame::drawTableGame() {
	UIHelper* console = UIHelper::getUIHelper();
	console->showConsoleCursor(false);
	// table 
	// length 2 - 92
	// width 2 - 28
	console->setTextColor(253); // set white-red
	UIHelper::getUIHelper()->drawRectangle(2, 2, 47, 27, 1);
	// draw line
	console->gotoXY(2, 5);
	cout << (char)199;
	for (int i = 3; i < 95; i++)
		cout << (char)196;
	cout << (char)182;
	console->gotoXY(2, 9);
	cout << (char)199;
	for (int i = 3; i < 95; i++)
		cout << (char)196;
	cout << (char)182;
	console->gotoXY(2, 13);
	cout << (char)199;
	for (int i = 3; i < 95; i++)
		cout << (char)196;
	cout << (char)182;
	console->gotoXY(2, 17);
	cout << (char)199;
	for (int i = 3; i < 95; i++)
		cout << (char)196;
	cout << (char)182;
	console->gotoXY(2, 21);
	cout << (char)199;
	for (int i = 3; i < 95; i++)
		cout << (char)196;
	cout << (char)182;
	console->gotoXY(2, 25);
	cout << (char)199;
	for (int i = 3; i < 95; i++)
		cout << (char)196;
	cout << (char)182;
}

void PlayGame::trafficColor(int lane, int color) {
	UIHelper* console = UIHelper::getUIHelper();
	console->gotoXY(99, 3 + lane * 4);
	if (color == 0) 
		console->setTextColor(242); // set green
	else
		console->setTextColor(244); // set red 
	cout << (char)219 << (char)219;
}
