#include "PlayGame.h"

PlayGame::PlayGame() {
	player = User("Unknown", -1, -1);
	accountPos = -1;
}

void PlayGame::drawPlayGame(int gameMode) {
	drawInformation();
	if (!drawInputName(gameMode)) return;

	UIHelper::getUIHelper()->clrscr();
	drawInformation();
	drawTableGame();

	processGame(gameMode);
}

bool PlayGame::addNewPlayer(string name, int score) {
	Account* account = Account::getInstance();
	if (account->findUser(name) == -1) {
		account->addAccount(name, score, 1);
		accountPos = account->getListAccount().size() - 1;
		player = account->getInstance()->getAccount(accountPos);
		account->saveAccountToFile();
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

	console->setTextColor(240);
	console->gotoXY(109, 3);
	for (int i = 0; i < 24; i++) {
		console->gotoXY(109 + i, 3); cout << " ";
	}

	for (int i = 0; i < 8; i++) {
		console->gotoXY(117 + i, 5); cout << " ";
		console->gotoXY(117 + i, 7); cout << " ";
	}

	console->gotoXY(109, 3); // name spot
	cout << player.getName();
	console->gotoXY(109, 5); // score spot
	cout << "Score:";
	console->gotoXY(109, 7); // level spot
	cout << "Level:";
	console->gotoXY(117, 5); // score spot
	if (player.getScore() >= 0) cout << player.getScore(); else cout << "?";
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
	console->gotoXY(108, 19);
	cout << (char)248 << " Press Esc to exit ";
}

bool PlayGame::drawInputName(int gameMode) {
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
		for (int i = 0; i <= 26; i++) {
			console->gotoXY(35 + i, 10);
			cout << " ";
		}
		console->gotoXY(35, 9);


		if (!name.empty()) cout << "Input your name again: ";
		else cout << "Input your name: ";
		console->gotoXY(35, 10);
		for (int i = 0; i < name.length(); i++) cout << " ";
		name = ""; c = ' ';
		console->gotoXY(35, 10);
		console->showConsoleCursor(true);
		while (c != '\n') {
			c = _getch();
			if (c == 27) return false;
			else
				if (c == 8) {
					if (console->getCursorX() < 36) continue;
					if (name.length() >= 25) cout << " " << c; else cout << c << " " << c;
					name.erase(name.end() - 1);
				}
				else
					if (c == '\n' || c == '\r') break;
					else {
						if (name.length() >= 25) {
							console->gotoXY(59, 10);
							continue;
						}
						if (c < 0 || !isalnum(c) && c != ' ') {
							_getch();
							continue;
						}

						if (isalnum(c) || c == ' ') {
							cout << c;
							name += c;
						}
					}
		}

		console->showConsoleCursor(false);
		if (gameMode == 0 && !name.empty() && addNewPlayer(name)) break;
		if (gameMode != 0 && !name.empty() && getPlayer(name)) break;
		//if (gameMode == 0 && addNewPlayer(name)) break;
		//if (gameMode != 0 && getPlayer(name)) break;
		name = " ";

	} while (true);
	return true;
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

bool PlayGame::loadPlayer() {
	string pathFile = UIHelper::getUIHelper()->getFilePath() + "InfoContinue" + player.getName();

	ifstream f(pathFile);

	if (f.good()) {
		string name; int a, b;
		getline(f, name);
		f >> a >> b;
		player.setName(name);
		player.setLevel(a);
		player.setScore(b);

		f.close();
		remove(pathFile.c_str());
		drawInformation();
		return true;
	}
	else {	
		player.setLevel(1);
		player.setScore(0);
		drawInformation();
		return false;
	}
}

void PlayGame::processGame(int gameMode) {
	bool isContinue = false;
	string result = "";

	//Continue
	if (gameMode == 1 && loadPlayer())
		isContinue = true;
	else isContinue = false;



	thread traffic([](User user, bool isContinue, string* result) {
		Traffic traffic(user, isContinue);
		*result = traffic.startTraffic();
		}, player, isContinue, &result);

	traffic.join();

	UIHelper* helper = UIHelper::getUIHelper();
	if (result == "EXIT") return;
	if (result == "WIN" || result == "RESTART") {
		helper->clrscr();

		if (result == "WIN") {
			player.increaseLevel(1);
			player.increaseScore(10);
		}
		else {
			player.setLevel(1);
			player.setScore(0);
		}

		drawInformation();
		drawTableGame();
		processGame(0);
		return;
	}
	if (result == "LOSE") {

		Account* account = Account::getInstance();

		User userOld = account->getAccount(accountPos);

		int y = 23;
		helper->gotoXY(105, y++);
		cout << "You lose!";

		if (userOld.getScore() < player.getScore()) {
			account->updateUser(accountPos, player);
			account->saveAccountToFile();
			helper->gotoXY(105, y++);
			cout << "High Score: " << player.getScore();
		}

		y++;
		int key = helper->createMenu(105, y++, { "Exit" });
		return;
	}
}

