/*
 * ProjectileSDL.h
 *
 *  Created on: 4-apr.-2016
 *      Author: msn-w
 */

#ifndef SDL_ENTITIES_PROJECTILESDL_H_
#define SDL_ENTITIES_PROJECTILESDL_H_

#include "Projectile.h"
#include "SDLdata.h"
#include "Animator.h"

class ProjectileSDL: public Projectile
{
public:
	ProjectileSDL(SDLdata* sdldata, int direction, int Xstart, int Ystart,
			int size, int speed, int ind);
	virtual ~ProjectileSDL();
	void draw();

private:
	SDLdata* sdldata;
	Animator* ani;

};

#endif /* SDL_ENTITIES_PROJECTILESDL_H_ */
