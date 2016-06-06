/*
 * ItemSDL.h
 *
 *  Created on: 18-mrt.-2016
 *      Author: msn-w
 */

#ifndef SDL_ENTITIES_ITEMSDL_H_
#define SDL_ENTITIES_ITEMSDL_H_

#include "Item.h"
#include "SDLdata.h"
#include "SDL.h"
#include "Row.h"
#include <vector>
#include "Animator.h"
namespace frogger_sdl
{
	class ItemSDL: public frogger::Item
	{
		public:
			ItemSDL(SDLdata* sdldata, frogger::Row* row, int x, int ind);
			ItemSDL(SDLdata* sdldata, frogger::Row* row, int ind);
			ItemSDL(SDLdata* sdldata);
			virtual ~ItemSDL();
			void draw();
			void queryW(int height);
		private:

			SDLdata* sdldata;
			std::vector<SDL_Texture*>* itemTex;
	};
}

#endif /* SDL_ENTITIES_ITEMSDL_H_ */
