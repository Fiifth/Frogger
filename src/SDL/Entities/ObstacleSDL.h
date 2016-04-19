/*
 * EnemySDL.h
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */



#ifndef ENEMYSDL_H_
#define ENEMYSDL_H_
#include "Obstacle.h"
#include "Entity.h"
#include "Window.h"
#include "SDLdata.h"
#include "Row.h"
#include <list>
#include "Animator.h"
#include "Factory.h"

class ObstacleSDL:public Obstacle {
public:

	ObstacleSDL(SDLdata* sdldata,Row* row,Factory* F,int x,int y,int w,int h);
	ObstacleSDL(SDLdata* sdldata,Row* row,Factory* F);
	virtual ~ObstacleSDL();
	void draw();
	void move(int deltaX,int deltaY);
private:
	void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
	SDLdata* sdldata;
	Animator* ani;
};

#endif /* ENEMYSDL_H_ */
