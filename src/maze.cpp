/*
 *
 * The exciting maze class!
 *
 * Written by PMI Spring 2015
 */


#include "maze.h"
#include "roomfactory.h"
#include <fstream>
#include "walkway.h"
#include "exit.h"
#include <vector>
#include <string>


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
				person_x = rooms.back().size();
				//Subtract 1 from rows to get the index
				person_y = rooms.size()-1;

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
	//NEWS: north, east, south, west
	int next_x = person_x;
	int next_y = person_y;
	if ("n" == input) {
		//Go north
		--next_y;
	}
	else if ("e" == input) {
		++next_x;
	}
	else if ("w" == input) {
		--next_x;
	}
	else if ("s" == input) {
		++next_y;
	}
	else {
		std::cout<<"What? I don't understand "<<input<<'\n';
	}
	//Is this next location valid?
	//Checking in one spot saves a little bit of coding
	if (0 <= next_y and 0 <= next_x and
			next_y < rooms.size() and next_x < rooms.at(0).size() and
			not rooms.at(next_y).at(next_x)->isWall()) {
		//This room is okay!
		person_x = next_x;
		person_y = next_y;
		//Mark this room and the adjacent ones as being visited
		visit(person_x, person_y);
		visit(person_x-1, person_y);
		visit(person_x+1, person_y);
		visit(person_x, person_y-1);
		visit(person_x, person_y+1);
		std::cout<<rooms.at(person_y).at(person_x)->description()<<'\n';;
		if (nullptr != dynamic_cast<Exit*>(rooms.at(person_y).at(person_x))) {
			std::cout<<"Congratulations! You reached the exit!\n";
			finished_ = true;
		}
	}
	else {
		std::cout<<"Ouch! You bonked your head! You can't go that way!\n";
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
			if (x == maze.person_x and y == maze.person_y) {
				os << 'O';
			}
			else {
				os << maze.rooms.at(y).at(x);
			}
		}
		os <<'\n';
	}
	return os;
}

