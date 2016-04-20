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


class Obstacle :public Props{
public:
	Obstacle();
	virtual ~Obstacle();
	virtual void draw()=0;
	void collision(Player* player);
	bool roomForItem();
	bool itemAbsent(){return true;};
	bool fire();
	bool spawnItem(){return false;};
protected:
	std::list<Projectile*>projectileList;
	struct collisionS
	{
	collisionS(Player* player):player(player){}
	Player* player;
	   bool operator()(Projectile* projectile) const
	   {
		  if(projectile->colli(player))
		  {
			  delete(projectile);
			  player->hit();
			  return true;
		  }
		  else
			  return false;
	   }
	};
	struct playerProjectiles
		{
		playerProjectiles(Obstacle* obstacle):obstacle(obstacle){}
		Obstacle* obstacle;
		   bool operator()(Projectile* projectile) const
		   {
			  if(obstacle->isVisible()&&projectile->colli(obstacle))
			  {
				  delete(projectile);
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
