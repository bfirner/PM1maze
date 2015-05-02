/*
 * A walkway.
 *
 * Written by PMI Spring 2015
 */

#include "room.h"
#include <string>

#ifndef WALKWAY_H__
#define WALKWAY_H__

class Walkway : public Room {
	public:
		//Return a description of the room
		std::string description();
		//Is this room passable?
		bool isWall();
		//Get the prinable character representing this room.
		char getPrintChar();
};


#endif

