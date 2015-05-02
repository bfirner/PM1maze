/*
 *
 * The exciting maze class!
 *
 * Written by PMI Spring 2015
 */


#include "maze.h"
#include <fstream>
#include "walkway.h"
#include "wall.h"
#include <vector>
#include <string>


//Initialize the maze with a filename
Maze::Maze(std::string fname) {
	is_valid_ = false;
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
		rooms.push_back(vector<Room*>());
		//Process this line of the maze
		for (char c : line) {
			Room* r = nullptr;
			if (' ' == c) {
				r = new Walkway();
			}
			else if ('W' == c) {
				r = new Wall();
			}
			else if ('O' == c) {
				r = new Walkway();
				//Set person_x and person_y
			}
			else if ('E' == c) {
				r = new Walkway();
				//Set exit_x and exit_y
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
	//TODO
	return;
}

//Is the maze finished?
bool Maze::finished() {
	//TODO
	return false;
}

std::ostream& operator<<(std::ostream& os, Maze& maze) {
	for (std::vector<Room*>& row : rooms) {
		for (Room* r : row) {
			os << r;
		}
		os <<'\n';
	}
	return os;
}

