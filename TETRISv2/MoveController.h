#pragma once
#include <iostream>
#include "const.h"
#include <conio.h>
#include <cstdlib>
using namespace std;

class MoveController
{
	int lastMove;
public:
	int getMove();
	int getLastMove();
	MoveController();
	~MoveController();
};

