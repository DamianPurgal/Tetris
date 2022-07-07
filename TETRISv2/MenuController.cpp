#include "stdafx.h"
#include "MenuController.h"


void MenuController::showMenu()
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	
	cout << "              " << "ooooooooooooo oooooooooooo ooooooooooooo ooooooooo.   ooooo  .oooooo..o " << endl;
	cout << "              " << "8'   888   `8 `888'     `8 8'   888   `8 `888   `Y88. `888' d8P'    `Y8 " << endl;
	cout << "              " << "     888       888              888       888   .d88'  888  Y88bo.      " << endl;
	cout << "              " << "     888       888oooo8         888       888ooo88P'   888   `'Y8888o.  " << endl;
	cout << "              " << "     888       888    '         888       888`88b.     888       `'Y88b " << endl;
	cout << "              " << "     888       888       o      888       888  `88b.   888  oo     .d8P " << endl;
	cout << "              " << "    o888o     o888ooooood8     o888o     o888o  o888o o888o 8""88888P'  " << endl;
	cout << "              " << "                                                                        " << endl;
	cout << "              " << "                                                                        " << endl;
	cout << "              " << "                                                                        " << endl;
	cout << "              " << "                            ZACZNIJ GRE                                 " << endl;
}

void MenuController::createNewGame()
{
	tetris = new TETRIS;
}

MenuController::MenuController()
{
	showMenu();
	_getch();
	createNewGame();
}


MenuController::~MenuController()
{

}
