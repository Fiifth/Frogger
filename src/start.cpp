/*
 * start.cpp
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */
#define SDL_MAIN_HANDLED

#include "Game.h"
#include "Player.h"
#include "Factory.h"
#include "PlayerSDL.h"
#include "FactorySDL.h"
#include <iostream>
#include <unistd.h>
#include <windows.h>
using namespace frogger;

using namespace std;

int main(int argc, char *argv[])
{
	frogger::Factory* f = new frogger_sdl::FactorySDL();
	Game* game=new Game(f);
	delete(game);
	return 0;
}
