/*
 * main.cpp
 *
 *  Created on: Apr 2, 2022
 *      Author: jun
 */

#include <iostream>
#include <fstream>
#include <string>
#include "readFile.h"
#include "writeFile.h"
using namespace std;

int main()
{
	string filename;
	cout << "Input the file name:" << endl;
	cin >> filename;

	bool isRead = read_file(filename);
	if(isRead)
	{
		write_file(filename);
		cout << "\nThe modified text:" << endl;
		read_file(filename);
	}
	else
	{
		cout << "File does not exist!" << endl;
	}

	return 0;
}
