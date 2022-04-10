/*
 * main.cpp
 *
 *  Created on: Mar 31, 2022
 *      Author: jun
 */

#include "Flasche.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Flasche f1, f2;
	f1.setVolumen(500);
	f1.setMaterial("plastic");
	cout << "The origin properties of Flasche1 are:" << endl;
	f1.printFlasche();

	f2.setVolumen(350);
	f2.setMaterial("metal");
	cout << "The origin properties of Flasche2 are:" << endl;
	f2.printFlasche();

	f1.adoptFlasche(f2);
	cout << "The adopted properties of Flasche1 are:" << endl;
	f1.printFlasche();

	return 0;
}
