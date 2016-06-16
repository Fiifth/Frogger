/*
 * Lane.h
 *
 *  Created on: 18-mrt.-2016
 *      Author: Kwinten
 */

#ifndef ABSTRACT_ENTITIES_LANE_H_
#define ABSTRACT_ENTITIES_LANE_H_

#include "Abstract/Entities/Props.h"
#include "Abstract/Entities/Player.h"
#include <list>
#include "Abstract/Entities/Item.h"
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
			void setItemAniList(std::vector<frogger::Animator>* itemAni);
		protected:
			std::list<Item*> itemList;
			std::vector<frogger::Animator>* itemAni=nullptr;

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
