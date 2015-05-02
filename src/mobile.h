/*
 *
 * Mobile class
 *
 * For all things that move around.
 *
 */

#ifndef __MOBILE_H
#define __MOBILE_H

#include "room.h"
#include <vector>

class Mobile {
	protected:
		int x;
		int y;
	public:
		Mobile(int start_x, int start_y);

		int getX();
		int getY();

		//Get the prinable character representing this mobile.
		virtual char getPrintChar() = 0;

		//Most mobs will just do something without input
		virtual void doSomething(std::vector<std::vector<Room*>>& rooms) = 0;
};

//Print out the character representing the mob
std::ostream& operator<<(std::ostream& os, Mobile* mob);

#endif

