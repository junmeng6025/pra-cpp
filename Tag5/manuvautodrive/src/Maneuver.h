/*
 * Maneuver.h
 *
 *  Created on: Apr 6, 2022
 *      Author: pi
 */

#ifndef MANEUVER_H_
#define MANEUVER_H_

#include <list>
#include <string>
#include "Coord.h"

class Maneuver
{
private:
	std::list<Coord> CoordList; //[0][1][2] = {x, y, v}
	std::list<Coord>::iterator iter;
	bool bIsRunning;
	double adWishSpeed[2];
	double dMaxSpeed;
	double dPosDifference;
	double dPosDiffThreshold;
public:
	Maneuver();

	void CalcCircle(double dRadius, double dSpeed, double dTimestep);
	void CalcEight(double dRadius, double dSpeed, double dTimestep);
	void LogList(std::string sDatei);
	bool isRunning();
	void Start();
	void Stop();
	void Proceed();
	void CalcManeuverSpeed(double dX, double dY, double dW);
	double* getManeuverSpeed();

	~Maneuver();
};

#endif /* MANEUVER_H_ */
