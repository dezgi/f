/* Hilal Bölük – 2243350
I read and accept the submission rules and the important section specified in assignment file.
This is my own work that is done by myself and my team-mate only */

#ifndef GRID_H
#define GRID_H
#include<iostream>
#include "Entities.h"
#include"Resources.h"
#include"Warriors.h"
#include"Zombies.h"

using namespace std;

class Grid {
private:
	int n;
	char **gridmap;
	int howmanyzombies;
	int howmanymedicine;
	int howmanyammunition;


public:
	//getters and setters
	int getn() {
		return this->n;
	}
	void setn(int n) {
		this->n = n;
	}
	int gethowmanyzombies() {
		return this->howmanyzombies;
	}
	void sethowmanyzombies(int howmanyzombies) {
		this->howmanyzombies = howmanyzombies;
	}
	int gethowmanymedicine() {
		return this->howmanymedicine;
	}
	void sethowmanymedicine(int howmanymedicine) {
		this->howmanymedicine = howmanymedicine;
	}
	int gethowmanyammunition() {
		return this->howmanyammunition;
	}
	void sethowmanyammunition(int howmanyammunition) {
		this->howmanyammunition = howmanyammunition;
	}

	//generates a random number 1 to n (grid size 'nxn').
	int getrandomn() {
		int x = ((rand() % n) + 1);
		return x;
	}

	//if the player does not enter an n value, it creates 5x5 grid as default
	Grid() {
		int answer_n;
		cout << "\nEnter grid size: ";
		cin >> answer_n;
		setn(answer_n);
		//the grid should be at least  5x5 according to asssignment description so the n value is less than 5, it calls the grid function with 5
		if (n < 5) {
			Grid(5);
		}
		else {
			gridmap = Gridinitialize(answer_n);
			for (int i = 0;i < answer_n;i++) {
				for (int j = 0; j < answer_n;j++) {
					gridmap[i][j] = '0';
				}
			}
		}
	}
	Grid(int a) {
		gridmap = Gridinitialize(a);
		for (int i = 0;i < a;i++) {
			for (int j = 0; j < a;j++) {
				gridmap[i][j] = '0';
			}
		}

	}
	char **Gridinitialize(int newn) {
		char* v = (char*)malloc(newn * newn * sizeof(char));
		char** p = (char**)malloc(newn * sizeof(char*));
		for (int i = 0;i < newn;i++) {
			p[i] = &v[i * newn];
		}
		return p;
	
	}

	/*Deploy function of the grid. 
	Calculates the number of medicines, zombies , and ammunition according to 'n' of grid randomly.
	For putting them on the grid randomly, for x and y coordinate, we call the getrandom function to get a random number and then if that cell is empty we put value there,
	if that cell is not empty, we generate new set of random numbers until we found the empty cell.
	If the calculated zombie number is less than 3, it still creates 3 zombies because according to assignment there should be at least one of the zombie from
	each type of zombie. Therefore, even if the calculated number is 2, it's fixed to 3 to put all types of zombies in the grid. If it's more than 3,
	it puts one large and one medium zombie into grid and put small zombies until the number of zombies we need to put into grid becomes 0.
	Same logic applies for putting resources as well.
	*/
	void Deploy() {
		int temp_x, temp_y;
		sethowmanyzombies((2 * ((n * n) / 25)));
		sethowmanymedicine((3 * ((n * n) / 25)));
		sethowmanyammunition((2 * ((n * n) / 25)));
		int tempzombienumber = gethowmanyzombies();
		int tempmedicinenumber = gethowmanymedicine();
		int tempammunitionnumber = gethowmanyammunition();

		if (tempzombienumber < 3) {
			sethowmanyzombies(3); //there should be at least 3 of zombies in the grid.
			Large_Zombie lzombie;
			temp_x = getrandomn();
			temp_y = getrandomn();
			if (getCharformgrid(temp_x, temp_y) == '0') {
				lzombie.setx(temp_x);
				lzombie.sety(temp_y);
				gridmap[temp_x - 1][temp_y - 1] = 'L';
			}
			else {
				int newy = findemptycol(temp_x);
				int newx = findemptyrow(temp_y);
				if (newy != -1) {
					lzombie.setx(temp_x);
					lzombie.sety(newy);
					gridmap[temp_x - 1][newy - 1] = 'L';
				}
				else if (newx != -1) {
					lzombie.setx(newx);
					lzombie.sety(temp_y);
					gridmap[newx - 1][temp_y - 1] = 'L';
				}
			}
			Medium_Zombie mzombie;
			temp_x = getrandomn();
			temp_y = getrandomn();
			if (getCharformgrid(temp_x, temp_y) == '0') {
				mzombie.setx(temp_x);
				mzombie.sety(temp_y);
				gridmap[temp_x - 1][temp_y - 1] = 'M';
			}
			else {
				int newy = findemptycol(temp_x);
				int newx = findemptyrow(temp_y);
				if (newy != -1) {
					mzombie.setx(temp_x);
					mzombie.sety(newy);
					gridmap[temp_x - 1][newy - 1] = 'M';
				}
				else if (newx != -1) {
					mzombie.setx(newx);
					mzombie.sety(temp_y);
					gridmap[newx - 1][temp_y - 1] = 'M';
				}
			}
			Small_Zombie szombie;
			temp_x = getrandomn();
			temp_y = getrandomn();
			if (getCharformgrid(temp_x, temp_y) == '0') {
				szombie.setx(temp_x);
				szombie.sety(temp_y);
				gridmap[temp_x - 1][temp_y - 1] = 'S';
			}
			else {
				int newy = findemptycol(temp_x);
				int newx = findemptyrow(temp_y);
				if (newy != -1) {
					szombie.setx(temp_x);
					szombie.sety(newy);
					gridmap[temp_x - 1][newy - 1] = 'S';
				}
				else if (newx != -1) {
					szombie.setx(newx);
					szombie.sety(temp_y);
					gridmap[newx - 1][temp_y - 1] = 'S';
				}
			}
		}
		//if there are more than 3 zombies in the game, creates 1 large zombie and 1 medium zombie and then creates small zombies for the rest
		else {
			Large_Zombie lzombie;
			temp_x = getrandomn();
			temp_y = getrandomn();
			if (getCharformgrid(temp_x, temp_y) == '0') {
				lzombie.setx(temp_x);
				lzombie.sety(temp_y);
				gridmap[temp_x - 1][temp_y - 1] = 'L';
				tempzombienumber--;
			}
			else {
				int newy = findemptycol(temp_x);
				int newx = findemptyrow(temp_y);
				if (newy != -1) {
					lzombie.setx(temp_x);
					lzombie.sety(newy);
					gridmap[temp_x - 1][newy - 1] = 'L';
					tempzombienumber--;
				}
				else if (newx != -1) {
					lzombie.setx(newx);
					lzombie.sety(temp_y);
					gridmap[newx - 1][temp_y - 1] = 'L';
					tempzombienumber--;
				}
			}
			Medium_Zombie mzombie;
			temp_x = getrandomn();
			temp_y = getrandomn();
			if (getCharformgrid(temp_x, temp_y) == '0') {
				mzombie.setx(temp_x);
				mzombie.sety(temp_y);
				gridmap[temp_x - 1][temp_y - 1] = 'M';
				tempzombienumber--;
			}
			else {
				int newy = findemptycol(temp_x);
				int newx = findemptyrow(temp_y);
				if (newy != -1) {
					mzombie.setx(temp_x);
					mzombie.sety(newy);
					gridmap[temp_x - 1][newy - 1] = 'M';
					tempzombienumber--;
				}
				else if (newx != -1) {
					mzombie.setx(newx);
					mzombie.sety(temp_y);
					gridmap[newx - 1][temp_y - 1] = 'M';
					tempzombienumber--;
				}
			}
			while (tempzombienumber != 0) {
				Small_Zombie szombie;
				temp_x = getrandomn();
				temp_y = getrandomn();
				if (getCharformgrid(temp_x, temp_y) == '0') {
					szombie.setx(temp_x);
					szombie.sety(temp_y);
					gridmap[temp_x - 1][temp_y - 1] = 'S';
					tempzombienumber--;

				}
				else {
					int newy = findemptycol(temp_x);
					int newx = findemptyrow(temp_y);
					if (newy != -1) {
						szombie.setx(temp_x);
						szombie.sety(newy);
						gridmap[temp_x - 1][newy - 1] = 'S';
						tempzombienumber--;

					}
					else if (newx != -1) {
						szombie.setx(newx);
						szombie.sety(temp_y);
						gridmap[newx - 1][temp_y - 1] = 'S';
						tempzombienumber--;

					}
				}
			}
		}
		if (tempmedicinenumber < 2) {
			Large_Medicine_Kit largemedicine;
			sethowmanyammunition(2);
			temp_x = getrandomn();
			temp_y = getrandomn();
			if (getCharformgrid(temp_x, temp_y) == '0') {
				largemedicine.setx(temp_x);
				largemedicine.sety(temp_y);
				gridmap[temp_x - 1][temp_y - 1] = '*';
			}
			else {
				int newy = findemptycol(temp_x);
				int newx = findemptyrow(temp_y);
				if (newy != -1) {
					largemedicine.setx(temp_x);
					largemedicine.sety(newy);
					gridmap[temp_x - 1][newy - 1] = '*';
				}
				else if (newx != -1) {
					largemedicine.setx(newx);
					largemedicine.sety(temp_y);
					gridmap[newx - 1][temp_y - 1] = '*';
				}
			}
			Small_Medicine_Kit smallmedicine;
			temp_x = getrandomn();
			temp_y = getrandomn();
			if (getCharformgrid(temp_x, temp_y) == '0') {
				smallmedicine.setx(temp_x);
				smallmedicine.sety(temp_y);
				gridmap[temp_x - 1][temp_y - 1] = '+';
			}
			else {
				int newy = findemptycol(temp_x);
				int newx = findemptyrow(temp_y);
				if (newy != -1) {
					smallmedicine.setx(temp_x);
					smallmedicine.sety(newy);
					gridmap[temp_x - 1][newy - 1] = '+';
				}
				else if (newx != -1) {
					smallmedicine.setx(newx);
					smallmedicine.sety(temp_y);
					gridmap[newx - 1][temp_y - 1] = '+';
				}
			}
	}

		//if there are more than two kits
		else {
			while (tempmedicinenumber != 0) {
				Large_Medicine_Kit largemedicine;
				temp_x = getrandomn();
				temp_y = getrandomn();
				if (getCharformgrid(temp_x, temp_y) == '0') {
					largemedicine.setx(temp_x);
					largemedicine.sety(temp_y);
					gridmap[temp_x - 1][temp_y - 1] = '*';
					tempmedicinenumber--;
				}
				else {
					int newy = findemptycol(temp_x);
					int newx = findemptyrow(temp_y);
					if (newy != -1) {
						largemedicine.setx(temp_x);
						largemedicine.sety(newy);
						gridmap[temp_x - 1][newy - 1] = '*';
						tempmedicinenumber--;

					}
					else if (newx != -1) {
						largemedicine.setx(newx);
						largemedicine.sety(temp_y);
						gridmap[newx - 1][temp_y - 1] = '*';
						tempmedicinenumber--;

					}
				}
				if(tempmedicinenumber!=0){
				Small_Medicine_Kit smallmedicine;
				temp_x = getrandomn();
				temp_y = getrandomn();
				if (getCharformgrid(temp_x, temp_y) == '0') {
					smallmedicine.setx(temp_x);
					smallmedicine.sety(temp_y);
					gridmap[temp_x - 1][temp_y - 1] = '+';
					tempmedicinenumber--;

				}
				else {
					int newy = findemptycol(temp_x);
					int newx = findemptyrow(temp_y);
					if (newy != -1) {
						smallmedicine.setx(temp_x);
						smallmedicine.sety(newy);
						gridmap[temp_x - 1][newy - 1] = '+';
						tempmedicinenumber--;

					}
					else if (newx != -1) {
						smallmedicine.setx(newx);
						smallmedicine.sety(temp_y);
						gridmap[newx - 1][temp_y - 1] = '+';
						tempmedicinenumber--;
					}
					
				}
			}
			}
		}
		while (tempammunitionnumber != 0) {
			Ammunition ammunition_pack;
			temp_x = getrandomn();
			temp_y = getrandomn();
			if (getCharformgrid(temp_x, temp_y) == '0') {
				ammunition_pack.setx(temp_x);
				ammunition_pack.sety(temp_y);
				gridmap[temp_x - 1][temp_y - 1] = 'A';
				tempammunitionnumber--;
			}
			else {
				int newy = findemptycol(temp_x);
				int newx = findemptyrow(temp_y);
				if (newy != -1) {
					ammunition_pack.setx(temp_x);
					ammunition_pack.sety(newy);
					gridmap[temp_x - 1][newy - 1] = 'A';
					tempammunitionnumber--;

				}
				else if (newx != -1) {
					ammunition_pack.setx(newx);
					ammunition_pack.sety(temp_y);
					gridmap[newx - 1][temp_y - 1] = 'A';
					tempammunitionnumber--;

				}
			}
		}
	}

	//accordding to x value returns the empty space's y value
	int findemptycol(int tempx) {
			for (int j = 0;j < n;j++) {
				if (gridmap[tempx-1][j] == '0') return j;
				else return -1;
		}
	}
	//accordding to y value returns the empty space's x value
	int findemptyrow(int tempy) {
		for (int i =0;i < n;i++) {
				if (gridmap[i][tempy-1] == '0') return i;
				else return -1;
		}
	}
	//prints grid
	void printGrid() {
		cout << "\n\n---------------------------------------------------\n";
		for (int i = 0;i < getn();i++) {
			for (int j = 0;j < getn();j++) {
				cout << "| " << gridmap[i][j]; cout << " |";
			}
			cout << "\n";
		}
		cout << "---------------------------------------------------\n";
	}
	

	//according to given x y coordinates returns the character in that position.
	char getCharformgrid(int x, int y) {
		return gridmap[x - 1][y - 1];
	}


	//set the coordinate to 0, after a zombie died or a resource is used.
	void setcoordinatetozero(int x, int y) {
		gridmap[x - 1][y - 1] = '0';
	}
};

#endif