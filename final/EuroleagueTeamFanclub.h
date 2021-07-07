#ifndef EUROLEAGUETEAMFANCLUB_H
#define EUROLEAGUETEAMFANCLUB_H

using std::cout;
using std::cin;
using std::strcpy;
using std::endl;
class EuroleagueTeamFanclub
{
private:
	const char* The_name_of_the_team;
	double year;
	char condition;
	const char* originCountry;
	int NumberOfMembers;


public:
	EuroleagueTeamFanclub() { //Default Constructor

	/*The_name_of_the_team = new char[50];
	strcpy(The_name_of_the_team, "None");*/
		The_name_of_the_team = "None";
		year = 0000;
		condition = 'A';
		/*originCountry = new char[30];
		strcpy(originCountry, "None");*/
		originCountry = "None";
		NumberOfMembers = 0;
	}

	EuroleagueTeamFanclub(const char* name, double year, char condition, const char* origincountry, int member) {
		/*this->The_name_of_the_team = new char[50];
		strcpy(this->The_name_of_the_team, name);*/
		this->The_name_of_the_team = name;
		this->year = year;
		this->condition = condition;
		this->originCountry = origincountry;
		/*this->originCountry = new char[30];
		strcpy(this->originCountry, origincountry);*/
		this->NumberOfMembers = member;
	}
	EuroleagueTeamFanclub(const EuroleagueTeamFanclub& team) { //Copy constructor
		/*The_name_of_the_team = new char[50];
		strcpy(this->The_name_of_the_team, team.The_name_of_the_team);*/
		this->The_name_of_the_team = team.The_name_of_the_team;
		year = team.year;
		condition = team.condition;
		/*originCountry = new char[30];
		strcpy(originCountry, team.originCountry);*/
		this->originCountry = team.originCountry;
		NumberOfMembers = team.NumberOfMembers;
		//cout << "EuroleagueTeamFanclub(const EuroleagueTeamFanclub& std) has been called!" << endl;
	}

	~EuroleagueTeamFanclub() { //Destructor
		//delete[] The_name_of_the_team;
		//cout << "~Student() has been called!" << endl;
	}

	void differences(EuroleagueTeamFanclub team) {

		if (The_name_of_the_team != team.getThe_name_of_the_team()) {
			cout << "\nThe name of the team is different.";
		}
		if (year != team.getYear()) {
			cout << "\nThe year is different.";
		}
		if (condition != team.getCondition()) {
			cout << "\nThe condition is different.";
		}
		if (originCountry != team.getOriginCountry()) {
			cout << "\nThe origin country is different.";
		}
		if (NumberOfMembers != team.getNumberOfMembers()) {
			cout << "\nThe number of fans is different";
		}

	}
	void addFan(int numberofmembers) {
		NumberOfMembers = NumberOfMembers + numberofmembers; //increament numberof members with the given number
	}

	/*Print details of the club*/
	void printClub() {
		cout << "\nTeam Name:" << The_name_of_the_team;
		cout << "\nYear:" << year;
		if (condition == 'P') {
			cout << "\nCondition: Pandemic continues";
		}
		if (condition == 'S') {
			cout << "\nnCondition: Open for supporters:";
		}
		cout << "\nCountry:" << originCountry;
		cout << "\nThe Number of Members:" << NumberOfMembers;
	}


	// Getters and Setters
	void setThe_name_of_the_team(const char* name) {
		/*this->The_name_of_the_team = new char[30];
		strcpy(this->The_name_of_the_team, name);*/
		this->The_name_of_the_team = name;
	}
	const char* getThe_name_of_the_team() {
		return The_name_of_the_team;
	}

	void setYear(double year) {
		this->year = year;
	}
	double getYear() {
		return year;
	}

	void setCondition(char condition) {
		this->condition = condition;
	}
	char getCondition() {
		return condition;
	}

	void setOriginCountry(const char* country) {
		/*this->originCountry = new char[30];
		strcpy(this->originCountry, country);*/
		this->originCountry = country;

	}
	const char* getOriginCountry() {
		return originCountry;
	}

	void setNumberOfMembers(int member) {
		this->NumberOfMembers = member;
	}
	int getNumberOfMembers() {
		return NumberOfMembers;
	}

};
#endif

