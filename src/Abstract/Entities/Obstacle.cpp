/*
 * Enemy.cpp
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#include <Obstacle.h>
#include "Factory.h"

Obstacle::Obstacle()
{
}

Obstacle::~Obstacle()
{
}

void Obstacle::collision(Player* player)
{
	considerFire();
	if (colli(player) && (!isTurned()))
		player->hit();
	else
	{
		int temp = projectileList.size();
		projectileList.remove_if(ProjCol2(player));
		int temp2 = projectileList.size();
		if (temp2 < temp)
			player->hit();
	}
	player->getProjectileList()->remove_if(playerProjectiles(this));
	projectileList.remove_if(ProjCol(player->getProjectileList()));
}

bool Obstacle::roomForItem()
{
	return false;
}

bool Obstacle::fire()
{
	projectileList.push_back(F->createProjectile(this, 5, 0));
	return true;
}

void Obstacle::considerFire()
{
	if (isVisible() && (((abs(x - previousX))) > w))
	{
		if (rand() % 100 > row->getShootRate())
			fire();
		previousX = x;
	}
}
std::list<Projectile*>* Obstacle::getProjectileList()
{
	return &projectileList;
}
