/*
* Author: Katharina Tinbergen
* 
* this program enables users to hand out presents (in form of a czech dish called "Liwanze") to people
* and to enble the user to define to whom the Liwanze connects to (whom may eat it) and from whom it comes (who gave it away). Both may hold more than 1 person. 
* 
* 16.11.2020 v1
*/

#include <exception>
#include <iostream>
#include "Liwanze.h"
#include <list>

int main() try
{
	std::list<Liwanze> vL{};

	populate(vL);
	addLiwanze(vL);
	initConnections(vL);
	addConnection(vL);
	printConnections(vL);

	return 0;
}
catch (const std::exception& e)
{
	std::cerr << e.what(); 
	return -1;
}
catch (...)
{
	std::cerr << "unknown error";
	return -99;
}