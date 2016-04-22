/*
 * LaneSDL.h
 *
 *  Created on: 18-mrt.-2016
 *      Author: msn-w
 */

#ifndef SDL_ENTITIES_LANESDL_H_
#define SDL_ENTITIES_LANESDL_H_
#include "Lane.h"
#include "SDLdata.h"
#include "Row.h"
#include "SDL.h"
#include <vector>
#include "Animator.h"
#include "Factory.h"

class LaneSDL: public Lane
{
public:
	LaneSDL(SDLdata* sdldata, Row* row, Factory* F,bool visible, int x, int y, int w, int h);
	LaneSDL(SDLdata* sdldata, Row* row, Factory* F,bool visible);
	virtual ~LaneSDL();
	void draw();
private:
	void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w,
			int h);
	SDLdata* sdldata;
	Animator* ani;
};

#endif /* SDL_ENTITIES_LANESDL_H_ */
