/*
 * PlayerSDL.h
 *
 *  Created on: 22 Feb 2016
 *      Author: Kwinten
 */

#ifndef SDL_ENTITIES_PLAYERSDL_H_
#define SDL_ENTITIES_PLAYERSDL_H_
#include "Abstract/Entity.h"
#include "Abstract/Entities/Player.h"
#include "Abstract/Window.h"
#include "SDL/SDLdata.h"
#include <vector>
#include "Abstract/Animator.h"
#include "Abstract/Factory.h"
#include "Abstract/Entities/Props.h"
#include "SDL.h"
#include "Abstract/Entities/Projectile.h"
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
