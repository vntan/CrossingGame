#include "User.h"
User::User(){}

User::User(string name, int score, int level) {
	this->name = name;
	this->score = score;
	this->level = level;
}

User::User(string name, int score) {
	this->name = name;
	this->score = score;
	this->level = 1;
}

User::User(const User& user2) {
	this->name = user2.name;
	this->score = user2.score;
	this->level = user2.level;
}

string User::getName() {
	return name;
}

int User::getScore() {
	return score;
}

void User::setScore(int score) {
	this->score = score;
}

int User::getLevel() {
	return level;
}

void User::setLevel(int level) {
	this->level = level;
}