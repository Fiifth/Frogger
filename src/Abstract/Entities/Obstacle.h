/*
 * Enemy.h
 *
 *  Created on: 12-mrt.-2016
 *      Author: Kwinten
 */

#ifndef ABSTRACT_ENTITIES_OBSTACLE_H_
#define ABSTRACT_ENTITIES_OBSTACLE_H_
#include "Abstract/Entities/Props.h"
#include "Abstract/Entity.h"
#include "Abstract/Row.h"
#include "Abstract/Entities/Player.h"
#include "Abstract/Entities/Projectile.h"
#include <list>
#include <vector>
#include <Abstract/Animator.h>
namespace frogger
{
	class Obstacle: public frogger::Props
	{
		public:
			Obstacle();
			virtual ~Obstacle();
			virtual void draw()=0;
			void collision(Player* player);
			bool itemListEmpty();
			void fire();
			void considerFire();
			std::list<Projectile*>* getProjectileList();
			void setPrevX();
			void setProjAniList(std::vector<frogger::Animator>* projAni);

		protected:
			int previousX = 0;
			std::list<Projectile*> projectileList;
			std::vector<frogger::Animator>* projAni=nullptr;
			struct playerProjectiles
			{
					playerProjectiles(Obstacle* obstacle) :	obstacle(obstacle)
					{
					}
					Obstacle* obstacle;
					bool operator()(Projectile* projectile) const;
			};
	};
}

#endif /* ENEMY_H_ */
