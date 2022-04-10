/*
 * PosEstimation.cpp
 *
 *  Created on: Apr 6, 2022
 *      Author: pi
 */

#include "PosEstimation.h"
#include <cmath>
#include <math.h>

PosEstimation::PosEstimation()
{
	x[0] = 0; // xk [m]
	x[1] = 0; // yk [m]
	x[2] = 0; // wk [rad]
	dVelAverage = 0; //[m/s]
}

void PosEstimation::PredictPosition(double dSpeedR, double dSpeedL, double dTimestep)
{
	// xk
	x[0] = x[0] + dVelAverage * dTimestep * cos(x[2]);
	// yk
	x[1] = x[1] + dVelAverage * dTimestep * sin(x[2]);
	// wk
	x[2] = x[2] + dTimestep * (dSpeedR - dSpeedL)/0.23;
	x[2] = fmod(x[2], 2*M_PI);
	if(x[2] > M_PI)
	{x[2] = x[2] - 2*M_PI;}
	else if(x[2] <= -M_PI)
	{x[2] = x[2] + 2*M_PI;}
	// aveV
	dVelAverage = (dSpeedR + dSpeedL)/2;
}

double* PosEstimation::getPosition()
{
	return x;
}

void PosEstimation::Reset()
{
	x[0] = 0; // xk
	x[1] = 0; // yk
	x[2] = 0; // wk
	dVelAverage = 0;
}

PosEstimation::~PosEstimation(){}
