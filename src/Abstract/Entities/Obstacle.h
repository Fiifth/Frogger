/*
 * Enemy.h
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include "Props.h"
#include "Entity.h"
#include "Row.h"
#include <iostream>
#include "Player.h"
#include "Projectile.h"
#include <list>
namespace frogger
{
	class Obstacle: public frogger::Props
	{
		public:
			Obstacle();
			virtual ~Obstacle();
			virtual void draw()=0;
			void collision(Player* player);
			void editYForProjectiles();
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
