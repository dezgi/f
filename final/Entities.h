/* Hilal Bölük – 2243350
I read and accept the submission rules and the important section specified in assignment file.
This is my own work that is done by myself and my team-mate only */

#ifndef ENTITIES_H
#define ENTITIES_H

using namespace std;

class Entities {

private:
	int size;
	char character;
	int x;
	int y;

public:

	Entities() { //Default Constructor
		size = 100;
		character = '0';
	}

	Entities(int size, char character,int x,int y) {
		this->size = size;
		this->character = character;
		this->x = x;
		this->y = y;
	}

	int getSize() {
		return size;
	}
	
	char getCharacter() {
		return character;
	}

	int getx() {
		return this->x;
	}
	void setx(int x) {
		this->x = x;
	}
	int gety() {
		return this->y;
	}
	void sety(int y) {
		this->y = y;
	}



};



#endif 