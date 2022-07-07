#pragma once

#include <iostream>
#include "GravityController.h"
#include "const.h"
#include "Figure.h"
#include <windows.h>
#include <cstdlib>
#include <string>
using namespace std;
class Map
{
	bool lineIsFull(int height);
	bool lineDropTo(int height);
	Figure *fig;
	HANDLE hOut;
	string frame;
	void elementOfFrame();
	void elementOfFrame2(int c);
	int digits(int l);
public:
	Figure *nextFig;
	int posY;
	int posX;
	int height;
	int width;
	int points;
	int **map;
	int **colorMap;
	void enterFigure(Figure*&fig,Figure*&nextFig);
	void enterXY(int posX, int posY);
	void saveFigureOnMap();
	bool isBlockOnFirstLine();
	bool isColor(int x, int y);
	Map(int width,int height);
	~Map();
	int checkFullLines();
	void showMap();


};
