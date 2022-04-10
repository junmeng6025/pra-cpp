/*
 * RobotControl.h
 *
 *  Created on: Apr 7, 2022
 *      Author: pi
 */

#ifndef ROBOTCONTROL_H_
#define ROBOTCONTROL_H_
#include "InterfaceSIM.h"
#include "Maneuver.h"
#include "PosEstimation.h"
#include "PIDCtrl.h"

class RobotControl
{
private:
	InterfaceSIM interface;
	Maneuver maneuver;
	PosEstimation posEstimation;
	PIDCtrl motorR = PIDCtrl(0, 0, 0, 0);
	PIDCtrl motorL = PIDCtrl(0, 0, 0, 0);
	bool bIsActive; // indicate wait for user input
	double m_timestep;

public:
	static RobotControl* transferPointer;
	RobotControl();
	static void transferFunction();
	bool isActive();
	void Step();
	void Communicate();

};

#endif /* ROBOTCONTROL_H_ */
