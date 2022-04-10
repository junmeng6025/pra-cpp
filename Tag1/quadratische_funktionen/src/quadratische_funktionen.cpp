/*
 * quadratische_funktionen.cpp
 *
 *  Created on: Mar 29, 2022
 *      Author: jun
 */

#include <iostream>
#include <cmath>
using namespace std;

// TODO: pointer of x1 and x2 as arguments NOT handled yet.
bool checksol(double a, double b, double c)
{
	double delta = pow(b, 2) - 4*a*c;
	if (delta < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	double a, b, c, x1, x2;
	cout << "Input the parameters a, b, and c of the function following the normal form 'a*x^2 + b*x + c = 0': " << endl;
	cin >> a;
	cin >> b;
	cin >> c;

	if (checksol(a, b, c) == false)
	{
		cout << "No real number solutions." << endl;
	}
	else
	{
		x1 = (-b + sqrt(pow(b, 2) - 4*a*c))/(2*a);
		x2 = (-b - sqrt(pow(b, 2) - 4*a*c))/(2*a);
		cout << "The solutions are: x1 = " << x1 << ", x2 = " << x2 << "." << endl;
	}
	return 0;
}

