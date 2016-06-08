/*
 * Obstacle.cpp
 * These are the type of objects where a player cannot stand on (when it isn't turned). They are the opposite of the lane object.
 *
 * The obstacle can be turned by the animator and when it is shot by a player.
 * When the object is turned it will behave like a lane (exeption last row with classic mode).
 *
 * The obstacle itself can create projectile objects during its lifetime.
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
	for(Projectile* proj:projectileList)
		delete(proj);
	projectileList.clear();
}

void Obstacle::collision(Player* player)
{
	considerFire();
	if (colli(player)	&& ((!isTurned()) || (row->getRowProperties()->getType()) == 'E')) //exeption last row with classic mode overwrites turned
		player->hit();
	else
	{
		int temp = projectileList.size();
		projectileList.remove_if(ProjCol2(player)); //collision obstacle bullets with player
		int temp2 = projectileList.size();
		if (temp2 < temp)	//when there was a collision with the player the vector size will be smaller
			player->hit();
	}
	//collision obstacle and player projectiles
	player->getProjectileList()->remove_if(playerProjectiles(this));
	//collision obstacle projectiles and player projectiles
	projectileList.remove_if(ProjCol(player->getProjectileList()));
}

void Obstacle::fire()
{
	Projectile* proj=F->createProjectile1();
	proj->setAni(projAni->at(0).clone());
	proj->queryW(row->getHeight());
	proj->setProperties(row,screenWidth,screenHeight,x,proj->getW(),true);
	proj->setSpeed(5);
	projectileList.push_back(proj);
}

void Obstacle::considerFire()
{
	if (isVisible() && (((abs(x - previousX))) > w)) //only try to fire when the object travelled its own width
	{
		if (rand() % 100 < *shootRate)
			fire();
		previousX = x;
	}
}

bool frogger::Obstacle::itemListEmpty()
{
	return true;
}

std::list<Projectile*>* Obstacle::getProjectileList()
{
	return &projectileList;
}

bool frogger::Obstacle::playerProjectiles::operator ()(Projectile* projectile) const
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

void frogger::Obstacle::setPrevX()
{
	previousX=x;
}

void frogger::Obstacle::setProjAniList(std::vector<frogger::Animator>* projAni)
{
	this->projAni=projAni;
}
