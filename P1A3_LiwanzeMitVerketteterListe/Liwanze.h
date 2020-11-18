/*
* Author: Katharina Tinbergen
*
* header of program, including class and none-class/support methods
*
* 16.11.2020 v1
*/

#include <string>
using std::string; 
#include <vector>
#include <list>


#ifndef LIWANZE_H
#define LIWANZE_H

class Liwanze {

public:
	//Task 1
	enum Region {ndef = 0, amer = 1, apac = 2, emea = 3};

	Liwanze(const string& name, const Region& loc); //constructor
	string getName() const; 
	Region getLoc() const;
	void print(); //prints name and location of object

	//Task 2
	bool connects(const string& connectTo);		//returns whether the person to be added to the connectesTo list is already in the list
	bool connected(const string& connectFrom);	//returns whether the person to be added to the connectedFrom list is already in the list
	void printTierOne();						//Prints connections
	bool addConnTo(const string& connectTo);	//changed from void to bool (different than in task) //adds a Person to the connectsTo list
	bool addConnFrom(const string& connectFrom);//changed from void to bool (different than in task) //adds a Person to the connectedFrom list

	//My methods
	void printWithConnections();				//prints owner including Name, Region and connections


private:
	//Task 1
	string name;
	Region loc; 
	Liwanze() = delete;

	//Task 2
	std::list<string> connectsTo;		//list of people the Liwanze connectsTo
	std::list<string> connectedFrom;	//list of people the Liwanze connectsFrom
};



//support functions

//Task 1
void populate(std::list<Liwanze>& vL);								//pupulate list from main with Liwanzen-owners
void printLVZMembers(const std::list<Liwanze>& vL);					//print names and regions of all members of list from main 
bool isUnique(const std::list<Liwanze>& vL, const string& newName); //check if a new owner is already in list
void addLiwanze(std::list<Liwanze>& vL);							//user to add new owner to list, defining the name of the user on the fly

//Task 2
void makeConnections(Liwanze& connectsFrom, Liwanze& connectsTo);	//establishes a connection (to or from) between two users
void initConnections(std::list<Liwanze>& vL);						//innitialize existing connection of users added to list in populate()
void addConnection(std::list<Liwanze>& vL);							//user to add a connection (from or to) two Liwanzen owners

//My custom support functions
Liwanze& findLiwanze(std::list<Liwanze>& vL, const string& name);	//finds a Liwanzen-owner of the list by their name and returns the Liwanze
void printConnections(std::list<Liwanze>& vL);						//prints the Names, Regions and connections of all owners in the list
const string regionToString(Liwanze::Region& region);				//returns the string of the enum Region()

#endif // !LIWANZE_H
