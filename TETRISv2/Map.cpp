#include "stdafx.h"
#include "Map.h"


void Map::enterFigure(Figure*&fig, Figure*&nextFig)
{
	this->fig = fig;
	this->nextFig = nextFig;
}

void Map::enterXY(int posX, int posY)
{
	this->posX = posX;
	this->posY = posY;
}

void Map::saveFigureOnMap()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (fig->fig[i][j] != 0)
			{
				if (posY + i >= 0)
				{
					map[posY + i][posX + j] = fig->fig[i][j];
					colorMap[posY + i][posX + j] = fig->color;
				}
			}
		}
	}
}

bool Map::isBlockOnFirstLine()
{
	for (int i = 0; i < width; i++)
	{
		if (map[0][i] != 0)
			return true;
	}
	return false;
}

bool Map::isColor(int x, int y)
{
	
	if (x >= posX +fig->collisionLeft() && x <= posX+fig->collisionRight() )
	{
			return true;
	}
	return false;
}

Map::Map(int width, int height)
{
	for (int i = 0; i < 16; i++)
	{
		frame += 219;
	}
	points = 0;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	this->height = height;
	this->width = width;
	map = new int*[height];
	colorMap = new int*[height];
	for (int i = 0; i < height; i++)
	{
		map[i] = new int[width];
		colorMap[i]= new int[width];
		for (int j = 0; j < width; j++)
		{
			map[i][j] = 0;
			colorMap[i][j] = 7;
		}
	}
}


Map::~Map()
{
}

int Map::checkFullLines()
{
	int deleted = 0;
	int actual = this->height-1;
	while (actual != -1)
	{
		if (lineIsFull(actual))
		{
			lineDropTo(actual);
			deleted++;
		}
		else
			actual--;
	}
	points += deleted;
	return deleted;
}

void Map::showMap()
{
	cout << "     ";
	for (int j = 0; j <= (width+1)*2; j++)
	{
		cout << (char)219;
	}
	cout << frame;
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		cout << "     ";
		cout << (char)219<< " ";
		for (int j = 0; j < width; j++)
		{
			if (isColor(j,i))
				SetConsoleTextAttribute(hOut, BACKGROUND_RED | 7 );
			if ((i >= posY && i <= posY + 3) && (j >= posX && j <= posX + 3))
			{
				if (fig->fig[i-posY][j-posX] != 0)
				{
					
					cout << FIGURE_SIGN;
				}
				else
				{
					if (map[i][j] == 1)
					{
						SetConsoleTextAttribute(hOut, colorMap[i][j]);
						cout << FIGURE_SIGN;
					}
					else
						cout << EMPTY_SIGN;
				}
			}
			else
			{
				if (map[i][j] == 1)
				{
					SetConsoleTextAttribute(hOut, colorMap[i][j]);
					cout << FIGURE_SIGN;
				}
				else
					cout << EMPTY_SIGN;
			}
			if (isColor(j + 1, i))
			{
				cout << " ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << " ";
			}
		}
		cout << (char)219;
		//
		if (i == 0)
			elementOfFrame();
		if (i == 1)
			cout << "      NEXT     " << (char)219;
		if(i==2)
			elementOfFrame();
		if (i == 3)
			elementOfFrame2(i - 3);
		if (i == 4)
			elementOfFrame2(i - 3);
		if (i == 5)
			elementOfFrame2(i - 3);
		if (i == 6)
			elementOfFrame2(i - 3);
		if (i == 7)
			elementOfFrame();
		if (i == 8)
			cout << frame;
		if (i == 9)
			elementOfFrame();
		if(i==10)
			cout << "      LINES    " << (char)219;
		if (i == 11)
			elementOfFrame();
		if (i == 12)
		{
			cout << "        " << points;
			for (int i = 0; i < 7 - digits(points); i++)
				cout << " ";
			cout << (char)219;
		}
		if (i == 13)
			elementOfFrame();
		if (i == 14)
			cout << frame;
		if (i == 15)
			elementOfFrame();
		if(i==16)
			cout << "     POINTS    " << (char)219;
		if (i == 17)
			elementOfFrame();
		if (i == 18)
		{
			cout << "        " << points*4;
			for (int i = 0; i < 7 - digits(points*4); i++)
				cout << " ";
			cout << (char)219;
		}
		if (i == 19)
			elementOfFrame();

		//
		cout << endl;
	}
	cout << "     ";
	for (int j = 0; j <= (width + 1) * 2; j++)
	{
		cout << (char)219;
	}
	
	cout << frame;
	cout << endl;
}

bool Map::lineIsFull(int height)
{
	for (int i = 0; i < width; i++)
	{
		if (map[height][i] == 0)
			return false;
	}
	return true;
}

bool Map::lineDropTo(int height)
{
	int actual = height;
	while (actual!=0)
	{
		for (int i = 0; i < width; i++)
		{
			map[actual][i] = map[actual - 1][i];
			colorMap[actual][i] = colorMap[actual - 1][i];
		}
		actual--;
	}
	for (int i = 0; i < 4; i++)
	{
		map[0][i] = 0;
		colorMap[0][i] = 7;
	}
	return true;
}

void Map::elementOfFrame()
{
	for (int i = 0; i < 15; i++)
		cout << " ";
	cout << (char)219;
}

void Map::elementOfFrame2(int c)
{
	cout << "    ";
	for (int z = 0; z < 4; z++)
	{
		if (nextFig->fig[c][z] != 0)
			cout << FIGURE_SIGN << " ";
		else
			cout << "  ";
	}
	cout << "   " << (char)219;
}

int Map::digits(int l)
{
	int z = 0;
	if (l == 0)
		return 1;
	while (l != 0)
	{
		l = l / 10;
		z++;
	}
	return z;
}
