/*
 * start.cpp
 *
 *  Created on: 22 Feb 2016
 *      Author: Kwinten
 */
#define SDL_MAIN_HANDLED

#include "Game.h"
#include "Abstract/Factory.h"
#include "SDL/FactorySDL.h"
#include <unistd.h>
#include <windows.h>
using namespace frogger;

int main(int argc, char *argv[])
{
	frogger::Factory* f = new frogger_sdl::FactorySDL();
	Game* game = new Game(f);
	delete(f);
	delete (game);
	return 0;
}
