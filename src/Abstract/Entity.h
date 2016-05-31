/*
 * Entity.h
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#ifndef ENTITY_H_
#define ENTITY_H_
#include <list>

namespace frogger
{
class Projectile;
class Factory;
class Props;
class Player;
class Entity
{

public:
	Entity();
	virtual ~Entity();
	void move(int deltaX, int deltaY, bool leaveScreen);
	void setSize(int wNew, int hNew);
	void setLocation(int xNew, int yNew);
	void setScreenSize(int* width, int* height);
	bool inframe();
	int getH() const;
	int getW() const;
	int getX() const;
	int getY() const;
	int getHeight() const;
	int getWidth() const;
	int getSpeed() const;
	void setSpeed(int speed);
	char getDirection() const;
	void setDirection(char direction);
	void setF(Factory* f);
	void setYPointer(int* y);
	virtual void collision(Player* player)=0;
	bool colli(Entity* entity);
	bool colli2(Entity* entity1,Entity* entity2);
	struct drawMoveRemove
	{
		bool operator()(Props* prop);
	};
	struct ProjCol
	{
		std::list<Projectile*>* projectList;
		ProjCol(std::list<Projectile*>* projectList) :	projectList(projectList)
		{
		}
		bool operator()(Entity* projectile) const
		{
			int prevSize = projectList->size();
			projectList->remove_if(ProjCol2(projectile));
			int newSize = projectList->size();
			bool shrink = (newSize < prevSize) ? true : false;
			if (shrink)
				delete (projectile);
			return shrink;
		}
	};
	struct ProjCol2
	{
		Entity* project;
		ProjCol2(Entity* project) :
				project(project)
		{
		}
		bool operator()(Entity* projectile) const
		{
			if (projectile->colli(project))
			{
				delete (projectile);
				return true;
			}
			else
				return false;
		}
	};

protected:

	Factory* F;

	int x, yR, w, h, speedR,dividerR,dividerCounter=0;
	char directionR = 'U';

	char* direction=&directionR;
	int* y=&yR;
	int* speed=&speedR;
	int* divider=&dividerR;

	int* screenWidth ;
	int* screenHeight;
};
}

#endif /* ABSTRACT_ENTITY_H_ */
