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
	this->level = level;
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