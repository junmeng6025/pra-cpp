/*
 * main.cpp
 *
 *  Created on: Apr 2, 2022
 *      Author: jun
 */

#include <iostream>
#include <string>
#include "factorialIter.h"
#include "factorialRec.h"
using namespace std;

int main()
{
	int input;
	cout << "Input a non-negative number: " << endl;
	cin >> input;
	// use iterative function:
	cout << "Using Iteration >> The factorial of " << input << " is " << factorialIter(input) << endl;

	// use recursive function:
	cout << "Using Recursion >> The factorial of " << input << " is " << factorialRec(input) << endl;

	return 0;
}

