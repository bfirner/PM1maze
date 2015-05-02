/*
 *
 * The amazing maze class.
 *
 * Writte by PMI Spring 2015
 *
 */

#include <string>
#include <vector>
#include "room.h"

//Preprocessor guards so multiple .cpp files
//can include this
#ifndef MAZE_H__
#define MAZE_H__

class Maze {
	public:
		//Initialize the maze with a filename
		Maze(std::string fname);
		//Free all of the memory
		~Maze();
		//Was the maze initialized properly?
		bool valid();
		//The welcome message when the maze starts
		std::string welcome();
		//Handle the next user command
		void command(std::string input);
		//Is the maze finished?
		bool finished();
	private:
		int person_x;
		int person_y;
		int exit_x;
		int exit_y;
		bool is_valid_;
		friend std::ostream& operator<<(std::ostream& os, Maze& maze);
		std::vector<std::vector<Room*>> rooms;
		//Mark this room as visited if it is within range
		void visit(int x, int y);
		bool finished_;
};

std::ostream& operator<<(std::ostream& os, Maze& maze);

#endif

