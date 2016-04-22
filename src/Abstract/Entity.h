/*
 * Entity.h
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#ifndef ENTITY_H_
#define ENTITY_H_
#include <list>
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
	void setScreenSize(int width, int height);
	bool inframe();
	int getH() const;
	int getW() const;
	int getX() const;
	int getY() const;
	int getHeight() const;
	int getWidth() const;
	int getSpeed() const;
	void setSpeed(int speed);
	int getDirection() const;
	void setDirection(int direction);
	void setF(Factory* f);
	virtual void collision(Player* player)=0;
	bool colli(Entity* entity);
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
	int x, y, w, h, speed;
	int screenWidth, screenHeight;
	int direction = 1; //1=up,2=right,3=down,4=left;
	Factory* F;

};

#endif /* ABSTRACT_ENTITY_H_ */
