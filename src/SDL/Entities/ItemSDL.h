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

class ItemSDL:public Item {
public:
	ItemSDL(SDLdata* sdldata,Row* row,int x,int y,int w,int h);
	virtual ~ItemSDL();
	void draw();
private:
	void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
	SDLdata* sdldata;
	std::vector<SDL_Texture*> textures;
	SDL_Texture* tex;
};

#endif /* SDL_ENTITIES_ITEMSDL_H_ */
