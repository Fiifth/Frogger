/*
 * ItemSDL.h
 *
 *  Created on: 18-mrt.-2016
 *      Author: msn-w
 */

#ifndef SDL_ENTITIES_ITEMSDL_H_
#define SDL_ENTITIES_ITEMSDL_H_

#include "Item.h"
#include "SDLdata.h"
#include "SDL.h"
#include "Row.h"
#include <vector>
#include "Animator.h"

class ItemSDL:public Item {
public:
	ItemSDL(SDLdata* sdldata,Row* row,int x,int y,int w,int h);
	ItemSDL(SDLdata* sdldata,Row* row);
	virtual ~ItemSDL();
	void draw();
private:
	void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
	SDLdata* sdldata;
	Animator* ani;
};

#endif /* SDL_ENTITIES_ITEMSDL_H_ */
