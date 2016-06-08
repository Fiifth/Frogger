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
#include "SDL.h"
#include "Projectile.h"
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
