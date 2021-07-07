/*  Ezgi Diþbudak 2243400
	I read and accept the submission rules and the extra rules specified in each question.This is my own work that is
	done by myself only.*/

#include <iostream>
#include "EuroleagueTeamFanclub.h"

using std::cout;
using std::cin;

int main()
{

	/*Sample Run 1*/
	//EuroleagueTeamFanclub e1("Anadolu Efes", 2021, 'P', "Turkey", 2521);
	//EuroleagueTeamFanclub e2("Anadolu Efes", 2022, 'P', "Turkey", 2521);

	/*Sample Run 2*/
	EuroleagueTeamFanclub e1("Anadolu Efes", 2021, 'P', "Turkey", 2521);
	EuroleagueTeamFanclub e2("Anadolu Efes", 2022, 'P', "Turkey", 2712);

	/*Other example*/
	//EuroleagueTeamFanclub e1("dsadsa", 2021, 'P', "Turkey", 2521);
	//EuroleagueTeamFanclub e2("Anadolu Efes", 2022, 'P', "Turkey", 2712);
	
	e1.differences(e2);

	cout << "\n";
	cout << "\nE1:";
	//cout << "\n";
	e1.printClub();
	cout << "\n";
	cout << "\nE2:";
	//cout << "\n";
	e2.printClub();
	cout << "\n";

	e1.addFan(2);
	

	return 0;

}
