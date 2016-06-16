/*
 * ProjectileSDL.h
 *
 *  Created on: 4-apr.-2016
 *      Author: Kwinten
 */

#ifndef SDL_ENTITIES_PROJECTILESDL_H_
#define SDL_ENTITIES_PROJECTILESDL_H_

#include "Abstract/Entities/Projectile.h"
#include "SDL/SDLdata.h"
#include "Abstract/Animator.h"
#include <vector>
namespace frogger_sdl
{
	class ProjectileSDL: public frogger::Projectile
	{
		public:
			explicit ProjectileSDL(SDLdata* sdldata);
			virtual ~ProjectileSDL();
			void draw();
			void queryW(int height);

		private:
			SDLdata* sdldata;
			std::vector<SDL_Texture*>* projTex;
	};
}

#endif /* SDL_ENTITIES_PROJECTILESDL_H_ */
