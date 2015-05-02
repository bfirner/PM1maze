/*
 * the room factory!
 *
 */


#include "roomfactory.h"
#include "walkway.h"
#include "wall.h"
#include "exit.h"

Room* roomFactory(char roomtype) {
	if (' ' == roomtype) {
		return new Walkway();
	}
	else if ('W' == roomtype) {
		return new Wall();
	}
	else if ('E' == roomtype) {
		return new Exit();
	}
	else {
		return nullptr;
	}
}

