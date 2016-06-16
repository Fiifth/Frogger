/*
 * ObstacleSDL.h
 *
 *  Created on: 12-mrt.-2016
 *      Author: Kwinten
 */

#ifndef SDL_ENTITIES_OBSTACLESDL_H_
#define SDL_ENTITIES_OBSTACLESDL_H_
#include "Abstract/Entities/Obstacle.h"
#include "Abstract/Entity.h"
#include "Abstract/Window.h"
#include "SDL/SDLdata.h"
#include "Abstract/Row.h"
#include <vector>
#include "Abstract/Animator.h"
#include "Abstract/Factory.h"

namespace frogger_sdl
{
	class ObstacleSDL: public frogger::Obstacle
	{
		public:
			explicit ObstacleSDL(SDLdata* sdldata);
			virtual ~ObstacleSDL();
			void draw();
			void queryW(int height);
		private:
			SDLdata* sdldata;
			std::vector<SDL_Texture*>* obstTex;
	};
}
#endif /* ENEMYSDL_H_ */
