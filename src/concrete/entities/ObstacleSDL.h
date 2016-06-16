/*
 * ObstacleSDL.h
 *
 *  Created on: 12-mrt.-2016
 *      Author: Kwinten
 */

#ifndef CONCRETE_ENTITIES_OBSTACLESDL_H_
#define CONCRETE_ENTITIES_OBSTACLESDL_H_
#include <abstract/Animator.h>
#include <abstract/entities/Obstacle.h>
#include <abstract/Entity.h>
#include <abstract/Factory.h>
#include <abstract/Row.h>
#include <abstract/Window.h>
#include <concrete/SDLdata.h>
#include <vector>

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
