/*
 * LaneSDL.h
 *
 *  Created on: 18-mrt.-2016
 *      Author: Kwinten
 */

#ifndef CONCRETE_ENTITIES_LANESDL_H_
#define CONCRETE_ENTITIES_LANESDL_H_
#include <abstract/Animator.h>
#include <abstract/entities/Lane.h>
#include <abstract/Factory.h>
#include <abstract/Row.h>
#include <concrete/SDLdata.h>
#include "SDL.h"
#include <vector>
namespace frogger_sdl
{
	class LaneSDL: public frogger::Lane
	{
		public:
			explicit LaneSDL(SDLdata* sdldata);
			virtual ~LaneSDL();
			void draw();
			void queryW(int height);
		private:
			SDLdata* sdldata;
			std::vector<SDL_Texture*>* laneTex;
	};
}

#endif /* CONCRETE_ENTITIES_LANESDL_H_ */
