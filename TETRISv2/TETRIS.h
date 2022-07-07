#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include "Map.h"
#include "GravityController.h"
#include "MoveController.h"

using namespace std;

class TETRIS
{
	int points;
	Map * MapC;
	GravityController * GravC;
	MoveController * MoveC;
public:
	void showAndCheck();
	void textTetris();
	void gameOver();
	TETRIS();
	~TETRIS();
};

