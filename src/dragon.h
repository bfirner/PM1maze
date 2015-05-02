/*
 * A dragon
 *
 * It will eat with 50% probability
 * Says something (flavor text)
 *
 * Moves every third time you move
 *
 *
 */



#ifndef __DRAGON_H
#define __DRAGON_H

#include "mobile.h"
#include "room.h"
#include <string>
#include <vector>
#include <random>

class Dragon : public Mobile {
	private:
		//Keep track of the turn count and move every third
		int count;
		//Random number generator
		std::mt19937 gen;
		std::uniform_int_distribution<int> flip;
	public:
		Dragon(int start_x, int start_y);
		char getPrintChar();
		void doSomething(std::vector<std::vector<Room*>>& rooms);
		bool eat();
};

#endif
