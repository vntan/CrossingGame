#pragma once
#include "MainGame.h"
#include "User.h"

class Account
{
private:
	static Account* instance;
	const string accountPath = UIHelper::getUIHelper()->getFilePath() + "Account.txt";
	vector<User> data;
	Account();

	
public:
	static Account* getInstance(); 
	void loadAccountFromFile();
	void saveAccountToFile();
	User getAccount(int index);
	void addAccount(string name, int score, int level = -1);
	void updateUserScore(int index, int score);
	void updateUserLevel(int index, int level);
	void updateUser(int index, User user);
	int findUser(string name);
	vector<User> getListAccount();

	~Account();
};

