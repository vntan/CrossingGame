#pragma once
#include "UIHelper.h"
#include <mutex>  

class Character
{
private:
	int x, y;
	const int height = 2;
	const int width = 3;
	const int minX = 4;
	const int maxX = 92;
	const int minY = 4;
	const int maxY = 27;

	void setX(int x);
	void setY(int y);

	void drawLines(int y);
	void drawLanes();
public:
	Character();
	int getX();
	int getY();

	void increaseX(int delta);
	void increaseY(int delta);
	void drawCharacter();
	void deleteCharacter();
	void resetCharater(bool isDraw = false);
};

