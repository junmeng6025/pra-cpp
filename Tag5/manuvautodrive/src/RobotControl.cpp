/*
 * RobotControl.cpp
 *
 *  Created on: Apr 7, 2022
 *      Author: pi
 */

#include "RobotControl.h"
#include "ncurses.h"
#include <jsoncpp/json/json.h>
#include <iostream>

RobotControl::RobotControl()
{
	bIsActive = false;
	m_timestep = 0.04;
	interface.Initialize(m_timestep, *transferFunction);
	transferPointer = this;
	motorR = PIDCtrl(500, 150, 0, m_timestep);
	motorL = PIDCtrl(500, 150, 0, m_timestep);
}

RobotControl* RobotControl::transferPointer;

void RobotControl::transferFunction()
{
	transferPointer->Step();
}

void RobotControl::Communicate()
{
	char chWantRe;
	std::cout << "Do you want to start a new maneuver? [press 'y' to start; press any other key to continue]" << std::endl;
	std::cin >> chWantRe;

	if(chWantRe != 'y')
	{
		bIsActive = false;
	}
	else
	{
		bIsActive = true;
		// maneuver select
		char chManuvSelect;
		std::cout << "Which maneuver do you want? ['c' for Circle; '8' for Eight-shape.]" << std::endl;
		std::cin >> chManuvSelect;
		// input parameter
		double dInputR, dInputV;
		std::cout << "Input Radius:" << std::endl;
		std::cin >> dInputR;
		std::cout << "Input Velocity:" << std::endl;
		std::cin >> dInputV;
		// generate maneuver
		switch(chManuvSelect)
		{
		case 'c':
			maneuver.CalcCircle(dInputR, dInputV, m_timestep);
			break;
		case '8':
			maneuver.CalcEight(dInputR, dInputV, m_timestep);
			break;
		default:
			break;
		}
		// position estimate reset
		posEstimation.Reset();

		// ncurses. launch
		sigprocmask(SIG_UNBLOCK, &interface.mask, nullptr);
		int iAscii = 0;
		initscr();
		nodelay(stdscr, TRUE);
		noecho();

		//loop: get user input
		while(iAscii != 113) // 'q'
		{
			iAscii = getch();
			if(iAscii != -1)
			{
				clear();
				printw("Which action do you want? [1] Start; [2] Stop; [3] Proceed.");
				printw("\nPress 'q' to quit.");
				switch(iAscii)
				{
					case 49: // ascii for '1'
						maneuver.Start();
						printw("\n Start.");
						break;
					case 50: // ascii for '2'
						maneuver.Stop();
						printw("\n Stop.");
						break;
					case 51: // ascii for '3'
						maneuver.Proceed();
						printw("\n Proceed.");
						break;
					default:
						break;
				}// end of switch
			}// end of if getch() != -1
		}// end of loop getch() != 'q'

		// press 'q', quit input
		printw("\nInput quit.");
		// wait until robot stands still
		double* pdActV = interface.GetInput();
		while(pdActV[0] != 0 or pdActV[1] != 0)
		{
			printw("\nRobot still running!");
		}
		sigprocmask(SIG_BLOCK, &interface.mask, nullptr);
		endwin();
	}
}

void RobotControl::Step()
{
	// create an array to write signal length. [0]right; [1]left
	int piSignalLen[2];
	piSignalLen[0] = 1500;
	piSignalLen[1] = 1500;

	// read current status via interface
	double* pdActV = interface.GetInput();            // get array current velocity from interface. [0]right; [1]left

	if(maneuver.isRunning())
	{
		// calculate the prediction
		posEstimation.PredictPosition(pdActV[0], pdActV[1], m_timestep);
		// calculate command
		double* status = posEstimation.getPosition();
		maneuver.CalcManeuverSpeed(status[0], status[1], status[2]);
		double* pdSetV = maneuver.getManeuverSpeed(); // get array adWishSpeed from obj. maneuver

		// translate command to signal length to motor
		// right side
		motorR.calcU(pdSetV[0], pdActV[0]);
		piSignalLen[0] = motorR.getU() + 1500;
		// left side
		motorL.calcU(pdSetV[1], pdActV[1]);
		piSignalLen[1] = motorL.getU() + 1500;

		// ensure signal length limit in interval [1000, 2000]
		if(piSignalLen[0] < 1000 or piSignalLen[0] > 2000 or piSignalLen[1] < 1000 or piSignalLen[1] > 2000)
		{
			if(piSignalLen[0] < 1000)
			{piSignalLen[0] = 1000;}
			else if(piSignalLen[0] > 2000)
			{piSignalLen[0] = 2000;}

			if(piSignalLen[1] < 1000)
			{piSignalLen[1] = 1000;}
			else if(piSignalLen[1] > 2000)
			{piSignalLen[1] = 2000;}
		}

	}// end of if maneuver.isRunning == true
	else
	{
		piSignalLen[0] = 1500;
		piSignalLen[1] = 1500;
	}
	// push signal length as control signal via interface
	interface.SetOutputs(piSignalLen);
}

bool RobotControl::isActive()
{
	return bIsActive;
}
