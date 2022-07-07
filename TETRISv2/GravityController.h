#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <string>
#include "Figure.h"
#include "const.h"

using namespace std;


class GravityController
{
	
public:
	int posX;
	int posY;
	int height;
	int width;
	int **map;
	int **colorMap;
	Figure * nextFig;
	Figure * fig;
	GravityController();
	void enterMap(int ** & map, int & height, int & width);
	void rollFigure(int choose = -1);
	void moveX(int direction);
	void moveY();
	bool isCollision();
	bool isCollisionWithBlocks(int side);
	bool isCollisionByRotate();
	void outOfMap();
	void rollNextFigure(int choose=-1);

	~GravityController();
};

