#include "stdafx.h"
#include "GravityController.h"


GravityController::GravityController()
{
	srand(time(NULL));
	rollNextFigure();
	fig = nextFig;
	rollNextFigure();
}

void GravityController::enterMap(int ** & map, int & height, int & width)
{
	this->map = map;
	this->height = height;
	this->width = width;
}

void GravityController::moveX(int direction)
{
	if (direction == LEFT)
	{
		if (fig->collisionLeft()+posX > 0 && !isCollisionWithBlocks(LEFT))
		{
			posX--;
		}
	}if (direction == RIGHT)
	{
		if (fig->collisionRight()+posX < width-1 && !isCollisionWithBlocks(RIGHT))
		{
			posX++;
		}
	}
}

void GravityController::moveY()
{
	posY++;
}

bool GravityController::isCollision()
{
	for (int i = 0; i < 4; i++)
	{
		if (fig->collisionColumn(i) != -404)
		{
			if (posY + fig->collisionColumn(i) >= height-1)
			{
				return true;
			}
			if(posY + fig->collisionColumn(i) + 1>=0 && i + posX>=0)
			if (map[posY + fig->collisionColumn(i)+1][i+posX] == 1)
			{
				return true;
			}
			
				
		}
	}
	return false;
}

bool GravityController::isCollisionWithBlocks(int side)
{
	if (side == LEFT)
	{
		for (int i = 0; i < 4; i++)
		{
			if (posY + i >= 0 && posY + i < height)
			{
				if (fig->collisionRow(i, LEFT) != -404)
				if (map[posY + i][posX + fig->collisionRow(i, LEFT) - 1] != 0)
				{
					cout << "A";
					return true;
				}
			}
		}
	}if (side == RIGHT)
	{
		for (int i = 0; i < 4; i++)
		{
			if (posY + i >= 0 && posY + i < height)
			{
				if(fig->collisionRow(i, RIGHT)!=-404)
				if (map[posY + i][posX + fig->collisionRow(i, RIGHT) + 1] != 0)
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool GravityController::isCollisionByRotate()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if(posY+i >= 0 && posY+i<height && posX+j>=0 && posX+j<width)
			if (map[posY + i][posX + j] == 1 && fig->tab[i + (fig->nextRotation() - 1) * 4][j] == 1)
				return true;
		}
	}
	return false;
}

void GravityController::outOfMap()
{
	while (posX + fig->collisionLeft() < 0)
		posX++;
	while (posX + fig->collisionRight() > width - 1)
		posX--;
	for (int i = 0; i < 4; i++)
	{
		while (posY + fig->collisionColumn(i) > height - 1)
			posY--;
	}

}

void GravityController::rollNextFigure(int choose)
{
	string filetext = "";
	if (choose == -1)
	{
		cout << rand();
		choose = rand() % AMOUNTOFFIGURES + 1;
		filetext += choose + '0';
		filetext += ".txt";
		nextFig = new Figure(filetext);
		int max = 0;
		for (int i = 0; i < 4; i++)
		{
			if (nextFig->collisionColumn(i) > max)
				max = nextFig->collisionColumn(i);
		}
		posX = 2;
		posY = -1 - max;
	}

}

void GravityController::rollFigure(int choose)
{
	fig = nextFig;
	rollNextFigure();
}

GravityController::~GravityController()
{
}

