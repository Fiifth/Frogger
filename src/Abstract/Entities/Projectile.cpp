/*
 * Projectile.cpp
 *
 *  Created on: 4-apr.-2016
 *      Author: msn-w
 */

#include <Projectile.h>
#include "Player.h"

Projectile::Projectile()
{
	// TODO Auto-generated constructor stub

}

Projectile::~Projectile()
{
	// TODO Auto-generated destructor stub
}

void Projectile::collision(Player* player)
{
	//if (!isTurned())
	//	return (((player->getY()>=(y)&&player->getY()<(y+h))||(player->getY()+player->getH()>(y)&&player->getY()+player->getH()<=(y+h)))&&((player->getX()>=(x)&&player->getX()<=(x+w))||(player->getX()+player->getW()>=(x)&&player->getX()+player->getW()<=(x+w))));
	//	else
	//		return false;
}
