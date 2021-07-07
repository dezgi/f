/* Hilal Bölük – 2243350
I read and accept the submission rules and the important section specified in assignment file.
This is my own work that is done by myself and my team-mate only */

#ifndef WARRIORS_H
#define WARRIORS_H

#include "Entities.h"

using namespace std;

class Warriors : public Entities {

private:
	int lifePoints;
	int ammunitions;
	int damage;
	int score;
	
public:

	int dice() { //Random dice
		int x = ((rand() % 6) + 1);
		return x;
	}

	Warriors() : Entities(){
		lifePoints = 100;
		ammunitions = 0;
		damage = 5;
		score = 0;
	}

	Warriors(int size, char character,int lifePoints,int ammunitions,int damage,int score,int x,int y) : Entities(size, character,x,y) {
		this->lifePoints = 100;
		this->ammunitions = ammunitions;
		this->damage = damage;
		this->score = score;
	}

	bool isLost() const {
		if (lifePoints <= 0) return 1;
		else return 0;
	}
	void updateLifePoint(int attackvalue) {
		if (lifePoints > 0) { //if healthbar is more than 0
			lifePoints = lifePoints - attackvalue;
		}
		else {
			lifePoints = 0;
		}
	}

	int getLifePoints() {
		return this->lifePoints;
	}
	void setLifePoints(int lifePoints) {
		this->lifePoints = lifePoints;
	}

	int getAmmunitions() {
		return this->ammunitions;
	}
	void setAmmunitions(int ammunitions) {
		this->ammunitions = ammunitions;
	}

	int getDamage() {
		return this->damage;
	}
	void setDamage(int damage) {
		this->damage = damage;
	}

	int getScore() {
		return this->score;
	}
	void setScore(int score) {
		this->score = score;
	}


};

class Derick : public Warriors {

private: 
	int knife;
public :
	Derick() : Warriors() {
		knife = 0;
	}
	Derick(int size, char character, int lifePoints, int ammunitions, int damage,int score,int knife,int x,int y) : Warriors (size, character,lifePoints, ammunitions,damage,score,x,y) {
		character = 'D';
		lifePoints = lifePoints;
		ammunitions = 30;
		damage = damage;
		score = score;
		this->knife = knife;
	}

	int DamageDerick() {

		int dicenumber = dice();
		int damage = 0;
		if (dicenumber == 5 || dicenumber == 6) {
			damage = 10;
			setAmmunitions(getAmmunitions() - 2); //2 shot
		}
		else if (dicenumber == 1 || dicenumber == 2) {
			damage = 2;
			setAmmunitions(getAmmunitions() - 2); //2 shoot
		}
		else {
			if (getAmmunitions() <= 30) { //If Derick has ammunition
				damage = 10;
				setAmmunitions(getAmmunitions() - 2); //2 shots
			}
			if (getAmmunitions() == 1) {
				damage = 5;
				setAmmunitions(getAmmunitions() - 1);
			}
			if (getAmmunitions() <= 0) { //using knife
				damage = 1;
			}
		}
		return damage;
	}

};

class Chichonne : public Warriors {

private:
	int katana;

public:
	Chichonne() : Warriors() {
		katana = 0;
	}
	Chichonne(int size, char character, int lifePoints, int ammunitions, int shot, int bullet, int damage,int score,int katana,int x,int y) : Warriors(size, character, lifePoints, ammunitions, damage,score,x,y) {

		character = 'C';
		lifePoints = lifePoints;
		ammunitions = 25;
		shot = shot;
		bullet = bullet;
		damage = damage;
		score = score;
		this->katana = katana;
	}

	int DamageChichonne(int killnumber) {
		int dicenumber = dice();
		int damage = 0;
		if (dicenumber == 5 || dicenumber == 6) {
			damage = 10;
			setAmmunitions(getAmmunitions() - 1); //1 shot
		}
		else if (dicenumber == 1 || dicenumber == 2) {
			damage = 2;
			setAmmunitions(getAmmunitions() - 2); //2 shots
		}
		else {
			if (getAmmunitions() <= 30) { //If Chichonne has ammunition
				damage = 10;
				setAmmunitions(getAmmunitions() - 2); //1 shoot
			}
			if (getAmmunitions() == 1) {
				damage = 5;
				setAmmunitions(getAmmunitions() - 1);
			}
			//upgrades katana to mega katana after killing 2 or more zombies
			if (getAmmunitions() <= 0) { //using katana
				if (killnumber >= 2) {
					damage = 6;
				}
				else damage = 4;
			}
			
			
		}
		return damage;
	}
	
};

#endif 