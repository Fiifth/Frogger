/*
 * ProjectileSDL.h
 *
 *  Created on: 4-apr.-2016
 *      Author: Kwinten
 */

#ifndef CONCRETE_ENTITIES_PROJECTILESDL_H_
#define CONCRETE_ENTITIES_PROJECTILESDL_H_

#include <abstract/Animator.h>
#include <abstract/entities/Projectile.h>
#include <concrete/SDLdata.h>
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

#endif /* CONCRETE_ENTITIES_PROJECTILESDL_H_ */
