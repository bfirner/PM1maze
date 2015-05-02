/*
 * Implementation of Room functions
 *
 *
 * Written by PMI Spring 2015
 *
 */

#include "room.h"

Room::Room() {
	visited_ = false;
}

void Room::visit() {
	visited_ = true;
}

std::ostream& operator<<(std::ostream& os, Room* room) {
	os << room->getPrintChar();
	return os;
}

