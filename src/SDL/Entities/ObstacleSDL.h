/*
 * EnemySDL.h
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#ifndef ENEMYSDL_H_
#define ENEMYSDL_H_
#include "Obstacle.h"
#include "Entity.h"
#include "Window.h"
#include "SDLdata.h"
#include "Row.h"
#include <list>
#include "Animator.h"
#include "Factory.h"

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
