/*
 *
 * Mobile class
 *
 * For all things that move around.
 *
 */

#include "mobile.h"

int Mobile::getX() {
	return x;
}

int Mobile::getY() {
	return y;
}

Mobile::Mobile(int start_x, int start_y) {
	x = start_x;
	y = start_y;
}

std::ostream& operator<<(std::ostream& os, Mobile* mob) {
	os << mob->getPrintChar();
	return os;
}

