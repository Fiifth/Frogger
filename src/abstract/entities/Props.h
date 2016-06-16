/*
 * Pops.h
 *
 *  Created on: 17-mrt.-2016
 *      Author: Kwinten
 */

#ifndef ABSTRACT_ENTITIES_PROPS_H_
#define ABSTRACT_ENTITIES_PROPS_H_
#include <abstract/Entity.h>
#include <abstract/Row.h>
#include <levelGenerator/RowProp.h>
namespace frogger
{
	class Props: public frogger::Entity
	{
		public:
			Props();
			virtual ~Props();
			virtual void queryW(int height)=0;
			void setRow(Row* row);
			Row* getRow();
			void moveForward();
			bool isRoom();
			bool isVisible() const;
			void setVisible(bool visible);
			void setProperties(Row* row, int* screenWidth, int* screenHeight, int x, int w, bool vis);
			virtual void draw()=0;
			bool isTurned() const;
			void setTurned(bool turned);
			bool timeToMove();
			virtual bool itemListEmpty()=0;
			struct drawMoveRemove
			{
					bool operator()(Props* prop);
			};

		protected:
			Row* row;
			bool visible;
			bool turned;
			bool isTurenedByAni;
			int* itemRate;
			int* shootRate;
	};
}
#endif /* ABSTRACT_ENTITIES_PROPS_H_ */
