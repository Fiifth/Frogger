/*
 * Projectile.cpp
 * This object will be created by obstacles and players.
 * It will act as an obstacle but will also destroy obstacles if it was created by a player.
 * When it is created by an obstacle it will hit players in the game.
 *
 *  Created on: 4-apr.-2016
 *      Author: Kwinten
 */

#include <abstract/entities/Player.h>
#include <abstract/entities/Projectile.h>
using namespace frogger;

Projectile::Projectile()
{
}

Projectile::~Projectile()
{
}

bool frogger::Projectile::itemListEmpty()
{
	return false;
}

void Projectile::collision(Player* player)
{
}

void frogger::Projectile::initProjectile(int speedR, int dividerR,char directionR, int h, int yR,int x)
{
	this->yR=yR;
	this->speedR=speedR;
	this->dividerR=dividerR;
	this->directionR=directionR;
	this->h=h;
	this->x=x;
}

