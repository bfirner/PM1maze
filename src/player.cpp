/*
 * The person class.
 *
 */



#include "player.h"
#include "mobile.h"
#include "room.h"
#include <functional>
#include <iostream>
#include <string>
#include <vector>

Player::Player(int start_x, int start_y) : Mobile(start_x, start_y) {
}

void Player::doSomething(std::vector<std::vector<Room*>>& rooms) {
	//The player does nothing without user cmd
	return;
}

//Get the prinable character representing this mobile.
char Player::getPrintChar() {
	return 'O';
}

void Player::doSomething(std::vector<std::vector<Room*>>& rooms, std::string cmd) {
	//NEWS: north, east, south, west
	int next_x = x;
	int next_y = y;
	if ("n" == cmd) {
		//Go north
		--next_y;
	}
	else if ("e" == cmd) {
		++next_x;
	}
	else if ("w" == cmd) {
		--next_x;
	}
	else if ("s" == cmd) {
		++next_y;
	}
	else {
		std::cout<<"What? I don't understand "<<cmd<<'\n';
	}

	//Function to safely visit adjacent rooms
	std::function<void(int, int)> visit =
		[&rooms] (int x, int y) {
			if (0 <= y and 0 <= x and
					y < rooms.size() and x < rooms.at(0).size()) {
				rooms.at(y).at(x)->visit();
			}
		};
	
	//Is this next location valid?
	//Checking in one spot saves a little bit of coding
	if (0 <= next_y and 0 <= next_x and
			next_y < rooms.size() and next_x < rooms.at(0).size() and
			not rooms.at(next_y).at(next_x)->isWall()) {
		//This room is okay!
		x = next_x;
		y = next_y;
		//Mark this room and the adjacent ones as being visited
		visit(x, y);
		visit(x-1, y);
		visit(x+1, y);
		visit(x, y-1);
		visit(x, y+1);
		std::cout<<rooms.at(y).at(x)->description()<<'\n';;
	}
	else {
		std::cout<<"Ouch! You bonked your head! You can't go that way!\n";
	}
}
