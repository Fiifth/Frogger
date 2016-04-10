/*
 * Projectile.cpp
 *
 *  Created on: 4-apr.-2016
 *      Author: msn-w
 */

#include <Projectile.h>

Projectile::Projectile() {
	// TODO Auto-generated constructor stub

}

Projectile::~Projectile() {
	// TODO Auto-generated destructor stub
}

int Projectile::coll(Entity* entity, bool type)
{
	return (((entity->getY()>=(y)&&entity->getY()<(y+h))||(entity->getY()+entity->getH()>(y)&&entity->getY()+entity->getH()<=(y+h)))&&((entity->getX()>=(x)&&entity->getX()<=(x+w))||(entity->getX()+entity->getW()>=(x)&&entity->getX()+entity->getW()<=(x+w))));
}
