/*
 * main.cpp
 *
 *  Created on: Apr 3, 2022
 *      Author: jun
 */

#include "ncurses.h"
#include <string>
#include <list>
#include <iostream>
using namespace std;

// install the ncurses library (via Linux terminal or .tar)
// include "ncurses.h" in .cpp script
// go to file->properties, setup the linker between .cpp and the ncurses-library
// -- following the steps on page 91 of PraSkript
// build the project
// run the project in Linux terminal
// --$ cd ... to the project file
// --$ cd Debug
// --$ ls to ensure <ProjectName> in Debug folder
// --$ ./<ProjectName> to run the program on the Linux terminal


int main()
{
	// user input several chars via loop
	// store chars in a list
	// as soon as a char is input, delete the current prints on the console
	// the input char should be stored in the list and be printed on the console
	// no input, no print in console
	// input 'q' to quite the input

	int iAscii = 0;
	list<char> chInLs;

	initscr();
	nodelay(stdscr, TRUE);
	noecho();

	printw("Input char, it will be displayed simultaneously.\nInput 'q' to quit. All would be printed.");

	while(iAscii != 113) // ASCII 'q'
	{
		iAscii = getch();

		if (iAscii != -1) // input is not blank
		{
			clear();
			printw("Input is: %c", iAscii);
			chInLs.push_back(iAscii);
		}
		else
		{
			continue;
		}
	}
	endwin();

	cout << "Input ended. Now print:\nindex) char\n-----------" << endl;
	list<char>::iterator iter;
	int idx = 0;
	for(iter = chInLs.begin(); iter != chInLs.end(); iter ++)
	{
		idx ++;
		cout << idx << ") " << *iter << endl;
		// iter cannot directly cout here.
		// because iter is NOT of a common data type, iter is of type list<char>::iterator.
		// iter can be processed normally in the code, but cannot be taken by iostream.
	}

	return 0;
}
