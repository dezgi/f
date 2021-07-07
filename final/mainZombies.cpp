
/* Hilal Bölük 2243350
   Ezgi Diþbudak 2243400 */

#include <iostream>
#include <stack>
#include "Entities.h"
#include "Zombies.h"
#include "Warriors.h"
#include"Grid.h"

using namespace std;

Derick derick;
Chichonne chichonne;
Large_Zombie largeZombie;
Medium_Zombie mediumzombie;
Small_Zombie smallzombie;
Grid g;
stack<char> killedZombiesByDerick;
stack<char> killedZombiesByChichonne;
void Battle();

int main() {

	int  gridSize;
	g.Deploy();
	g.printGrid();

	Battle(); // call Battle Function

	return 0;
}


/***** Battle Function *****/

/* Ezgi Diþbudak – 2243400
I read and accept the submission rules and the important section specified in assignment file.
This is my own work that is done by myself and my team-mate only */

void Battle() {

	int choose, coordinateX, coordinateY;
	int warriorShot = 0, zombieLifePoint = 0;


	largeZombie.setLife(12); //set Large Zombie's life to 12
	mediumzombie.setLife(8);  //set Medium Zombie's life to 8
	smallzombie.setLife(4); //set Small Zombie's life to 4
	largeZombie.setScore_per_item(100); //set Large Zombie's Score Per Item to 100
	mediumzombie.setScore_per_item(75); //set Large Zombie's Score Per Item to 75
	smallzombie.setScore_per_item(50); //set Large Zombie's Score Per Item to 50
	derick.setAmmunitions(30);         //set Derick's Ammunitions to 30
	chichonne.setAmmunitions(25);     //set Chichonne's Ammunitions to 30

	cout << "Total Number of zombies:" << g.gethowmanyzombies();

	while (g.gethowmanyzombies() != 0) {

		cout << "\n1 for Derick 2 for Chichonne";
		cout << "\nPlease Choose warrior:";
		cin >> choose;
		if (choose == 1) { //if player chooses Derick as a Warrior
			cout << "\nPlease enter X coordinate of the Warrior: ";
			cin >> coordinateX;
			cout << "Please enter Y coordinate of the Warrior: ";
			cin >> coordinateY;

			if (g.getCharformgrid(coordinateX, coordinateY) == '0') {
				cout << "Empty Place";
			}
			else if (g.getCharformgrid(coordinateX, coordinateY) == 'L') { // character  L
				cout << "\nLarge Zombie's health:" << largeZombie.getLife();
				cout << "\nDerick's health:" << derick.getLifePoints();
				while (largeZombie.isDead() != 1) { // if zombie is not dead
					largeZombie.updateLifePoint(derick.DamageDerick());
					cout << "\nLarge Zombie's health:" << largeZombie.getLife();
					derick.updateLifePoint(8);
					cout << "\nDerick's health:" << derick.getLifePoints();
				}

				if (largeZombie.isDead() == 1) {
					g.setcoordinatetozero(coordinateX, coordinateY);
					g.sethowmanyzombies(g.gethowmanyzombies() - 1);
					cout << "\n\nNumber of zombies:" << g.gethowmanyzombies();

				}
				killedZombiesByDerick.push('L'); // add killed Large zombie to the killedZombiesByDerick Stack
				derick.setScore(derick.getScore() + largeZombie.getScore_per_item());
				cout << "\nTotal Score:" << derick.getScore();
				/*cout << "\nPlayer 1(Derick) killed:";
				if (killedZombiesByDerick.top() == 'L') {
					cout << "\nLarge Zombie";
				}*/
				cout << "\nGrid After Round";
				g.printGrid();
			}
			else if (g.getCharformgrid(coordinateX, coordinateY) == 'M') { // character  M
				cout << "\Medium Zombie's health:" << mediumzombie.getLife();
				cout << "\nDerick's health:" << derick.getLifePoints();
				while (mediumzombie.isDead() != 1) { // if zombie is not dead
					mediumzombie.updateLifePoint(derick.DamageDerick());
					cout << "\nMedium Zombie's health:" << mediumzombie.getLife();
					derick.updateLifePoint(4);
					cout << "\nDerick's health:" << derick.getLifePoints();
				}
				if (mediumzombie.isDead() == 1) {
					g.setcoordinatetozero(coordinateX, coordinateY);
					g.sethowmanyzombies(g.gethowmanyzombies() - 1);
					cout << "\n\nNumber of zombies:" << g.gethowmanyzombies();
				}
				killedZombiesByDerick.push('M'); // add killed zombie to the killedZombiesByDerick Stack
				derick.setScore(derick.getScore() + mediumzombie.getScore_per_item());
				/*cout << "\nPlayer 1(Derick) killed:";
				if (killedZombiesByDerick.top() == 'M') {
					cout << "\nMedium Zombie";
				}*/
				cout << "\nTotal Score:" << derick.getScore();
				cout << "\nGrid After Round";
				g.printGrid();
			}
			else if (g.getCharformgrid(coordinateX, coordinateY) == 'S') { // character  S
				cout << "\nSmall Zombie's health:" << smallzombie.getLife();
				cout << "\nDerick's health:" << derick.getLifePoints();
				while (smallzombie.isDead() != 1) { // if zombie is not dead
					smallzombie.updateLifePoint(derick.DamageDerick());
					cout << "\nSmall Zombie's health:" << smallzombie.getLife();
					derick.updateLifePoint(2);
					cout << "\nDerick's health:" << derick.getLifePoints();
				}
				if (smallzombie.isDead() == 1) {
					g.setcoordinatetozero(coordinateX, coordinateY);
					g.sethowmanyzombies(g.gethowmanyzombies() - 1);
					cout << "\n\nNumber of zombies:" << g.gethowmanyzombies();
				}
				killedZombiesByDerick.push('S'); // add killed zombie to the killedZombiesByDerick Stack
				derick.setScore(derick.getScore() + smallzombie.getScore_per_item());
				/*cout << "\nPlayer 1(Derick) killed:";
				if (killedZombiesByDerick.top() == 'S') {
					cout << "\nSmall Zombie";
				}*/
				cout << "\nTotal Score:" << derick.getScore();
				cout << "\nGrid After Round";
				g.printGrid();
			}
			else if (g.getCharformgrid(coordinateX, coordinateY) == '*') { // character Large Medical Kit	
				derick.setLifePoints(derick.getLifePoints() + 20);
				cout << "\nDerick's health after find Large Medical Kit:" << derick.getLifePoints();
				g.setcoordinatetozero(coordinateX, coordinateY);
				cout << "\n\nGrid After Round";
				g.printGrid();
			}
			else if (g.getCharformgrid(coordinateX, coordinateY) == '+') { // character Small Medical Kit	
				derick.setLifePoints(derick.getLifePoints() + 10);
				cout << "\nDerick's health after find Small Medical Kit:" << derick.getLifePoints();
				g.setcoordinatetozero(coordinateX, coordinateY);
				cout << "\nGrid After Round";
				g.printGrid();
			}
			else if (g.getCharformgrid(coordinateX, coordinateY) == 'A') { // character Ammunition
				derick.setAmmunitions(derick.getAmmunitions() + 10);
				cout << "\nDerick's Ammunition after find Ammunition:" << derick.getLifePoints();
				g.setcoordinatetozero(coordinateX, coordinateY);
				cout << "\nGrid After Round";
				g.printGrid();
			}
			else {
				cout << "You entered wrong coordinates.";
			}
		}
		if (choose == 2) { //if player chooses Chichonne as a Warrior

			cout << "\nPlease enter X coordinate of the Warrior: ";
			cin >> coordinateX;
			cout << "Please enter Y coordinate of the Warrior: ";
			cin >> coordinateY;

			if (g.getCharformgrid(coordinateX, coordinateY) == '0') {
				cout << "Empty Place";
			}
			else if (g.getCharformgrid(coordinateX, coordinateY) == 'L') {  //if there is a Large Zombie at that coordinate
				cout << "\nLarge Zombie's health:" << largeZombie.getLife();
				cout << "\nChichonne's health:" << chichonne.getLifePoints();
				while (largeZombie.isDead() != 1) { // if zombie is not dead
					largeZombie.updateLifePoint(chichonne.DamageChichonne(killedZombiesByChichonne.size()));
					cout << "\nLarge Zombie's health:" << largeZombie.getLife();
					chichonne.updateLifePoint(8);
					cout << "\nChichonne's health:" << chichonne.getLifePoints();
				}

				if (largeZombie.isDead() == 1) {
					g.setcoordinatetozero(coordinateX, coordinateY);
					g.sethowmanyzombies(g.gethowmanyzombies() - 1);
					cout << "\n\nNumber of zombies:" << g.gethowmanyzombies();

				}
				killedZombiesByChichonne.push('L'); // add killed Large zombie to the killedZombiesByChichonne Stack
				chichonne.setScore(chichonne.getScore() + largeZombie.getScore_per_item()); // set Chichonne's Score to current Score + mediumzombie's score per item
				cout << "\nTotal Score:" << chichonne.getScore();
				cout << "\nGrid After Round";
				g.printGrid();
			}
			else if (g.getCharformgrid(coordinateX, coordinateY) == 'M') {  //if there is a Medium Zombie at that coordinate
				cout << "\Medium Zombie's health:" << mediumzombie.getLife();
				cout << "\nChichonne's health:" << chichonne.getLifePoints();
				while (mediumzombie.isDead() != 1) { // if zombie is not dead
					mediumzombie.updateLifePoint(chichonne.DamageChichonne(killedZombiesByChichonne.size()));
					cout << "\nMedium Zombie's health:" << mediumzombie.getLife();
					chichonne.updateLifePoint(4);
					cout << "\nChichonne's health:" << chichonne.getLifePoints();
				}
				if (mediumzombie.isDead() == 1) {
					g.setcoordinatetozero(coordinateX, coordinateY);
					g.sethowmanyzombies(g.gethowmanyzombies() - 1);
					cout << "\n\nNumber of zombies:" << g.gethowmanyzombies();
				}
				killedZombiesByChichonne.push('M'); // add killed zombie to the killedZombiesByChichonne Stack
				chichonne.setScore(chichonne.getScore() + mediumzombie.getScore_per_item()); // set Chichonne's Score to current Score + mediumzombie's score per item
				cout << "\nTotal Score:" << chichonne.getScore();
				cout << "\nGrid After Round";
				g.printGrid();
			}
			else if (g.getCharformgrid(coordinateX, coordinateY) == 'S') { //if there is a Small Zombie at that coordinate
				cout << "\nSmall Zombie's health:" << smallzombie.getLife();
				cout << "\nChichonne's health:" << chichonne.getLifePoints();
				while (smallzombie.isDead() != 1) { // if zombie is not dead
					smallzombie.updateLifePoint(chichonne.DamageChichonne(killedZombiesByChichonne.size()));
					cout << "\nSmall Zombie's health:" << smallzombie.getLife();
					chichonne.updateLifePoint(2);
					cout << "\nChichonne's health:" << chichonne.getLifePoints();
				}
				if (smallzombie.isDead() == 1) {
					g.setcoordinatetozero(coordinateX, coordinateY); // set that coordinate to 0
					g.sethowmanyzombies(g.gethowmanyzombies() - 1);
					cout << "\n\nNumber of zombies:" << g.gethowmanyzombies();
				}
				killedZombiesByChichonne.push('S'); // add killed zombie to the killedZombiesByChichonne Stack
				chichonne.setScore(chichonne.getScore() + smallzombie.getScore_per_item()); // set Chichonne's Score to current Score + smallzombie's score per item
				cout << "\nTotal Score:" << chichonne.getScore();
				cout << "\nGrid After Round";
				g.printGrid();
			}
			else if (g.getCharformgrid(coordinateX, coordinateY) == '*') { //if there is a Large Medical Kit at that coordinate
				chichonne.setLifePoints(chichonne.getLifePoints() + 20); // set new life point to current life point + 20
				cout << "\nChichonne's health after find Large Medical Kit:" << chichonne.getLifePoints();
				g.setcoordinatetozero(coordinateX, coordinateY); // set that coordinate to 0
				cout << "\n\nGrid After Round";
				g.printGrid(); // print Grid After Round
			}
			else if (g.getCharformgrid(coordinateX, coordinateY) == '+') { //if there is a Small Medical Kit at that coordinate
				chichonne.setLifePoints(chichonne.getLifePoints() + 10);  // set new life point to current life point + 10
				cout << "\nChichonne's health after find Small Medical Kit:" << chichonne.getLifePoints();
				g.setcoordinatetozero(coordinateX, coordinateY); // set that coordinate to 0
				cout << "\nGrid After Round";
				g.printGrid();  // print Grid After Round
			}
			else if (g.getCharformgrid(coordinateX, coordinateY) == 'A') { //if there is a Ammunition at that coordinate
				chichonne.setAmmunitions(chichonne.getAmmunitions() + 10);  // set new Ammunitions to Ammunitions point + 10
				cout << "\nChichonne's Ammunition after find Ammunition:" << chichonne.getLifePoints();
				g.setcoordinatetozero(coordinateX, coordinateY); // set that coordinate to 0
				cout << "\nGrid After Round"; 
				g.printGrid();  // print Grid After Round
			}
			else {
				cout << "You entered wrong coordinates.";
			}
		}

	}
	
	if (g.gethowmanyzombies() == 0) {

		cout << "\n\n\nPlayer 1(Derick) killed:";
	
		while(killedZombiesByDerick.size()!=0){
			char topss = '0';
			topss = killedZombiesByDerick.top();

			if (topss =='S') {
				cout << "\nSmall Zombie";
			}
		
			if (topss == 'L') {
				cout << "\nLarge Zombie";
			}
			if (topss == 'M') {
				cout << "\nMedium Zombie";
			}
			killedZombiesByDerick.pop();
		}
		cout << "\n\nTotal Score:" << derick.getScore();

		cout << "\n\n\nPlayer 2(Chichonne) killed:";
		while (killedZombiesByChichonne.size() != 0) {
			char topss = '0';
			topss = killedZombiesByChichonne.top();

			if (topss == 'S') {
				cout << "\nSmall Zombie";
			}

			if (topss == 'L') {
				cout << "\nLarge Zombie";
			}
			if (topss == 'M') {
				cout << "\nMedium Zombie";
			}
			killedZombiesByChichonne.pop();
		}
		cout << "\n\nTotal Score:" << chichonne.getScore();
		cout << "\n";
	}

}