/*
 * Implementation of the exit
 *
 * Writen by PMI
 */

#include "exit.h"

//Get the printable character representing this room.
char Exit::getPrintChar() {
	if (visited_) {
		return 'E';
	}
	else {
		return '?';
	}
}

