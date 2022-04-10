/*
 * heron.cpp
 *
 *  Created on: Mar 29, 2022
 *      Author: jun
 */

# include <iostream>
using namespace std;

double heorn_ite(double a, double x0)
{
	// Definition of Heorn-ite function
	for(int i = 0; i < 10; i++)
	{
		x0 = (x0 + a/x0) / 2;
	}
	return x0;
}

int main()
{
	double a, x;
	cout << "Input a non-negative number to do the square root calculation: " << endl;
	cin >> a;
	// Check the number:
	bool flga = false;
	do
	{
		if (cin.fail() or a < 0)
		{
			cout << "ERROR: Wrong input! Please input a non-negative number!" << endl;
			cin.clear();
			cin.ignore(1, '\n');
			cin >> a;
		}
		else
		{
			flga = true;
		}
	}
	while (flga == false);

	cout << "Input a non-zero initial divider x0: " << endl;
	cin >> x;
	// Check the divider x:
	bool flgx = false;
	do
	{
		if (cin.fail() or x == 0)
		{
			cout << "ERROR: Wrong input! Please input a non-zero number!" << endl;
			cin.clear();
			cin.ignore(1, '\n');
			cin >> x;
		}
		else
		{
			flgx = true;
		}
	}
	while (flgx == false);

	// Call the defined function heron_ite(a, x0):
	double sqrt = heorn_ite(a, x);
	cout << "ANS: sqrt(" << a <<")= " << sqrt << endl;
}
