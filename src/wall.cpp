/*
 * The implementation of a Wall.
 *
 * Written by PMI
 */


#include "wall.h"
#include <iostream>

std::string Wall::description() {
	return "This is a wall. You can't get past it. YOU SHALL NOT PASS!!!";
}

bool Wall::isWall() {
	return true;
}

char Wall::getPrintChar() {
	if (visited_) {
		return 'W';
	}
	else {
		return '?';
	}
}

