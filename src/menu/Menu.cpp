/*
 * Menu.cpp
 *
 *  Created on: 24-apr.-2016
 *      Author: msn-w
 */

#include <Menu.h>


Menu::Menu(SDLdata* sdldata):sdldata(sdldata)
{
	int screenHeight=sdldata->getScreenHeight();
	int screenWidth=sdldata->getScreenWidth();
	//int x, int y, int w, int h, int screenWidth, int screenHeight


}

Menu::~Menu()
{
	// TODO Auto-generated destructor stub
}

bool Menu::isStartGame() const
{
	return startGame;
}

void Menu::menuExecution(std::string keyDown, int mXH, int mYH, int mXP,int mYP)
{
}

void Menu::startMenu()
{
}
