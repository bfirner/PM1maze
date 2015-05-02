/*
 *
 * The exciting maze class!
 *
 * Written by PMI Spring 2015
 */


#include <algorithm>
#include "maze.h"
#include "roomfactory.h"
#include <fstream>
#include "walkway.h"
#include "exit.h"
#include <vector>
#include <string>
#include "player.h"
#include "mobile.h"


//Initialize the maze with a filename
Maze::Maze(std::string fname) {
	is_valid_ = false;
	finished_ = false;
	std::ifstream infile(fname.c_str());

	//Can't read the file
	if (not infile) {
		return;
	}

	std::string line;
	//The getline function reads in an
	//entire line into the string,
	//including any whitespace like spaces
	//The regular operator>> will stop at spaces
	while (std::getline(infile, line)) {
		//Add a new row to the rooms vector
		rooms.push_back(std::vector<Room*>());
		//Process this line of the maze
		for (char c : line) {
			//We could use a switch statement (it would be faster)
			//The best solution is to use something called a "factory"
			Room* r = nullptr;
			if ('O' == c) {
				r = new Walkway();
				//Set person_x and person_y
				//The current row's size is the offset of this
				//new element
				int x = rooms.back().size();
				//Subtract 1 from rows to get the index
				int y = rooms.size()-1;
				mobs.push_back(new Player(x, y));
			}
			else {
				//Manufacture the appropriate room
				r = roomFactory(c);
			}

			if (nullptr == r) {
				//Not a valid room type!
				return;
			}
			else {
				//Push back the new room
				rooms.back().push_back(r);
			}
		}
	}
	//Only valid if we get to the end
	is_valid_ = true;
}

Maze::~Maze() {
	for (std::vector<Room*>& row : rooms) {
		for (Room* r : row) {
			delete r;
		}
	}

	for (Mobile* mob : mobs) {
		delete mob;
	}
}

//Was the maze initialized properly?
bool Maze::valid() {
	return is_valid_;
}

//The welcome message when the maze starts
std::string Maze::welcome() {
	return "Hola!";
}

//Handle the next user command
void Maze::command(std::string input) {
	//TODO FIXME Fix this
	for (Mobile* mob : mobs) {
		//Player uses the input
		if (nullptr != dynamic_cast<Player*>(mob)) {
			Player* player = dynamic_cast<Player*>(mob);
			player->doSomething(rooms, input);
			Exit* exit = dynamic_cast<Exit*>(rooms.at(player->getY()).at(player->getX()));
			if (nullptr != exit) {
				std::cout<<"Congratulations! You reached the exit!\n";
				finished_ = true;
			}
		}
		else {
			//Regular mobs just do something without input
			mob->doSomething(rooms);
		}
	}
	return;
}

//Visit this room if it exists!
void Maze::visit(int x, int y) {
	if (0 <= y and 0 <= x and
			y < rooms.size() and x < rooms.at(0).size()) {
		rooms.at(y).at(x)->visit();
	}
}

//Is the maze finished?
bool Maze::finished() {
	return finished_;
}

std::ostream& operator<<(std::ostream& os, Maze& maze) {
	for (int y = 0; y < maze.rooms.size(); ++y) {
		for (int x = 0; x <maze.rooms.at(y).size(); ++x) {
			//TODO FIXME This  is a bit awkward.
			//It would be better for the room class to
			//know if something is inside of it and have
			//the room look different. (through its own printing)
			auto mob_in_room = std::find_if(maze.mobs.begin(), maze.mobs.end(),
					[x,y](Mobile* mob) { return (x == mob->getX() and y == mob->getY());});
			if (maze.mobs.end() != mob_in_room) {
				os << (*mob_in_room);
			}
			else {
				os << maze.rooms.at(y).at(x);
			}
		}
		os <<'\n';
	}
	return os;
}

