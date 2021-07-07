/* Ezgi Diþbudak 2243400
I read and accept the submission rules and the extra rules specified in each question. This is my
own work that is done by myself only. */

#ifndef FIGHTER_H
#define FIGHTER_H

using namespace std;

class Fighter {

private:
	int healthbar;
	int attackValue;
	bool lost;

public:

	Fighter(int attackValue,int fighterHealthbar) {
		attackValue = attackValue;
		healthbar = fighterHealthbar;
	}

	virtual void print(void) = 0;

	int getAttackValue() {
		return attackValue;
	}

	int getHealthbar() const {
		return healthbar;
	}

	void updateHealthBar(int attackvalue) {
		if (healthbar > 0) { //if healthbar is more than 0
			healthbar = healthbar - attackvalue;
		}
		else {
			healthbar = 0;
		}
	}

	bool isLost() const { //check the healthbar is less than and equal to zero.
		if (healthbar <=0) return 1; // fighter loses the game
		else return 0;
	}

	void setHealthbar(int health) {
		this->healthbar = health;
	}
	void setAttackValue(int attack) {
		this->attackValue = attack;
	}
};

class Haohmaru : public Fighter {

public: 
	
	Haohmaru(int attackVaue, int fighterHealthbar) : Fighter(attackVaue,fighterHealthbar) {
	}


	void print() {
		if (getHealthbar() > 0) {
			cout << "\nHaohmaru's current stamina: " << getHealthbar();
		}
		else {
			cout << "";
		}
		
	}
};

class Genjuro : public Fighter {

private:
	int attackValue;

public:

	Genjuro(int attackValue, int fighterHealthbar) :Fighter(attackValue,fighterHealthbar) {
	}

	void print() {
		if (getHealthbar() > 0) {
			cout << "\nGenjuro's current stamina: " << getHealthbar();
		}
		else {
			cout << "";
		}
	}

};

#endif