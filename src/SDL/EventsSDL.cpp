/*
 * EventsSDL.cpp
 *
 *  Created on: 6-mrt.-2016
 *      Author: msn-w
 */

#include "EventsSDL.h"
#include "SDL.h"
#include <iostream>

using namespace std;
using namespace frogger_sdl;
//string event;

EventsSDL::EventsSDL()
{

}

EventsSDL::~EventsSDL()
{
}

string EventsSDL::getEvent()
{
	SDL_Event e;
	SDL_PollEvent(&e);
	if (e.type == SDL_KEYDOWN)
	{
		const char* s = SDL_GetKeyName(e.key.keysym.sym);
		return s;
	}
	else if (e.type==SDL_MOUSEBUTTONDOWN)
	{
		return "MOUSEBUTTONDOWN";
	}
	else
		return "";
}
void EventsSDL::getMousePos(int* x,int* y)
{
	SDL_GetMouseState(x,y);
}
