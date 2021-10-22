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

	string getName();

	int getScore();
	void setScore(int score);
	
	int getLevel();
	void setLevel(int level);
};

