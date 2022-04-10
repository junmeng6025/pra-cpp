/*
 * main.cpp
 *
 *  Created on: Apr 3, 2022
 *      Author: jun
 */

#include <iostream>
#include <fstream>
#include <string>
#include "readFile.h"
#include "NoFileException.h"
using namespace std;

int main()
{
	string filename;
	cout << "Input filename: " << endl;
	cin >> filename;

	try
	{
		read_file(filename);
	}
	catch(NoFileException& err)
	{
		cout << err.what() << endl;
	}

	return 0;
}
