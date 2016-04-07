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

int Projectile::coll(int xPos, int YPos, int height, int width, bool type)
{
	return (((YPos>=(y)&&YPos<=(y+h))||(YPos+height>=(y)&&YPos+height<=(y+h)))&&((xPos>=(x)&&xPos<=(x+w))||(xPos+width>=(x)&&xPos+width<=(x+w))));
}
