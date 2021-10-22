#include "PlayGame.h"

PlayGame::PlayGame(int gameMode) {
	account = Account::getInstance();
	drawPlayGame(gameMode);
}

void PlayGame::drawPlayGame(int gameMode) {
	drawInformation();
	drawInputName(gameMode);
	drawTableGame();
}

void PlayGame::addNewPlayer(string name, int score) {
	if (account->findUser(name) == -1) account->addAccount(name, score);
	accountPosition = account->getListAccount().size();
}

bool PlayGame::getPlayer(string name) {
	int index = account->findUser(name);
	if (index == -1) return false;
	else {
		accountPosition = index;
		player = account->getListAccount()[index];
	}
}

void PlayGame::drawInformation() {

}

void PlayGame::drawInputName(int gameMode) {

}

void PlayGame::drawTableGame() {
	//Depend on Level.
}