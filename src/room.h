/*
 *
 * Room class
 *
 * Written by PMI Spring 2015
 *
 */

#include <iostream>

#ifndef ROOM_H__
#define ROOM_H__

class Room {
	public:
		Room();

		//Return a description of the room
		virtual std::string description() = 0;
		//Is this room passable?
		virtual bool isWall() = 0;
		//Get the prinable character representing this room.
		virtual char getPrintChar() = 0;
		//Indicate that the room was visited
		virtual void visit();
		virtual bool visited();
	protected:
		bool visited_;
};

//Print out the character representing the room
std::ostream& operator<<(std::ostream& os, Room* room);


#endif //Defined ROOM_H__
