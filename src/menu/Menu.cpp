/*
 * Menu.cpp
 *
 *  Created on: 24-apr.-2016
 *      Author: msn-w
 */

#include <Menu.h>
#include "MenuButton.h"


Menu::Menu(Window* win):win(win)
{
	//int x,int y,int w,int h
	start=new MenuButton(200,230,300,35);
	high=new MenuButton(220,310,260,35);
	quit=new MenuButton(285,385,100,35);
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

char Menu::menuExecution(std::string keyDown, int mXH, int mYH, int mXP,int mYP)
{
	if(start->col(mXH,mYH))
	{
		win->setBackground('B');
		if(keyDown=="MOUSEBUTTONDOWN")
			return 'A';
	}
	else if(high->col(mXH,mYH))
	{
		win->setBackground('C');
		if(keyDown=="MOUSEBUTTONDOWN")
			return 'H';
	}
	else if(quit->col(mXH,mYH))
	{
		win->setBackground('D');
		if(keyDown=="MOUSEBUTTONDOWN")
			return 'Q';
	}
	else
	{
		win->setBackground('A');
		if (keyDown=="Escape")
		return 'Q';
		else
			return 'B';
	}
}

void Menu::startMenu()
{
}
