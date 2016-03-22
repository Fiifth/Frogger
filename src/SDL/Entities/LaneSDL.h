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
class LaneSDL: public Lane{
public:
	LaneSDL(SDLdata* sdldata,Row* row,int x,int y,int w,int h);
	LaneSDL(SDLdata* sdldata,Row* row);
	virtual ~LaneSDL();
	void draw();
private:
	void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
	SDLdata* sdldata;
	std::vector<SDL_Texture*> textures;
	SDL_Texture* tex;
};

#endif /* SDL_ENTITIES_LANESDL_H_ */
