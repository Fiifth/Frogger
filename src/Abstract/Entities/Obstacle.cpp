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

Obstacle::~Obstacle() {
}

void Obstacle::collision(Player* player) {
	if (colli(player)&&(!isTurned()))
		player->hit();
	else
		projectileList.remove_if(collisionS(player));
	player->getProjectileList().remove_if(playerProjectiles(this));
}

bool Obstacle::roomForItem()
{
	return false;
}

bool Obstacle::fire()
{
	projectileList.push_back(F->createProjectile(this,5,0));


	return true;
}
