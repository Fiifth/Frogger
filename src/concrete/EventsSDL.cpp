/*
 * EventsSDL.cpp
 *
 *  Created on: 6-mrt.-2016
 *      Author: Kwinten
 */

#include <concrete/EventsSDL.h>
#include "SDL.h"
using namespace frogger_sdl;


EventsSDL::EventsSDL()
{
}

EventsSDL::~EventsSDL()
{
}
std::string EventsSDL::getEvent()
{
	SDL_Event e;
	SDL_PollEvent(&e);
	if (e.type == SDL_WINDOWEVENT && (e.window.event ==SDL_WINDOWEVENT_CLOSE))
	{
		return "Escape";
	}

	if (e.type == SDL_KEYDOWN)
	{
		const char* s = SDL_GetKeyName(e.key.keysym.sym);
		return s;
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		return "MOUSEBUTTONDOWN";
	}
	else
		return "";
}
void EventsSDL::getMousePos(int* x, int* y)
{
	SDL_GetMouseState(x, y);
}
