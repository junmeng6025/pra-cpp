/*
 * PIDCtrl.cpp
 *
 *  Created on: Apr 5, 2022
 *      Author: jun
 */

#include "PIDCtrl.h"

PIDCtrl::PIDCtrl(double Kp, double Ki, double Kd, double Ta)
{
	dKp = Kp;
	dKi = Ki;
	dKd = Kd;
	dTa = Ta;
	dEsum = 0;
	deold = 0;
	dU = 0;
}

PIDCtrl::~PIDCtrl(){}

double PIDCtrl::getU()
{
	return dU;
}

void PIDCtrl::calcU(double dW, double dY)
{
	double dek = dW - dY;
	dEsum += dek;
	dU = dKp*dek + dKi*dTa*dEsum + dKd*(dek - deold)/dTa;
}
