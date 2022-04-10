/*
 * test.cpp
 *
 *  Created on: Apr 4, 2022
 *      Author: jun
 */

#include <string>
#include "ncurses.h"

int main ()
{
	initscr();
	raw();
	noecho();
	curs_set(0);

	printw("Hello!");
	refresh();

	getch();
	endwin();

	return 0;
}


