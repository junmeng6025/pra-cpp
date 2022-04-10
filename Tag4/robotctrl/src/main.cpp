/*
 * main.cpp
 *
 *  Created on: Apr 4, 2022
 *      Author: jun
 */

#include "ncurses.h"
#include "KeyboardCtrl.h"
#include "InterfaceSIM.h"
#include "PIDCtrl.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Debug KeyboardCtrl #########################################################################
	KeyboardCtrl testcommand1;
//	testcommand1.Step();
	testcommand1.Communicate();

	// Debug PIDCtrl ##############################################################################
//	PIDCtrl testpid = PIDCtrl(1000, 10, 0.1, 0.5);
//
//	double dWtxt, dYtxt;
//	string txtline;
//	fstream ifile;
//	int i = 1;
//	ifile.open("PIDControllerInput.txt");
//	if(ifile.is_open())
//	{
//		while(getline(ifile, txtline))
//		{
//			ifile >> dWtxt >> dYtxt;
//			testpid.calcU(dWtxt, dYtxt);
//			cout << i << ")\tSetV = " << dWtxt << ",\tActV = " << dYtxt << ",\tCalcU = " << testpid.getU() << endl;
//			i++;
//		}
//	}

	//


	return 0;
}
