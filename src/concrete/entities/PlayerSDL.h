/*
 * PlayerSDL.h
 *
 *  Created on: 22 Feb 2016
 *      Author: Kwinten
 */

#ifndef CONCRETE_ENTITIES_PLAYERSDL_H_
#define CONCRETE_ENTITIES_PLAYERSDL_H_
#include <abstract/Animator.h>
#include <abstract/entities/Player.h>
#include <abstract/entities/Projectile.h>
#include <abstract/entities/Props.h>
#include <abstract/Entity.h>
#include <abstract/Factory.h>
#include <abstract/Window.h>
#include <concrete/SDLdata.h>
#include <vector>
#include "SDL.h"
namespace frogger_sdl
{
	class PlayerSDL: public frogger::Player
	{
		public:
			explicit PlayerSDL(SDLdata* sdldata);
			virtual ~PlayerSDL();
			void draw();
		private:
			SDLdata* sdldata;
			std::vector<SDL_Texture*>* playerTex;

	};
}

#endif /* FROGSDL_H_ */
