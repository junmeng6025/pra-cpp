/*
 * Maneuver.cpp
 *
 *  Created on: Apr 6, 2022
 *      Author: pi
 */

#include "Maneuver.h"
#include <cmath>
#include <fstream>

Maneuver::Maneuver()
{
	bIsRunning = false;
	adWishSpeed[0] = 0;
	adWishSpeed[1] = 0;
	dMaxSpeed = 0.5;
	dPosDifference = 0;
	dPosDiffThreshold = 0.05;
}

Maneuver::~Maneuver(){}

void Maneuver::CalcCircle(double dRadius, double dSpeed, double dTimestep)
{
	for(int i = 0; i < (int)((2*M_PI) / ((dSpeed/dRadius) * dTimestep)); i++)
	{
//		iter = CoordList.begin() + i;
//		iter->m_dX = dRadius * sin(i * (dSpeed/dRadius) * dTimestep);
//		iter->m_dY = dRadius * (1 - cos(i * (dSpeed/dRadius) * dTimestep));
//		iter->m_dV = dSpeed;

		double x = dRadius * sin(i * (dSpeed/dRadius) * dTimestep);
		double y = dRadius * (1 - cos(i * (dSpeed/dRadius) * dTimestep));
		Coord cooCircle(x, y, dSpeed);
		CoordList.push_back(cooCircle);
	}
}

void Maneuver::CalcEight(double dRadius, double dSpeed, double dTimestep)
{
	int iterTotalCircl = (int)((2*M_PI) / ((dSpeed/dRadius) * dTimestep));

	// The first circle of '8'
	for(int i = 0; i < iterTotalCircl; i++)
	{
//		iter = CoordList.begin() + i;
//		iter->m_dX = dRadius * sin(i * (dSpeed/dRadius) * dTimestep);
//		iter->m_dY = dRadius * (1 - cos(i * (dSpeed/dRadius) * dTimestep));
//		iter->m_dV = dSpeed;

		double x = dRadius * sin(i * (dSpeed/dRadius) * dTimestep);
		double y = dRadius * (1 - cos(i * (dSpeed/dRadius) * dTimestep));
		Coord cooCircle(x, y, dSpeed);
		CoordList.push_back(cooCircle);
	}
	// The second circle of '8'
	for(int i = 0; i < iterTotalCircl; i++)
	{
//		iter = CoordList.begin() + i;
//		iter->m_dX = dRadius * sin(i * (dSpeed/dRadius) * dTimestep);
//		iter->m_dY = (-dRadius) * (1 - cos(i * (dSpeed/dRadius) * dTimestep));
//		iter->m_dV = dSpeed;

		double x = dRadius * sin(i * (dSpeed/dRadius) * dTimestep);
		double y = (-dRadius) * (1 - cos(i * (dSpeed/dRadius) * dTimestep));
		Coord cooCircle(x, y, dSpeed);
		CoordList.push_back(cooCircle);
	}

}

void Maneuver::LogList(std::string sDatei)
{
	// Log Position information (x, y) in file
	std::ofstream ofile;
	// Input sDatei is the filename
	ofile.open(sDatei, std::ios::out | std::ios::app);
	if(ofile.is_open())
	{
		for(iter = CoordList.begin(); iter != CoordList.end(); iter++)
		{ofile << iter->m_dX << "      \t" << iter->m_dY <<std::endl;}
	}
	ofile.close();
}

bool Maneuver::isRunning()
{
	return bIsRunning;
}

void Maneuver::Start()
{
	iter = CoordList.begin();
	bIsRunning = true;
}

void Maneuver::Stop()
{
	bIsRunning = false;
}

void Maneuver::Proceed()
{
	bIsRunning = true;
}

void Maneuver::CalcManeuverSpeed(double dX, double dY, double dW)
{
	// Reference-coordinate X, Y read from CoordList
	// Actual-coordinate x, y is input
	double dXref = iter->m_dX;
	double dYref = iter->m_dY;
	dPosDifference = sqrt(pow((dXref-dX), 2) + pow((dYref-dY), 2));

	if(dPosDifference < dPosDiffThreshold)
	{iter++;}

	if(iter != CoordList.end())
	{
		// calc pos-angle to the ref-Coord
		double dPhi = atan2((dYref-dY), (dXref-dX));
		// calc diff-angle between current head-angle and target pos-angle
		double dWdiff = dPhi - dW;
		// ensure diff-angle in interval ]-pi, pi]
		dWdiff = fmod(dWdiff, 2*M_PI);
		if(dWdiff > M_PI)
		{dWdiff = dWdiff - 2*M_PI;}
		else if(dWdiff <= -M_PI)
		{dWdiff = dWdiff + 2*M_PI;}
		// calc rotation speed, limit in interval [-0.5, 0.5]
		double dVrotat = 2*dWdiff;
		if(fabs(dVrotat) > 0.5)
		{
			if(dVrotat > 0)
			{dVrotat = 0.5;}
			else
			{dVrotat = -0.5;}
		}
		// get translation speed
		double dVtrans = iter->m_dV;
		// check MaxSpeed limit
		if(dVtrans * dVrotat > 0)
		{
			if(dVtrans + dVrotat > dMaxSpeed)
			{dVtrans = dMaxSpeed - dVrotat;}
			else if(dVtrans + dVrotat < -dMaxSpeed)
			{dVtrans = -dMaxSpeed - dVrotat;}
		}
		else
		{
			if(dVtrans - dVrotat > dMaxSpeed)
			{dVtrans = dMaxSpeed + dVrotat;}
			else if(dVtrans - dVrotat < -dMaxSpeed)
			{dVtrans = -dMaxSpeed + dVrotat;}
		}
		// sum Speed
		adWishSpeed[0] = dVtrans + dVrotat;
		adWishSpeed[1] = dVtrans - dVrotat;
	}
	else
	{
		adWishSpeed[0] = 0;
		adWishSpeed[1] = 0;
		Stop();
	}
}

double* Maneuver::getManeuverSpeed()
{
	return adWishSpeed;
}
