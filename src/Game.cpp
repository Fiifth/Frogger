/*
 * Game.cpp
 *
 *  Created on: 22 Feb 2016
 *      
 */

#include "Game.h"

#include "SDLdata.h"
#include "Factory.h"
#include "Window.h"
#include "Events.h"
#include <iostream>
#include <string>
#include "Row.h"
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <ctime>
#include <ratio>
#include <chrono>
#include "Projectile.h"
#include <Obstacle.h>
#include <Player.h>
#include "Level.h"
#include "LevelProperties.h"
#include "Menu.H"

using namespace std;
using namespace std::chrono;
using namespace frogger;

Game::Game(Factory* F)
{
	char state = 'B';
	char PrevState = 'B';
	int amountOfPlayers=1;
	char gameMode='E';
	char difficulty='E';
	int WindowHeight = 520;
	int WindowWidth = 700;
	int rowHeight = 50;
	int dataWindowHeightDesired = 20;
	int dataWindowHeight =((WindowHeight - dataWindowHeightDesired) % rowHeight)+ dataWindowHeightDesired;
	int gameWindowHeight = WindowHeight - dataWindowHeight;
	int gameWindowWidth = WindowWidth;
	int plStartW = rowHeight, plStartH = rowHeight, plStartSpeed = rowHeight;
	int plStartX = (gameWindowWidth / 2), plStartY = (gameWindowHeight	- plStartW);
	string keyStroke;


	list<Player*> playersR;
	list<Player*>* players = &playersR;
	Events* event = F->createEvents();
	Window* win = F->createWindow();
	LevelProperties* lvlprop;
	Level* level;

	win->makeWindow(WindowWidth, WindowHeight, dataWindowHeight, "frogger");

	Menu* men=new Menu(win,&gameMode,&amountOfPlayers,&difficulty);

	int temp=0;
	while (true)
	{
		int x,y;

		keyStroke = event->getEvent();
		event->getMousePos(&x,&y);

		switch (state)
		{
		case 'B':case'H':case'G':case'S':case 'V':
			//menu case modes
			PrevState=state;
			state=men->menuExecution(keyStroke,state,x,y,x,y);

			win->updateScreen();
			break;
		case 'E':case'C':
			//level execution modes
			if(PrevState==state)
			{
				level->levelExecution(keyStroke);
				state = playersAlive(players, state) ? state : 'G';
				state=level->isObjectiveDone()?'V':state;
				if (((players->back()->getScore()%100)==0)&&(players->back()->getScore()>temp))
				{
					lvlprop->levelUp();
					temp=players->back()->getScore();
				}
				win->dislayData(players);
				win->updateScreen();
			}

			else if (PrevState=='B'||PrevState=='G')
			{
				addPlayers(F,players,amountOfPlayers,plStartX,plStartY,plStartW,plStartH,plStartSpeed,rowHeight);

				lvlprop=new LevelProperties(gameMode);
				level = new Level(F, win, players, rowHeight,lvlprop);
				state=gameMode;
				PrevState=state;
			}
			else if (PrevState=='V')
			{
				addPlayers(F,players,amountOfPlayers,plStartX,plStartY,plStartW,plStartH,plStartSpeed,rowHeight);
				lvlprop->levelUp();
				level = new Level(F, win, players, rowHeight,lvlprop);
				state='C';
				PrevState=state;
			}

			break;
		case 'Q':
				//remove everything
			return;

				break;
		}
	}
}

Game::~Game()
{
}

bool Game::playersAlive(list<Player*>* players, char mode)
{
	bool temp = false;
	for (Player* player : *players)
	{
		temp = temp || !player->isDead();
	}
	return temp;
}

void frogger::Game::addPlayers(Factory* F,list<Player*>* players, int amount,int X,int Y,int W,int H,int speed, int rowHeight)
{
	players->clear();
	if (amount >=1)
	{
	Player* player = F->createPlayer(X, Y, W, H,	speed, rowHeight, 0);
	players->push_back(player);
	}
	if (amount>1)
	{
		Player* player2 = F->createPlayer(X, Y, W, H,	speed, rowHeight, 1);
		player2->setDifferentControls();
		players->push_back(player2);
	}
}
//start_time=chrono::steady_clock::now();
//			end_time=chrono::steady_clock::now();
