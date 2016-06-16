/*
 * MenuButton.h
 *
 *  Created on: 24-apr.-2016
 *      Author: Kwinten
 */

#ifndef MENU_MENUBUTTON_H_
#define MENU_MENUBUTTON_H_
#include <abstract/Window.h>
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
