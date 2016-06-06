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
	if (colli(player)
			&& ((!isTurned()) || (row->getRowProperties()->getType()) == 'E'))
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

void Obstacle::fire()
{
	//Projectile* proj(F->createProjectile(this, y, 5, 0));
	Projectile* proj=F->createProjectile1();
	proj->setAni(projAni->at(0).clone());
	proj->queryW(row->getHeight());
	proj->setProperties(row,screenWidth,screenHeight,x,proj->getW(),true);
	proj->setSpeed(5);
	projectileList.push_back(proj);
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

bool frogger::Obstacle::itemListEmpty()
{
	return true;
}

std::list<Projectile*>* Obstacle::getProjectileList()
{
	return &projectileList;
}

void Obstacle::editYForProjectiles()
{
	for (Projectile* proje : projectileList)
	{
		proje->setLocation(proje->getX(), *y);
	}
}

bool frogger::Obstacle::playerProjectiles::operator ()(
		Projectile* projectile) const
{
	if (obstacle->isVisible()
			&& obstacle->colli(projectile))
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
