#include "PlayGame.h"

void PlayGame::drawPlayGame(int gameMode) {
	drawFrame();
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

void PlayGame::drawFrame() {
	// length 0 - 136
	// width 0 - 30
	ConsoleHelper* p;
	p->getConsoleUtilities()->setTextColor(244); // set white-red
	p->getConsoleUtilities()->gotoXY(0, 0);
	cout << (char)218; // top left corner
	for (int i = 1; i < 136; i++) // top edge
		cout << (char)196;
	cout << (char)191; // top right corner
	for (int i = 1; i < 30; i++) { // right edge
		p->getConsoleUtilities()->gotoXY(136, i);
		cout << (char)179;
	}
	for (int i = 1; i < 30; i++) { // left edge
		p->getConsoleUtilities()->gotoXY(0, i);
		cout << (char)179;
	}
	p->getConsoleUtilities()->gotoXY(0, 30);
	cout << (char)192; // bottom left corner
	for (int i = 1; i < 136; i++) // bottom edge
		cout << (char)196;
	cout << (char)217; // bottom right corner
}

void PlayGame::drawInformation() {
	ConsoleHelper* p;

#pragma region Score board
	// score board
	// length 100 - 130
	// width 2 - 9
	p->getConsoleUtilities()->setTextColor(241); // set white-deep-blue
	p->getConsoleUtilities()->gotoXY(100, 2);
	cout << (char)201; // top left corner
	for (int i = 101; i < 130; i++) // top edge
		cout << (char)205;
	cout << (char)187; // top right corner
	for (int i = 3; i < 9; i++) { // right edge
		p->getConsoleUtilities()->gotoXY(130, i);
		cout << (char)186;
	}
	for (int i = 3; i < 9; i++) { // left edge
		p->getConsoleUtilities()->gotoXY(100, i);
		cout << (char)186;
	}
	p->getConsoleUtilities()->gotoXY(100, 9);
	cout << (char)200; // bottom left corner
	for (int i = 101; i < 130; i++) // bottom edge
		cout << (char)205;
	cout << (char)188; // bottom right corner
#pragma endregion
	
#pragma region Score board inside score board
	// score board inside score board
	// length 103 - 119
	// width 4 - 8
	p->getConsoleUtilities()->setTextColor(240); // set white-black
	p->getConsoleUtilities()->gotoXY(103, 4);
	cout << (char)218; // top left corner
	for (int i = 104; i < 119; i++) // top edge
		cout << (char)196;
	cout << (char)191; // top right corner
	for (int i = 5; i < 8; i++) { // right edge
		p->getConsoleUtilities()->gotoXY(119, i);
		cout << (char)179;
	}
	for (int i = 5; i < 8; i++) { // left edge
		p->getConsoleUtilities()->gotoXY(103, i);
		cout << (char)179;
	}
	p->getConsoleUtilities()->gotoXY(103, 8);
	cout << (char)192; // bottom left corner
	for (int i = 104; i < 119; i++) // bottom edge
		cout << (char)196;
	cout << (char)217; // bottom right corner
	p->getConsoleUtilities()->gotoXY(103, 6);
	cout << (char)195;
	for (int i = 104; i < 119; i++) // middle vertical edge
		cout << (char)196;
	cout << (char)180;
	p->getConsoleUtilities()->gotoXY(111, 4);
	cout << (char)194;
	p->getConsoleUtilities()->gotoXY(111, 8);
	cout << (char)193;
	for (int i = 5; i < 8; i++) { // middle horizontal edge
		p->getConsoleUtilities()->gotoXY(111, i);
		cout << (char)179;
	}
	p->getConsoleUtilities()->gotoXY(111, 6);
	cout << (char)197; // middle
#pragma endregion

#pragma region Output score board word
	// output word
	p->getConsoleUtilities()->gotoXY(104, 3); // name spot
	cout << "Unknown";
	p->getConsoleUtilities()->gotoXY(104, 5); // score spot
	cout << "Score:";
	p->getConsoleUtilities()->gotoXY(104, 7); // level spot
	cout << "Level:";
	p->getConsoleUtilities()->gotoXY(112, 5); // score spot
	cout << "?";
	p->getConsoleUtilities()->gotoXY(112, 7); // level spot
	cout << "?";
#pragma endregion

#pragma region How to play board
	// how to play board
	// length 100 - 130
	// width 11 - 20
	p->getConsoleUtilities()->setTextColor(242); // set white-deep-green
	p->getConsoleUtilities()->gotoXY(100, 11);
	cout << (char)201; // top left corner
	for (int i = 101; i < 130; i++) // top edge
		cout << (char)205;
	cout << (char)187; // top right corner
	for (int i = 12; i < 20; i++) { // right edge
		p->getConsoleUtilities()->gotoXY(130, i);
		cout << (char)186;
	}
	for (int i = 12; i < 20; i++) { // left edge
		p->getConsoleUtilities()->gotoXY(100, i);
		cout << (char)186;
	}
	p->getConsoleUtilities()->gotoXY(100, 20);
	cout << (char)200; // bottom left corner
	for (int i = 101; i < 130; i++) // bottom edge
		cout << (char)205;
	cout << (char)188; // bottom right corner
#pragma endregion

#pragma region Output how to play
	// output how to play
	p->getConsoleUtilities()->setTextColor(240); // set white-black
	p->getConsoleUtilities()->gotoXY(102, 13);
	cout << "How to play: ";
	p->getConsoleUtilities()->gotoXY(104, 14);
	cout << (char)248 << " Use arrow key or A, W, ";
	p->getConsoleUtilities()->gotoXY(106, 15);
	cout << "S, D to move.";
	p->getConsoleUtilities()->gotoXY(104, 16);
	cout << (char)248 << " Press p to pause or ";
	p->getConsoleUtilities()->gotoXY(106, 17);
	cout << "resume.";
	p->getConsoleUtilities()->gotoXY(104, 18);
	cout << (char)248 << " Press r to play again ";
#pragma endregion
}

void PlayGame::drawInputName(int gameMode) {
	ConsoleHelper* p;

#pragma region Input name board
	// length 3 - 97
	// width 7 - 12
	p->getConsoleUtilities()->setTextColor(244); // set white-red
	p->getConsoleUtilities()->gotoXY(3, 7);
	cout << (char)218; // top left corner
	for (int i = 4; i < 97; i++) // top edge
		cout << (char)196;
	cout << (char)191; // top right corner
	for (int i = 8; i < 12; i++) { // right edge
		p->getConsoleUtilities()->gotoXY(3, i);
		cout << (char)179;
	}
	for (int i = 8; i < 12; i++) { // left edge
		p->getConsoleUtilities()->gotoXY(97, i);
		cout << (char)179;
	}
	p->getConsoleUtilities()->gotoXY(3, 12);
	cout << (char)192; // bottom left corner
	for (int i = 4; i < 97; i++) // bottom edge
		cout << (char)196;
	cout << (char)217; // bottom right corner
#pragma endregion

#pragma region Input name word
	p->getConsoleUtilities()->setTextColor(240); // set white-black
	p->getConsoleUtilities()->gotoXY(42, 9);
	cout << "Input your name: ";
	p->getConsoleUtilities()->gotoXY(42, 10);
	cout << "Meo..............";
#pragma endregion
}

void PlayGame::drawTableGame() {
	ConsoleHelper* p;

#pragma region Table game
	// length 2 - 92
	// width 2 - 28
	p->getConsoleUtilities()->setTextColor(244); // set white-red
	p->getConsoleUtilities()->gotoXY(2, 2);
	cout << (char)218; // top left corner
	for (int i = 3; i < 92; i++) // top edge
		cout << (char)196;
	cout << (char)191; // top right corner
	for (int i = 3; i < 28; i++) { // right edge
		p->getConsoleUtilities()->gotoXY(92, i);
		cout << (char)179;
	}
	for (int i = 3; i < 28; i++) { // left edge
		p->getConsoleUtilities()->gotoXY(2, i);
		cout << (char)179;
	}
	p->getConsoleUtilities()->gotoXY(2, 28);
	cout << (char)192; // bottom left corner
	for (int i = 3; i < 92; i++) // bottom edge
		cout << (char)196;
	cout << (char)217; // bottom right corner
	// draw line
	p->getConsoleUtilities()->gotoXY(2, 5);
	cout << (char)195;
	for (int i = 3; i < 92; i++)
		cout << (char)196;
	cout << (char)180;
	p->getConsoleUtilities()->gotoXY(2, 9);
	cout << (char)195;
	for (int i = 3; i < 92; i++)
		cout << (char)196;
	cout << (char)180;
	p->getConsoleUtilities()->gotoXY(2, 13);
	cout << (char)195;
	for (int i = 3; i < 92; i++)
		cout << (char)196;
	cout << (char)180;
	p->getConsoleUtilities()->gotoXY(2, 17);
	cout << (char)195;
	for (int i = 3; i < 92; i++)
		cout << (char)196;
	cout << (char)180;
	p->getConsoleUtilities()->gotoXY(2, 21);
	cout << (char)195;
	for (int i = 3; i < 92; i++)
		cout << (char)196;
	cout << (char)180;
	p->getConsoleUtilities()->gotoXY(2, 25);
	cout << (char)195;
	for (int i = 3; i < 92; i++)
		cout << (char)196;
	cout << (char)180;
#pragma endregion

#pragma region Traffic lights
	// red light
	p->getConsoleUtilities()->setTextColor(244); // set white-red
	p->getConsoleUtilities()->gotoXY(94, 5);
	cout << (char)218 << (char)196 << (char)196 << (char)191;
	p->getConsoleUtilities()->gotoXY(94, 6);
	cout << (char)179 << (char)178 << (char)178 << (char)179;
	p->getConsoleUtilities()->gotoXY(94, 7);
	cout << (char)192 << (char)196 << (char)196 << (char)217;

	// green light
	p->getConsoleUtilities()->gotoXY(94, 9);
	cout << (char)218 << (char)196 << (char)196 << (char)191;
	p->getConsoleUtilities()->gotoXY(94, 10);
	cout << (char)179;
	p->getConsoleUtilities()->setTextColor(242); // set white-green
	cout << (char)178 << (char)178;
	p->getConsoleUtilities()->setTextColor(244); // set white-red
	cout << (char)179;
	p->getConsoleUtilities()->gotoXY(94, 11);
	cout << (char)192 << (char)196 << (char)196 << (char)217;
#pragma endregion


}
