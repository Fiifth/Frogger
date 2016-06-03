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
	int WindowHeight = 660;
	int WindowWidth = 800;
	int rowHeight = 45;
	int dataWindowHeightDesired = 30;
	int dataWindowHeight =((WindowHeight - dataWindowHeightDesired) % rowHeight)+ dataWindowHeightDesired;
	int gameWindowHeight = WindowHeight - dataWindowHeight;
	int gameWindowWidth = WindowWidth;
	int plStartW = rowHeight, plStartH = rowHeight, plStartSpeed = rowHeight;
	int plStartX = (gameWindowWidth / 2), plStartY = (gameWindowHeight	- plStartW);
	string keyStroke;

std::cout<<dataWindowHeight<<std::endl;
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
			if(state=='G'&&PrevState!=state)
				addHighScore(players,gameMode);
			PrevState=state;
			state=men->menuExecution(keyStroke,state,x,y,x,y);
			if(state=='H')
			{
				if(gameMode=='E')
				win->displayHighScore(highScoreEndless);
				else
					win->displayHighScore(highScoreClassic);
			}
			win->updateScreen();
			break;
		case 'E':case'C':
			//level execution modes
			if(PrevState==state)
			{

				level->levelExecution(keyStroke);

				state = playersAlive(players, state) ? state : 'G';
				state=level->isObjectiveDone()?'V':state;
				if (gameMode=='E'&&((players->back()->getScore()%100)==0)&&(players->back()->getScore()>temp))
				{
					lvlprop->levelUp();
					temp=players->back()->getScore();
				}
				win->dislayData(players);
				win->updateScreen();
			}

			else if (PrevState=='B'||PrevState=='G')
			{

				addPlayers(F,players,amountOfPlayers,plStartX,plStartY,plStartW,plStartH,plStartSpeed,rowHeight,gameMode,difficulty);
				lvlprop=new LevelProperties(gameMode,difficulty);
				level = new Level(F, win, players, rowHeight,lvlprop);

				state=gameMode;
				PrevState=state;
			}
			else if (PrevState=='V')
			{
				addPlayers(F,players,amountOfPlayers,plStartX,plStartY,plStartW,plStartH,plStartSpeed,rowHeight,gameMode,difficulty);
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

void frogger::Game::addPlayers(Factory* F,list<Player*>* players, int amount,int X,int Y,int W,int H,int speed, int rowHeight,char gameMode,char difficulty)
{
	int life=4,totalTime=50,scorePerStep=10,projectiles=3; //classic easy mode
	bool counterEnabled=true;

	counterEnabled=(gameMode=='E')?false:true;

	life=(difficulty=='M')?3:life;
	life=(difficulty=='H')?2:life;
	life=(gameMode=='E')?0:life;

	totalTime=(difficulty=='M')?40:totalTime;
	totalTime=(difficulty=='H')?30:totalTime;

	scorePerStep=(difficulty=='M')?20:scorePerStep;
	scorePerStep=(difficulty=='H')?30:scorePerStep;

	projectiles=(difficulty=='M')?2:projectiles;
	projectiles=(difficulty=='H')?1:projectiles;

	players->clear();
	if (amount >=1)
	{
	Player* player = F->createPlayer(X, Y, W, H,	speed, rowHeight, 0);
	player->setParameters(life,totalTime,counterEnabled,scorePerStep,projectiles);
	players->push_back(player);
	}
	if (amount>=2)
	{
		Player* player2 = F->createPlayer(X, Y, W, H,	speed, rowHeight, 1);
		player2->setDifferentControls('A');
		player2->setParameters(life,totalTime,counterEnabled,scorePerStep,projectiles);
		players->push_back(player2);
	}
	if (amount >=3)
	{
		Player* player3 = F->createPlayer(X, Y, W, H,	speed, rowHeight, 1);
		player3->setDifferentControls('B');
		player3->setParameters(life,totalTime,counterEnabled,scorePerStep,projectiles);
		players->push_back(player3);
	}
}

void frogger::Game::addHighScore(list<Player*>* players,char gameMode)
{
	for(Player* play :*players)
	{
		int score=play->getScore();
		if(gameMode=='C')
		{
			highScoreClassic.push_back(score);
			std::sort(highScoreClassic.begin(), highScoreClassic.end());
			std::reverse(highScoreClassic.begin(), highScoreClassic.end());
			highScoreClassic.pop_back();
		}
		else
		{
			highScoreEndless.push_back(score);
			std::sort(highScoreEndless.begin(), highScoreEndless.end());
			std::reverse(highScoreEndless.begin(), highScoreEndless.end());
			highScoreEndless.pop_back();
		}
	}
}
//start_time=chrono::steady_clock::now();
//			end_time=chrono::steady_clock::now();
