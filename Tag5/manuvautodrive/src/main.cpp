/*
 * main.cpp
 *
 *  Created on: Apr 6, 2022
 *      Author: pi
 */

#include "PosEstimation.h"
#include "Maneuver.h"
#include <fstream>
#include <iostream>
#include <string>
#include "RobotControl.h"
using namespace std;

int main()
{
	// Debug PosEstimation ######################################################################
//	PosEstimation testPosEsti = PosEstimation();
//
//	double dVr, dVl, dTstep;
//	string txtline;
//	fstream ifile;
//	int i = 1;
//	ifile.open("PosEstimationInput.txt");
//	if(ifile.is_open())
//	{
//		for(i = 1; i <= 10; i++)
//		{
//			ifile >> dVr >> dVl >> dTstep;
//			testPosEsti.PredictPosition(dVr, dVl, dTstep);
//			double* x = testPosEsti.getPosition();
//			cout << i << ")\tSpeedR = " << dVr << ",\tSpeedL = " << dVl << ",\tTimestep = " << dTstep;
//			cout << "\tPosEstimation = " << x[0] << "\t" << x[1] << "\t" << x[2] << endl;
//		}
//	}

	//Debug LogList #############################################################################
//	Maneuver manCircle;
//	manCircle.CalcCircle(2, 0.3, 0.04);
//	manCircle.LogList("debugLogFileCircle.txt");
//
//	Maneuver manEight;
//	manEight.CalcEight(5, 1, 10);
//	manEight.LogList("debugLogFileEight.txt");

	// Debug test robot control #################################################################
	RobotControl robotctrltest1;
	robotctrltest1.Communicate();

	return 0;
}
