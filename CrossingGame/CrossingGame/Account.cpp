#include "Account.h"

Account* Account::instance = nullptr;

Account* Account::getInstance() {
	if (instance == nullptr) instance = new Account();
	return instance;
}

Account::Account() {
	loadAccountFromFile();
}

Account::~Account() {
	delete instance;
	instance = nullptr;
}

void Account::loadAccountFromFile() {
	fstream f(accountPath, ios::in);
	
	if (f.fail()) return;
	
	while (!f.eof()) {
		string name; int score, level;
		getline(f, name);
		f >> score >> level;
		if (name != "") data.push_back(User(name, score, level));
		getline(f, name);
	}
	f.close();
}

void Account::saveAccountToFile() {
	fstream f(accountPath, ios::out);
	if (f.fail()) return;

	for (int i = 0; i < data.size(); i++) {
		f << data[i].getName() << "\n" << data[i].getScore() << "\n" << data[i].getLevel() << "\n";
	}
	f.close();
}

User Account::getAccount(int index) {
	return data[index];
}

void Account::addAccount(string name, int score, int level) {
	data.push_back(User(name, score, level));
}

void Account::updateUserScore(int index, int score) {
	data[index].setScore(score);
}

void Account::updateUserLevel(int index, int level) {
	data[index].setLevel(level);
}

int Account::findUser(string name) {
	for (int i = 0; i < data.size(); i++) 
		if (name == data[i].getName()) return i;
	
	return -1;
}

vector<User> Account::getListAccount() {
	return data;
}

