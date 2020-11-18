/*
* Author: Katharina Tinbergen
*
* cpp of program, including class and none-class/support methods
*
* 16.11.2020 v1
*/

#include "Liwanze.h"
#include <iostream>
using std::cout;
using std::cin;



Liwanze::Liwanze(const string& name, const Region& loc): name {name}, loc{loc} 
{}

string Liwanze::getName() const
{
	return name;
}

Liwanze::Region Liwanze::getLoc() const
{
	return loc;
}
 
void Liwanze::print()
{
	cout << "\nName: " << this->name << ", region: " << regionToString(this->loc);
	
}

void Liwanze::printWithConnections()
{
	this->print();
	printTierOne();
}

bool Liwanze::connects(const string& connectTo)
{
	for(string name: this->connectsTo)
	{
		if (name == connectTo) { return true; }
	}
	return false;
}

bool Liwanze::connected(const string& connectFrom)
{
	for (string name : this->connectedFrom)
	{
		if (name == connectFrom) { return true; }
	}
	
	return false;
}

void Liwanze::printTierOne()
{
	cout << std::endl << this->name << " connects to: ";
	for (string connTo : this->connectsTo)
	{
		cout << connTo << ", ";
	}
	cout << std::endl << this->name << " connects from: ";
	for (string connFrom : this->connectedFrom)
	{
		cout << connFrom << ", ";
	}
}

bool Liwanze::addConnTo(const string& connectTo)
{
	if (this->connects(connectTo))
	{
		cout << "\nConnection already exists.\n";
		return false; 
	}
	else
	{
		this->connectsTo.push_back(connectTo);
		return true; 
	}
}

bool Liwanze::addConnFrom(const string& connectFrom)
{
	if (this->connected(connectFrom))
	{
		cout << "\nConnection already exists.\n";
		return false;
	}
	else
	{
		this->connectedFrom.push_back(connectFrom);
		return true;
	}
}

void populate(std::list<Liwanze>& vL)
{
	vL.push_back(Liwanze("Joey", Liwanze::Region(1)));
	vL.push_back(Liwanze("Johnny", Liwanze::Region(1)));
	vL.push_back(Liwanze("DeeDee", Liwanze::Region(1)));
	vL.push_back(Liwanze("Tommy", Liwanze::Region(3)));
	vL.push_back(Liwanze("Suzy", Liwanze::Region(2)));
	vL.push_back(Liwanze("Sheena", Liwanze::Region(1)));
}

void printLVZMembers(const std::list<Liwanze>& vL)
{
	for (Liwanze liwanze: vL)
	{
		liwanze.print();
	}
}

bool isUnique(const std::list<Liwanze>& vL, const string& newName)
{
	for (Liwanze liwanze : vL)
	{
		if (liwanze.getName() == newName) return false;
	}
	return true;
}

void addLiwanze(std::list<Liwanze>& vL)
{
	string inputName{};
	cout << "\nYou may now add as many people as you wish to have the insurmountable pleasure of owning a Liwanze. Please type 'q' and press enter when you are finished.";

	while (inputName != "q")
	{
		cout << "\nPlease add a name. Interrupt with 'q'. Press enter to confirm. \n>";
		cin >> inputName;
		if (!cin) throw std::runtime_error{ "Incorrect input at addLiwanze()" };
		
		if (!isUnique(vL, inputName)) {
			cout << "\n" << inputName << " already owns a Liwanze. Please consider giving the Liwanze to someone else.\n";
		}
		else if(inputName != "q") {
			vL.push_back(Liwanze(inputName, Liwanze::Region(0))); 
			cout << std::endl << inputName << " thanks you for the gift.\n";
			cout << "\n----- These people now own a Liwanze-----";
			printLVZMembers(vL);
			cout << std::endl;
		}
	}
}

void makeConnections(Liwanze& connectsFrom, Liwanze& connectsTo)
{
	if (
		connectsFrom.addConnTo(connectsTo.getName()) == true
		&&
		connectsTo.addConnFrom(connectsFrom.getName()) == true
		)
	{
		cout << "\nConnection has been established.\n";
	}
}

void initConnections(std::list<Liwanze>& vL)
{
	for (Liwanze& liwanze : vL)
	{
		if (liwanze.getName() == "Joey")
		{
			liwanze.addConnTo("Johnny");
			liwanze.addConnTo("DeeDee");
			liwanze.addConnTo("Suzy");
			liwanze.addConnTo("Sheena");
		}
		if (liwanze.getName() == "Johnny")
		{
			liwanze.addConnTo("Joey");
			liwanze.addConnTo("Suzy");
		}
		if (liwanze.getName() == "DeeDee")
		{
			liwanze.addConnTo("Suzy");
		}
		if (liwanze.getName() == "Tommy")
		{
			liwanze.addConnTo("Suzy");
		}
		if (liwanze.getName() == "Sheena")
		{
			liwanze.addConnTo("Joey");
		}

		if (liwanze.getName() == "Joey")
		{
			liwanze.addConnFrom("Johnny");
			liwanze.addConnFrom("Sheena");
		}
		if (liwanze.getName() == "Johnny")
		{
			liwanze.addConnFrom("Joey");
		}
		if (liwanze.getName() == "DeeDee")
		{
			liwanze.addConnFrom("Joey");
		}
		if (liwanze.getName() == "Suzy")
		{
			liwanze.addConnFrom("Joey");
			liwanze.addConnFrom("Johnny");
			liwanze.addConnFrom("DeeDee");
			liwanze.addConnFrom("Tommy");
		}
		if (liwanze.getName() == "Sheena")
		{
			liwanze.addConnFrom("Joey");
		}
	}
}

void addConnection(std::list<Liwanze>& vL)
{
	string inputLiwanzeName1{};
	string inputLiwanzeName2{};

	cout << "\nYou may now add pairs of two people whom you wish to establish a connection between.";


	while (true)
	{
		cout << "\nPlease add the first name. Exit by entering 'q'. Confirm by pressing enter. \n>";
		cin >> inputLiwanzeName1;
		if (!cin) throw std::runtime_error{ "incorrect input at addConnection()" };
		cout << "Please add the second name. Exit by entering 'q'. Confirm by pressing enter. \n>";
		cin >> inputLiwanzeName2;
		if (!cin) throw std::runtime_error{ "incorrect input at addConnection()" };

		if (inputLiwanzeName1 != "q" && inputLiwanzeName2 != "q")
		{
			Liwanze& liwanze1{  findLiwanze(vL, inputLiwanzeName1) };
			Liwanze& liwanze2{ findLiwanze(vL, inputLiwanzeName2) };

			makeConnections(liwanze1, liwanze2);
			liwanze1.printWithConnections();
			liwanze2.printWithConnections();
			cout << std::endl; 
			 
		}
		else { break;  }
		
	}
	
}

Liwanze& findLiwanze(std::list<Liwanze>& vL, const string& name)
{
	for (Liwanze& liwanze : vL) {
		if (liwanze.getName() == name) { return liwanze; }
	}
	cout << std::endl << name << " does not exist.\n";
}

void printConnections(std::list<Liwanze>& vL)
{
	for (Liwanze& liwanze : vL) { liwanze.printWithConnections(); }
}

const string regionToString(Liwanze::Region& region)
{
	switch (region)
	{
	case 0:
		return "region not defined";
	case 1: 
		return "America";
	case 2: 
		return "Asia Pacific";
	case 3: 
		return "Europe, Middle East and Africa";
	}
	return string();
}
