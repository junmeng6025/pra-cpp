/*
 * main.cpp
 *
 *  Created on: Apr 2, 2022
 *      Author: jun
 */

#include <iostream>
#include <string>
#include "fibonacci.h"
using namespace std;

int main()
{
	int input;
	cout << "Input a number: " << endl;
	cin >> input;
	cout << "f(" << input << ") = " << fibonacciRec(input) << endl;

	if(input > 2)
	{
		cout << "(which equals to f(" << input-1 << ") + f(" << input-2;
		cout << ") = " << fibonacciRec(input - 1) << " + " << fibonacciRec(input - 2) << ")" << endl;
	}
}
