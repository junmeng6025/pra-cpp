/*
 * mayazahlen.cpp
 *
 *  Created on: Mar 28, 2022
 *      Author: jun
 */
# include <iostream>
using namespace std;

int main()
{
	int decnum, mayaquo, mayares;

	cout << "Input a decimal number: " << endl;
	cin >> decnum;
	while(cin.fail())
	{
		cout << "ERROR: Wrong data type. Input a integer." << endl;
		cin.clear();
		cin.ignore(1, '\n');
		cin >> decnum;
	}

	do
	{
		mayares = decnum % 20;
		mayaquo = decnum / 20;
		decnum = mayaquo;
		cout << mayares << endl;
	}
	while(mayaquo != 0);

	return 0;

}
