/*
 * main.cpp
 *
 *  Created on: Mar 31, 2022
 *      Author: jun
 */

#include "Vehicle.h"
#include <string>
#include <iostream>

void printIfOldtimer(Vehicle car)
{
	if(Vehicle::isOldtimer(car) == true)
	{cout << "p.s. an old-timer." << endl;}
	else
	{cout << "p.s. NOT an old-timer." << endl;}
}

int main()
{
	// Input the car information in the form of (build-year, price); color is randomly initialized.
	Vehicle car1 = Vehicle(1980, 23.3);
	car1.printInfo();
	printIfOldtimer(car1);

	Vehicle car2 = Vehicle(1972, 12.5);
	car2.printInfo();
	printIfOldtimer(car2);

	Vehicle car3 = Vehicle(2021, 38.2);
	car3.printInfo();
	printIfOldtimer(car3);

	return 0;
}
