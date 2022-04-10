/*
 * PosEstimation.h
 *
 *  Created on: Apr 6, 2022
 *      Author: pi
 */

#ifndef POSESTIMATION_H_
#define POSESTIMATION_H_

class PosEstimation
{
private:
	double x[3];
	double dVelAverage;
public:
	PosEstimation();
	~PosEstimation();
	void Reset();
	void PredictPosition(double dSpeedR, double dSpeedL, double dTimestep);
	double* getPosition();
};

#endif /* POSESTIMATION_H_ */
