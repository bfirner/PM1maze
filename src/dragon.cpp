
/*
 * The dragon class.
 *
 */



#include "dragon.h"
#include "mobile.h"
#include "room.h"
#include <random>
#include <iostream>
#include <string>
#include <vector>

Dragon::Dragon(int start_x, int start_y) : Mobile(start_x, start_y)  {
	std::random_device rd;
	//Start the mersenne twister at the given location
	gen = std::mt19937(rd());
	flip = std::uniform_int_distribution<int>(0, 1);
}

//Get the prinable character representing this mobile.
char Dragon::getPrintChar() {
	return 'D';
}

void Dragon::doSomething(std::vector<std::vector<Room*>>& rooms) {
	//NEWS: north, east, south, west
	int next_x = x;
	int next_y = y;

	std::vector<std::pair<int, int>> possible = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};



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
