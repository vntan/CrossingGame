#pragma once
#include <iostream>
#include <string>

using namespace std;

class User
{
private:
	string name;
	int score;
	int level;
public:
	User();
	User(string name, int score, int level);
	User(string name, int score);
	User(const User& user2);

	string getName();
	void setName(string name);

	int getScore();
	void setScore(int score);
	void increaseScore(int delta);
	
	int getLevel();
	void setLevel(int level);
	void increaseLevel(int delta);
};

