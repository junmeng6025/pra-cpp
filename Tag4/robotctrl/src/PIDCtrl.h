/*
 * PIDCtrl.h
 *
 *  Created on: Apr 5, 2022
 *      Author: pi
 */

#ifndef PIDCTRL_H_
#define PIDCTRL_H_

class PIDCtrl
{
private:
	double dKp, dKi, dKd, dTa;
	double dEsum, deold, dU;
public:
	PIDCtrl(double Kp, double Ki, double Kd, double Ta);
	~PIDCtrl();

	double getU();
	void calcU(double dW, double dY);
};

#endif /* PIDCTRL_H_ */
