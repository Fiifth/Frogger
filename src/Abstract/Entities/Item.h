/*
 * Item.h
 *
 *  Created on: 18-mrt.-2016
 *      Author: Kwinten
 */

#ifndef ABSTRACT_ENTITIES_ITEM_H_
#define ABSTRACT_ENTITIES_ITEM_H_
#include <abstract/entities/Player.h>
#include <abstract/entities/Props.h>
#include <abstract/Entity.h>
namespace frogger
{
	class Item: public frogger::Props
	{
		public:
			Item();
			virtual ~Item();
			virtual void draw()=0;
			void collision(Player* player);
			void effectOnPlayer(Player* player);
			bool itemListEmpty();
			void setEffect(int effect);
			int getEffect();
		protected:
			int effect;
	};
}

#endif /* ABSTRACT_ENTITIES_ITEM_H_ */
