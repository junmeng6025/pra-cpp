/*
 * referenzen.cpp
 *
 *  Created on: Mar 29, 2022
 *      Author: jun
 */

#include<iostream>
using namespace std;

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int para1, para2;
	cout << "Input two parameters to exchange: " << endl;
	cout << " Input prar1 = ";
	cin >> para1;
	cout << " Input prar2 = ";
	cin >> para2;

	swap(para1, para2);
	cout << "The exchanged parameters are:\n Swapped para1 = " << para1 << "\n Swapped para2 = " << para2 << endl;
	return 0;
}
