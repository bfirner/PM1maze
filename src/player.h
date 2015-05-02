/*
 * The player class.
 *
 * This is you!
 *
 */

#ifndef __PLAYER_H
#define __PLAYER_H

#include "mobile.h"
#include "room.h"
#include <string>
#include <vector>

class Player : public Mobile {
	public:
		Player(int start_x, int start_y);
		char getPrintChar();
		void doSomething(std::vector<std::vector<Room*>>& rooms);
		void doSomething(std::vector<std::vector<Room*>>& rooms, std::string cmd);
};

#endif

