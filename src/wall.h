/*
 *
 * A wall type room
 *
 * Written by PMI Spring 2015
 */


#include "room.h"

#ifndef WALL_H__
#define WALL_H__

class Wall : public Room {
	public:
		//Return a description of the room
		std::string description();
		//Is this room passable?
		bool isWall();
		//Get the prinable character representing this room.
		char getPrintChar();
};

#endif

