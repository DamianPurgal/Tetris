#pragma once

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <fstream>
#include "const.h"
using namespace std;
class Figure
{
public:
	int variations;
	int**tab;//tablica wszystkich warjacji
	int**fig;//tablica aktualnej warjacji
	int actualRotation;
	fstream File;
	int color;
public:
	int collisionLeft();//numer kolumny w ktorej jest 1 (od lewej)
	int collisionRight();//numer kolumny w ktorej jest 1 (od prawej)
	void showFig();
	int collisionColumn(int column);
	int nextRotation();
	int collisionRow(int row, int direction);
	Figure(string file);
	~Figure();
	void rotate();
	void rollColor();
};

