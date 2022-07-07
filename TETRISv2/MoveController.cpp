#include "stdafx.h"
#include "MoveController.h"


int MoveController::getMove()
{
	int move = _getch();
	if (move == 'w')
	{
		lastMove = UP;
		return UP;
	}
	if (move == 's')
	{
		lastMove = DOWN;
		return DOWN;
	}
	if (move == 'a')
	{
		lastMove = LEFT;
		return LEFT;
	}
	if (move == 'd')
	{
		lastMove = RIGHT;
		return RIGHT;
	}
	if (move == 32)
	{
		lastMove = SPACE;
		return SPACE;
	}
	return -1;
}

int MoveController::getLastMove()
{
	return lastMove;
}

MoveController::MoveController()
{
	lastMove = -1;
}


MoveController::~MoveController()
{
}
