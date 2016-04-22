/*
 * FrogSDL.h
 *
 *  Created on: 22 Feb 2016
 *      Author: msn-w
 */

#ifndef FROGSDL_H_
#define FROGSDL_H_
#include "Entity.h"
#include "Player.h"
#include "Window.h"
#include "SDLdata.h"
#include <vector>
#include "Animator.h"
#include "Factory.h"
#include "Props.h"

class PlayerSDL: public Player
{
public:
	PlayerSDL(SDLdata* sdldata, Factory* F, int x, int y, int w, int h,
			int speedH, int speedV, int number);
	virtual ~PlayerSDL();
	void draw();
	void move(int deltaX, int deltaY);
private:
	void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w,
			int h);
	SDLdata* sdldata;
	std::vector<SDL_Texture*> textures;
	Animator* ani;

};

#endif /* FROGSDL_H_ */
