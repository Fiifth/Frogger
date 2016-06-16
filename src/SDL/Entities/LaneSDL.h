/*
 * LaneSDL.h
 *
 *  Created on: 18-mrt.-2016
 *      Author: Kwinten
 */

#ifndef SDL_ENTITIES_LANESDL_H_
#define SDL_ENTITIES_LANESDL_H_
#include "Abstract/Entities/Lane.h"
#include "SDL/SDLdata.h"
#include "Abstract/Row.h"
#include "SDL.h"
#include <vector>
#include "Abstract/Animator.h"
#include "Abstract/Factory.h"
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

#endif /* SDL_ENTITIES_LANESDL_H_ */
