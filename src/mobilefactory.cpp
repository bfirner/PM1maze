/*
 *
 * The mobile factory.
 *
 */

#include "mobilefactory.h"

Mobile* mobileFactory(char c, int x, int y) {
	if ('O' == c) {
		return new Player(x, y);
	}
	else if ('D' == c) {
		return new Dragon(x, y);
	}
	else {
		return nullptr;
	}
}

