#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include "TETRIS.h"
using namespace std;
class MenuController
{
	TETRIS* tetris;
public:
	void showMenu();
	void createNewGame();
	MenuController();
	~MenuController();
};

