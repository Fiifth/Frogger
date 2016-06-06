/*
 * Lane.h
 *
 *  Created on: 18-mrt.-2016
 *      Author: msn-w
 */

#ifndef ABSTRACT_ENTITIES_LANE_H_
#define ABSTRACT_ENTITIES_LANE_H_
#include "Props.h"
#include "Player.h"
#include <list>
#include "Item.h"
namespace frogger
{
	class Lane: public frogger::Props
	{
		public:
			Lane();
			virtual ~Lane();
			virtual void draw()=0;
			void collision(Player* player);
			bool itemListEmpty();
			void spawnItem();
			void initLane();
		protected:
			std::list<Item*> itemList;
			struct collisionS
			{
					collisionS(Player* player):	player(player)
					{}
					Player* player;
					bool operator()(Item* item) const;
			};
	};
}
#endif /* ABSTRACT_ENTITIES_LANE_H_ */
