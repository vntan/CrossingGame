#pragma once
#include "MainGame.h"
#include "User.h"

class Account
{
private:
	static Account* instance;
	const string accountPath = ConsoleHelper::getConsoleUtilities()->getFilePath() + "Account.txt";
	vector<User> data;
	Account();
	~Account();

	void loadAccountFromFile();
	
public:
	static Account* getInstance(); 
	void saveAccountToFile();
	User getAccount(int index);
	void addAccount(string name, int score, int level = -1);
	void updateUserScore(int index, int score);
	void updateUserLevel(int index, int level);
	int findUser(string name);
	vector<User> getListAccount();
};

