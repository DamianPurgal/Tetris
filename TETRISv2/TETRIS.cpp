#include "stdafx.h"
#include "TETRIS.h"


void TETRIS::showAndCheck()
{
	system("cls");
	textTetris();
	cout << endl;
	MapC->enterXY(GravC->posX, GravC->posY);
	MapC->showMap();
	points += MapC->checkFullLines();
}

void TETRIS::textTetris()
{
	cout << " _______ _______ _______  ______ _____ _______" << endl;
	cout << "    |    |______    |    |_____/   |   |______" << endl;
	cout << "    |    |______    |    |    \\  __|__ ______|" << endl;
	//roman
}

void TETRIS::gameOver()
{
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "            " << "###############################" << endl;
	cout << "            " << "#                             #" << endl;
	cout << "            " << "#          GAME OVER          #" << endl;
	cout << "            " << "#         HEIGHT LIMIT        #" << endl;
	cout << "            " << "#                             #" << endl;
	cout << "            " << "###############################" << endl;
	Sleep(3000);
}

TETRIS::TETRIS()
{
	srand(time(NULL));
	MoveC = new MoveController;
	MapC = new Map(10, 20);
	GravC = new GravityController;
	GravC->enterMap(MapC->map, MapC->height, MapC->width);
	MapC->enterFigure(GravC->fig, GravC->nextFig);
	showAndCheck();

	int timer, answer;
	for (;;)
	{
		
		timer = 1500;
		while (timer > 0)
		{
			if (_kbhit())
			{
				answer = MoveC->getMove();
					if (answer == LEFT || answer == RIGHT)
					{
						GravC->moveX(answer);
						showAndCheck();
					}
					if (answer == UP)
					{
						if (!GravC->isCollisionByRotate())
						{
							GravC->fig->rotate();
							GravC->outOfMap();
							showAndCheck();
						}	
					}
					if (answer == SPACE)
					{
						while (!GravC->isCollision())
						{
							GravC->moveY();
						}
						showAndCheck();
					}
					if (answer == DOWN)
					{
						GravC->moveY();
						showAndCheck();
						if (MapC->isBlockOnFirstLine())
							break;
					}
					if (GravC->isCollision())
					{
						MapC->saveFigureOnMap();
						GravC->rollFigure();
						MapC->enterXY(GravC->posX, GravC->posY);
						MapC->enterFigure(GravC->fig, GravC->nextFig);
						showAndCheck();
					}
			}
			Sleep(10);
			timer -= 10;
		};
		if (MapC->isBlockOnFirstLine())
			break;
		GravC->moveY();
		showAndCheck();
		if (MapC->isBlockOnFirstLine())
			break;
		if (GravC->isCollision())
		{
			MapC->saveFigureOnMap();
			GravC->rollFigure();
			MapC->enterXY(GravC->posX, GravC->posY);
			MapC->enterFigure(GravC->fig, GravC->nextFig);
			showAndCheck();
		}

	}
	gameOver();
}


TETRIS::~TETRIS()
{
}
