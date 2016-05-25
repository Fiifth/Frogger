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
using namespace frogger;

using namespace std;

int main(int argc, char *argv[])
{
	frogger::Factory* f = new frogger_sdl::FactorySDL();
	new Game(f);
	return 0;
}
