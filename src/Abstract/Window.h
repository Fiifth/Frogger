/*
 * window.h
 *
 *  Created on: Feb 29, 2016
 *      Author: fifth
 */
#include <string>
#ifndef WINDOW_H_
#define WINDOW_H_

class Window {
public:
	Window();
	virtual ~Window();
	virtual void makeWindow(int ScreenWidth, int ScreenHeight,char const* title)=0;
	void setProp(int width,int height,char const* title);
	virtual void setBackground()=0;
	virtual void updateScreen()=0;
	int getHeight() const;
	int getWidth() const;

protected:
	int WIDTH;
	int HEIGHT;
	char const * TITLE;
};

#endif /* WINDOW_H_ */
