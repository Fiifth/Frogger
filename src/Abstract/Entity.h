/*
 * Entity.h
 *
 *  Created on: 12-mrt.-2016
 *      Author: msn-w
 */

#ifndef ABSTRACT_ENTITY_H_
#define ABSTRACT_ENTITY_H_
#include <list>
#include "Animator.h"


namespace frogger
{
	class Projectile;
	class Factory;
	class Player;
	class Entity
	{
		public:
			Entity();
			virtual ~Entity();
			void move(int deltaX, int deltaY, bool leaveScreen);
			void setLocation(int xNew, int yNew);
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
			void setF(Factory* f);
			virtual void collision(Player* player)=0;
			bool colli(Entity* entity);
			bool colli2(Entity* entity1, Entity* entity2);
			void setAni(frogger::Animator* ani);

			struct ProjCol
			{
					std::list<Projectile*>* projectList;
					explicit ProjCol(std::list<Projectile*>* projectList) :
							projectList(projectList)
					{
					}
					bool operator()(Entity* projectile) const;
			};
			struct ProjCol2
			{
					Entity* project;
					explicit ProjCol2(Entity* project):project(project)
					{
					}
					bool operator()(Entity* projectile) const;
			};
		protected:
			Factory* F;
			int x, yR, w, h, speedR, dividerR, dividerCounter;
			char directionR = 'U';
			frogger::Animator* ani;

			char* direction;
			int* y;
			int* speed;
			int* divider;
			int* screenWidth;
			int* screenHeight;
	};
}

#endif /* ABSTRACT_ENTITY_H_ */
