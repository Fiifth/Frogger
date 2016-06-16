/*
 * ItemSDL.h
 *
 *  Created on: 18-mrt.-2016
 *      Author: Kwinten
 */

#ifndef CONCRETE_ENTITIES_ITEMSDL_H_
#define CONCRETE_ENTITIES_ITEMSDL_H_

#include <abstract/Animator.h>
#include <abstract/entities/Item.h>
#include <abstract/Row.h>
#include <concrete/SDLdata.h>
#include "SDL.h"
#include <vector>
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

#endif /* CONCRETE_ENTITIES_ITEMSDL_H_ */
