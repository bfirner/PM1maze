
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
	count = 0;
}

//Get the prinable character representing this mobile.
char Dragon::getPrintChar() {
	return 'D';
}

void Dragon::doSomething(std::vector<std::vector<Room*>>& rooms) {
	//Move every third step
	++count;
	if (3 == count) {

		std::vector<std::pair<int, int>> possible =
		{{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};

		//Remove any locations that aren't actually present or
		//that are walls
		////Also see the "remove_if" function
		for (auto I = possible.begin(); I != possible.end();) {
			int x = I->first;
			int y = I->second;
			if ((0 > x or 0 > y or
						y >= rooms.size() or x >= rooms.at(0).size()) or
					rooms.at(y).at(x)->isWall()) {
				I = possible.erase(I);
			}
			else {
				++I;
			}
		}

		if (not possible.empty()) {
			//Pick a location at random
			std::uniform_int_distribution<int> dir(0, possible.size()-1);
			std::pair<int, int> next = possible.at(dir(gen));
			//Move the dragon
			x = next.first;
			y = next.second;
		}

		//Rezero the step counter
		count = 0;
	}
}

bool Dragon::eat() {
	bool chomp = (0 == flip(gen));
	if (chomp) {
		std::cout<<"Chomp! You have been eaten by a dragon!\n";
	}
	else {
		std::cout<<"Phew! The dragon looks full. You'd best get away!\n";
	}
	return chomp;
}

