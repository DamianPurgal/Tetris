#include "stdafx.h"
#include "Figure.h"


int Figure::collisionLeft()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (fig[j][i] == 1)
				return i;
		}
	}
	return -404;
}

int Figure::collisionRight()
{
	for (int i = 3; i >= 0; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			if (fig[j][i] == 1)
				return i;
		}
	}
	return -404;
}

void Figure::showFig()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << fig[i][j];
		}
		cout << endl;
	}
}

int Figure::collisionColumn(int column)
{
	for (int i = 3; i >= 0; i--)
	{
		if (fig[i][column] == 1)
			return i;
	}
	return -404;
}

int Figure::nextRotation()
{
	int ac = actualRotation;
	ac++;
	if (ac > variations)
		ac = 1;
	return ac;
}

int Figure::collisionRow(int row, int direction)
{
	if (direction == LEFT)
	{
		for (int i = 0; i < 4; i++)
		{
			if (fig[row][i] != 0)
			{
				return i;
			}
		}
	}
	if (direction == RIGHT)
	{
		for (int i = 3; i >= 0; i--)
		{
			if (fig[row][i] != 0)
			{
				return i;
			}
		}
	}
	return -404;
}

Figure::Figure(string file)
{
	File.open(file, ios::in);
	actualRotation = 1;
	rollColor();
	File >> variations;
	tab = new int*[variations * 4];
	fig = new int*[4];
	for (int i = 0; i < variations * 4; i++)
	{
		tab[i] = new int[4];
	}
	for (int i = 0; i < variations * 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			File >> tab[i][j];
			//cout << tab[i][j] << " ";
		}
		//cout << endl;
	}
	for (int i = 0; i < 4; i++)
	{
		fig[i] = new int[4];
		for (int j = 0; j < 4; j++)
		{
			fig[i][j] = tab[i][j];
		}
	}
	
	File.close();
}


Figure::~Figure()
{
}

void Figure::rotate()
{
	actualRotation = nextRotation();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fig[i][j] = tab[i + (actualRotation - 1) * 4][j];
		}
	}
}

void Figure::rollColor()
{
	color = rand() % 9+1;
}
