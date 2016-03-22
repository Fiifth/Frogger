/*
 * FrogSDL.h
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */
#include "Entity.h"
#include "Player.h"
#include "Window.h"
#include "SDLdata.h"
#include <vector>
#ifndef FROGSDL_H_
#define FROGSDL_H_


class PlayerSDL :public Player {
public:
	PlayerSDL(SDLdata* sdldata,int x,int y,int w,int h,int speedH,int speedV);
	virtual ~PlayerSDL();
	void draw();
	void move(int deltaX,int deltaY);
private:
	void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
	SDLdata* sdldata;
	std::vector<SDL_Texture*> textures;
};


#endif /* FROGSDL_H_ */
