/*
 * main.cpp
 *
 *  Created on: Mar 31, 2022
 *      Author: jun
 */
// Fehler: keine Headdatei beinhalten
#include "Date.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void compareDate(int cmpflg)
{
	switch(cmpflg)
	{
	case 1:
		cout << "Date2 is before Date1.\n" << endl;
		break;
	case 0:
		cout << "Date2 is the same as Date1.\n" << endl;
		break;
	case -1:
		cout << "Date2 is after Date1.\n" << endl;
		break;
	default:
		cout << "Error" << endl;
	}
}


int main()
{
	srand(time(nullptr));

	Date d1 = Date();
	d1.printDate();

	Date d2 = Date();
	d2.printDate();

	compareDate(d1.compare(d2));


	Date d3 = Date();
	d3.printDate();

	Date d4 = Date();
	d4.printDate();

	compareDate(d3.compare(d4));

	Date d5 = Date();
	d5.printDate();

	Date d6 = Date();
	d6.printDate();

	compareDate(d5.compare(d6));

	return 0;
}
