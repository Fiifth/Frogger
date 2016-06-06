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
namespace frogger_sdl
{
	class ProjectileSDL: public frogger::Projectile
	{
		public:
			ProjectileSDL(SDLdata* sdldata, char direction, int Xstart,	int Ystart, int* Ypoint, int size, int speed, int ind);
			ProjectileSDL(SDLdata* sdldata);
			virtual ~ProjectileSDL();
			void draw();
			void queryW(int height);

		private:
			SDLdata* sdldata;
			std::vector<SDL_Texture*>* projTex;
	};
}

#endif /* SDL_ENTITIES_PROJECTILESDL_H_ */
