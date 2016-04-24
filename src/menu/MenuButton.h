/*
 * MenuButton.h
 *
 *  Created on: 24-apr.-2016
 *      Author: msn-w
 */

#ifndef MENUBUTTON_H_
#define MENUBUTTON_H_

class MenuButton
{
public:
	MenuButton(int x,int y,int w,int h);
	virtual ~MenuButton();
	bool col(int xCo,int yCo);
private:
	int x, y, w, h;
};

#endif /* MENUBUTTON_H_ */
