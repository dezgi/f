/* Ezgi Diþbudak – 2243400
I read and accept the submission rules and the important section specified in assignment file.
This is my own work that is done by myself and my team-mate only */


#ifndef ZOMBIES_H
#define ZOMBIES_H
#include "Entities.h"

using namespace std;

class Zombies : public Entities {
private:
	int life;
	int damage_per_hit; //attack
    int score_per_item;

public:
	Zombies() :Entities() { //Default Constrcutor
		life = 0;
		damage_per_hit = 0;
		score_per_item = 0;
	}
	Zombies(int size, int character, int life, int damage_per_hit, int score_per_item,int x,int y) : Entities(size, character,x,y) {
		this->life = life;
		this->damage_per_hit = damage_per_hit;
		this->score_per_item = score_per_item;
	}

	bool isDead() const { // check if Zombie is dead or not
		if (life <= 0) return 1;
		else return 0;
	}

	void updateLifePoint(int attackvalue) {
		if (life > 0) { //if life is more than 0
			life = life - attackvalue;
		}
		else {
			life = 0;
		}
	}
	int getLife() {
		return this->life;
	}
	void setLife(int life) {
		this->life = life;
	}

	int getDamage_per_hit() {
		return this->damage_per_hit;
	}
	void setDamage_per_hit(int damage_per_hit) {
		this->damage_per_hit = damage_per_hit;
	}

	int getScore_per_item() {
		return this->score_per_item;
	}
	void setScore_per_item(int score_per_item) {
		this->score_per_item = score_per_item;
	}
};

class Large_Zombie : public Zombies {

public:
	Large_Zombie() :Zombies() { //Default Constructor

	}
	Large_Zombie(int size, char character, int life, int damage_per_hit,int score_per_item,int x,int y) : Zombies(size,character,life,damage_per_hit,score_per_item,x,y) {
		size = 3;
		character = 'L';
		life = 12;
		damage_per_hit = 8;
		score_per_item = 100;
	}
};

class Medium_Zombie : public Zombies {

public:

	Medium_Zombie() : Zombies() { //Default Constructor

	}
	Medium_Zombie(int size, char character, int life, int damage_per_hit, int score_per_item,int x,int y) : Zombies(size, character, life, damage_per_hit, score_per_item,x,y) {
		size = 2;
		character = 'M';
		life = 8;
		damage_per_hit = 4;
		score_per_item = 75;
	}
};

class Small_Zombie : public Zombies {

public:
	Small_Zombie() : Zombies() {

	}
	Small_Zombie(int size, char character, int life, int damage_per_hit, int score_per_item,int x,int y) : Zombies(size, character, life, damage_per_hit, score_per_item,x,y) {
		size = 1;
		character = 'S';
		life = 4;
		damage_per_hit = 2;
		score_per_item = 50;
	}
};

#endif 