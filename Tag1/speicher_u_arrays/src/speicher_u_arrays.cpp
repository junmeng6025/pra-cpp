/*
 * speicher_u_arrays.cpp
 *
 *  Created on: Mar 29, 2022
 *      Author: jun
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(nullptr));

	// Dynamic storage reservation.
	int* iStack = new int[100000];
	int counter = 0;

	// TODO: see what iStack and *iStack stands for
	cout << iStack << endl;
	// iStack is the memory address
	cout << *iStack << endl;
	// *iStack = 0

	for(unsigned i = 0; i < 100000; i++)
	{
		iStack[i] = rand() % 100 + 0;
		if (iStack[i] % 13 == 0)
		{
			counter++;
		}
		else
		{
			continue;
		}
	}
	cout << "There are " << counter << " numbers that are exactly divisible by 13." << endl;

	// Free the storage of a dynamic arranged array.
	delete[] iStack;

	return 0;
}
