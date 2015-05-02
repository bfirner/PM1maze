/*
 * Implementation of the walkway
 *
 * Writen by PMI
 */


//Return a description of the room
std::string Walkway::description() {
	return "The faint scent of mildew emanates from the wet dungeon walls.";
}
//Is this room passable?
bool Walkway::isWall() {
	return false;
}
//Get the prinable character representing this room.
char Walkway::getPrintChar() {
	if (visited_) {
		return ' ';
	}
	else {
		return '?';
	}
}

