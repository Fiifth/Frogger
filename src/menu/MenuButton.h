/*
 * MenuButton.h
 *
 *  Created on: 24-apr.-2016
 *      Author: msn-w
 */

#ifndef MENUBUTTON_H_
#define MENUBUTTON_H_
#include "Window.h"
namespace frogger
{
	class MenuButton
	{
		public:
			MenuButton(double x, double y, double w, double h, Window* win);
			virtual ~MenuButton();
			bool col(int xCo, int yCo);
			int getH() const;
			int getX() const;
			int getY() const;
			int getW() const;

		private:
			int x, y, w, h;
	};
}

#endif /* MENUBUTTON_H_ */
