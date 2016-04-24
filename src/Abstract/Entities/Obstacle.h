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

class Obstacle: public Props
{
public:
	Obstacle();
	virtual ~Obstacle();
	virtual void draw()=0;
	void collision(Player* player);
	bool roomForItem();
	bool itemListEmpty()
	{
		return false;
	};
	bool itemAbsent()
	{
		return true;
	}
	;
	bool fire();
	void considerFire();
	bool spawnItem()
	{
		return false;
	}
	;
	std::list<Projectile*>* getProjectileList();
protected:
	int previousX = 0;
	std::list<Projectile*> projectileList;

	struct playerProjectiles
	{
		playerProjectiles(Obstacle* obstacle) :
				obstacle(obstacle)
		{
		}
		Obstacle* obstacle;
		bool operator()(Projectile* projectile) const
		{
			if (obstacle->isVisible() && obstacle->colli(projectile))
			{
				delete (projectile);
				obstacle->setVisible(false);
				obstacle->setTurned(true);
				return true;
			}
			else
				return false;
		}
	};
};

#endif /* ENEMY_H_ */
