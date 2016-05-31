/*
 * Menu.cpp
 *
 *  Created on: 24-apr.-2016
 *      Author: msn-w
 */

#include <Menu.h>
#include "MenuButton.h"
using namespace frogger;


Menu::Menu(Window* win):win(win)
{
	//int x,int y,int w,int h

	classic=new MenuButton(180,200,320,35);
	endless=new MenuButton(180,280,340,35);
	high=new MenuButton(220,365,260,35);
	quit=new MenuButton(280,450,120,35);
	p1=new MenuButton(230,220,230,35);
	p2=new MenuButton(230,350,270,35);
	menu=new MenuButton(80,310,140,35);
	restart=new MenuButton(410,320,210,35);
	back=new MenuButton(30,474,110,35);


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

char Menu::menuExecution(std::string keyDown,char state, int mXH, int mYH, int mXP,int mYP)
{
	//menuTextures={M,MCL,ME,MH,MQ,PS,PS1,PS2,G,GM,GR,H,HB};
	switch (state)
	{
	case'S':
		if(classic->col(mXH,mYH))
		{
			win->setBackground(1);
			if(keyDown=="MOUSEBUTTONDOWN")
				return 'M';
		}
		else if(endless->col(mXH,mYH))
				{
					win->setBackground(2);
					if(keyDown=="MOUSEBUTTONDOWN")
						return 'N';
				}
		else if(high->col(mXH,mYH))
		{
			win->setBackground(3);
			if(keyDown=="MOUSEBUTTONDOWN")
			{
				return 'H';
			}
		}
		else if(quit->col(mXH,mYH))
		{
			win->setBackground(4);
			if(keyDown=="MOUSEBUTTONDOWN")
				return 'Q';
		}
		else
		{
			win->setBackground(0);
			if (keyDown=="Escape")
				return 'Q';
			else
				return state;
		}
		break;
	case'H':
		if(back->col(mXH,mYH))
		{
			win->setBackground(12);
			if(keyDown=="MOUSEBUTTONDOWN")
			{
				state='S';
			}
		}
		else
		{
			win->setBackground(11);
			if (keyDown=="Escape")
				return 'Q';
			else
				return state;
		}
		break;
	case'M':case'N':
		if(p1->col(mXH,mYH))
				{
					win->setBackground(6);
					if(keyDown=="MOUSEBUTTONDOWN")
						return 'I';
				}
				else if(p2->col(mXH,mYH))
						{
							win->setBackground(7);
							if(keyDown=="MOUSEBUTTONDOWN")
								return 'O';
						}
				else
				{
					win->setBackground(5);
						return state;
				}

		break;
	case'G':
		if(menu->col(mXH,mYH))
		{
			win->setBackground(9);
			if(keyDown=="MOUSEBUTTONDOWN")
				return 'S';
		}
		else if(restart->col(mXH,mYH))
				{
					win->setBackground(10);
					if(keyDown=="MOUSEBUTTONDOWN")
						return 'S';
				}
		else
		{
			win->setBackground(8);
				return state;
		}
		break;
	case'V':

		break;


	}
	return state;
}


