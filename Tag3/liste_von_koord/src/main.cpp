/*
 * main.cpp
 *
 *  Created on: Apr 3, 2022
 *      Author: jun
 */

#include "Coord.hpp"
#include "printlist.hpp"
#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
#include "delcoords.hpp"
using namespace std;

int main()
{
	srand((unsigned)(time(nullptr)));
	list<Coord> origLs;

	// Create a coord-list
	for(int i = 0; i < 10; i++)
	{
		float inX = (float)(rand() / (float)(RAND_MAX/100));
		float inY = (float)(rand() / (float)(RAND_MAX/100));

		origLs.push_front(Coord(inX, inY));
	}

	// Print the original coord-list
	cout << "\nThe created coord-list: " << endl;
	printlist(&origLs);

	// Backup
	list<Coord> backupLs(origLs.begin(), origLs.end());

	// Delete coords in which x < y
	origLs = delcoords(origLs);

	// Print the modified and the original backup coord-list
	cout << "\nThe modified coord-list: " << endl;
	printlist(&origLs);
	cout << "\nThe backup of original coord-list: " << endl;
	printlist(&backupLs);

	return 0;
}
