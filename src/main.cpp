/*
 *
 * Simple maze game.
 *
 * Written by PMI Spring 2015
 *
 */


#include <iostream>
#include <string>
#include "maze.h"

int main(int argc, char** argv) {
	//We should get a single argument
	//that is a filename where the maze is stored.
	if (argc != 2) {
		std::cout<<"We need 1 filename to load the maze!\n";
		return 0;
	}

	//Get the filename into a string
	std::string fname(argv[1]);

	//Initialize the maze with that file
	Maze maze(fname);

	if (not maze.valid()) {
		std::cout<<"Bad maze configuration file: "<<fname<<'\n';
		return 0;
	}
	
	//Print out the initial maze state
	std::cout<<maze.welcome()<<'\n';

	//Loop accepting user input until the user wins
	std::string input;
	while (not maze.finished() and std::cin >> input) {
		maze.command(input);
		std::cout<<maze<<'\n';
	}


	//Exit
	return 0;
}


