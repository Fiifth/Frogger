/*
 * Lane.cpp
 *
 *  Created on: 18-mrt.-2016
 *      Author: msn-w
 */

#include <Lane.h>
#include "Factory.h"
Lane::Lane() {

}

Lane::~Lane() {
}

int Lane::coll(Player* player, bool type) {
	if (isTurned())
		return (((player->getY()>=(y)&&player->getY()<(y+h))||(player->getY()+player->getH()>(y)&&player->getY()+player->getH()<=(y+h)))&&((player->getX()>=(x)&&player->getX()<=(x+w))||(player->getX()+player->getW()>=(x)&&player->getX()+player->getW()<=(x+w))));
	else
		return 0;
}

bool Lane::roomForItem()
{
	//height item = row->getHeight();
	int itemX=row->isDirLeft()?screenWidth:-row->getHeight();
	return (getX()<=itemX)&&(getX()+getW()>=row->getHeight()+itemX);
}

bool Lane::spawnItem()
{
	//itemList.push_back(F->createItem(row,x,y,w,h,0));
	itemList.push_back(F->createItem(row,0));
	//std::cout<<"new"<<itemList.size()<<endl;
	return true;
}
