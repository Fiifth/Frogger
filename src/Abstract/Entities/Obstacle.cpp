/*
 * Enemy.cpp
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#include <Obstacle.h>
#include "Factory.h"
using namespace frogger;
Obstacle::Obstacle()
{
}

Obstacle::~Obstacle()
{
}

void Obstacle::collision(Player* player)
{
	considerFire();
	if (colli(player) && ((!isTurned())||(row->getRowProperties()->getType())=='E'))
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
	Projectile* proj(F->createProjectile(this,y, 5, 0));
	projectileList.push_back(proj);
	return true;
}

void Obstacle::considerFire()
{
	if (isVisible() && (((abs(x - previousX))) > w))
	{
		if (rand() % 100 < *shootRate)
			fire();
		previousX = x;
	}
}
std::list<Projectile*>* Obstacle::getProjectileList()
{
	return &projectileList;
}

void Obstacle::editYForProjectiles()
{
	for(Projectile* proje:projectileList)
	{
		proje->setLocation(proje->getX(),*y);
	}
}
