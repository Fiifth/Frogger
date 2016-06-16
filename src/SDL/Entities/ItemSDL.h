/*
 * ItemSDL.h
 *
 *  Created on: 18-mrt.-2016
 *      Author: Kwinten
 */

#ifndef SDL_ENTITIES_ITEMSDL_H_
#define SDL_ENTITIES_ITEMSDL_H_

#include "Abstract/Entities/Item.h"
#include "SDL/SDLdata.h"
#include "SDL.h"
#include "Abstract/Row.h"
#include <vector>
#include "Abstract/Animator.h"
namespace frogger_sdl
{
	class ItemSDL: public frogger::Item
	{
		public:
			explicit ItemSDL(SDLdata* sdldata);
			virtual ~ItemSDL();
			void draw();
			void queryW(int height);
		private:
			SDLdata* sdldata;
			std::vector<SDL_Texture*>* itemTex;
	};
}

#endif /* SDL_ENTITIES_ITEMSDL_H_ */
