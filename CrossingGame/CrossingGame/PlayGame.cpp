#include "PlayGame.h"

void PlayGame::drawPlayGame(int gameMode) {
	drawInformation();
	drawInputName(gameMode);
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
	
}

void PlayGame::drawInputName(int gameMode) {

}

void PlayGame::drawTableGame() {

}
