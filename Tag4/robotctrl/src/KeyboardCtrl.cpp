/*
 * KeyboardCtrl.cpp
 *
 *  Created on: Apr 5, 2022
 *      Author: jun
 */

#include "KeyboardCtrl.h"
#include "InterfaceSIM.h"
#include "PIDCtrl.h"
#include <iostream>
#include <string>

KeyboardCtrl::KeyboardCtrl()
{
	m_rdaSetV[0] = 0;
	m_rdaSetV[1] = 0;
	m_rdaActV[0] = 0;
	m_rdaActV[1] = 0;
	m_dtimestep = 0.04;
	interface.Initialize(m_dtimestep, transferFunction);
	transferPointer = this;
	m_iaSignalLen[0] = 1500;
	m_iaSignalLen[1] = 1500;
	controllerR = PIDCtrl(500.0, 1850.0, 0, 0.04);
	controllerL = PIDCtrl(500.0, 1850.0, 0, 0.04);
}

KeyboardCtrl* KeyboardCtrl::transferPointer;

void KeyboardCtrl::transferFunction()
{
	transferPointer->Step();
}

double* KeyboardCtrl::getSetV()
{
	return m_rdaSetV;
}

void KeyboardCtrl::setActV(double dActVr, double dActVl)
{
	m_rdaActV[0] = dActVr;
	m_rdaActV[1] = dActVl;
}

void KeyboardCtrl::Communicate() // Input command 'wasdbq', Output darrSetV[2]
{
	// loop 01:
	// active communication between program and user
	// 'w' 'a' 's' 'd' >> directions
	// 119 'w' 115 's': SetV +- 0.01
	// 97  'a': SetV.r +0.005 && SetV.l -0.005
	// 100 'd': SetV.l +0.005 && SetV.r -0.005
	// r: [0]; l: [1]
	// 98  'b' >> break: pause
	// 113 'q' >> quit: quit the loop, end the keyboard input
	// LIMIT of ActV: interval [-0.5, +0.5]

	// loop 02:
	// ensure Safe-Quitting, check ActV == 0 then quit ncurses

	sigprocmask(SIG_UNBLOCK, &interface.mask, nullptr);

	int iAscii = 0;

	initscr();
	nodelay(stdscr, TRUE);
	noecho();

//	printw("Input the control command: w/a/s/d; b for pause; q for quit");
//	printw("\nThe initial velocity set value: r: %f, l: %f", m_rdaSetV[0], m_rdaSetV[1]);

	// loop 01: command processing

	while(iAscii != 113) // 'q' >> quit input
	{
		iAscii = getch();
		if(iAscii != -1)
		{
			switch(iAscii)
			{
				case 119: // 'w' >> forward
	//					m_rdaSetV[0] += 0.1;
	//					m_rdaSetV[1] += 0.01;

					m_rdaSetV[0] += 0.01;
					if(fabs(m_rdaSetV[0]) >= 0.5)
					{m_rdaSetV[0] = 0.5;}

					m_rdaSetV[1] += 0.01;
					if(fabs(m_rdaSetV[1]) >= 0.5)
					{m_rdaSetV[1] = 0.5;}

	//				printw("\nInput: %c, command forward.    ", iAscii);
	//				printw("The current velocity set value: r: %f, l: %f", m_rdaSetV[0], m_rdaSetV[1]);
					break;

				case 97:  // 'a' >> turn left; r: [0]; l: [1]
	//					m_rdaSetV[0] += 0.005;
	//					m_rdaSetV[1] -= 0.005;

					m_rdaSetV[0] += 0.005;;
					if(fabs(m_rdaSetV[0]) >= 0.5)
					{m_rdaSetV[0] = 0.5;}

					m_rdaSetV[1] -= 0.005;
					if(fabs(m_rdaSetV[1]) >= 0.5)
					{m_rdaSetV[1] = -0.5;}

	//				printw("\nInput: %c, command turn left.  ", iAscii);
	//				printw("The current velocity set value: r: %f, l: %f", m_rdaSetV[0], m_rdaSetV[1]);
					break;

				case 115: // 's' >> backward
	//					m_rdaSetV[0] -= 0.01;
	//					m_rdaSetV[1] -= 0.01;

					m_rdaSetV[0] -= 0.01;
					if(fabs(m_rdaSetV[0]) >= 0.5)
					{m_rdaSetV[0] = -0.5;}

					m_rdaSetV[1] -= 0.01;
					if(fabs(m_rdaSetV[1]) >= 0.5)
					{m_rdaSetV[1] = -0.5;}

	//				printw("\nInput: %c, command backward.   ", iAscii);
	//				printw("The current velocity set value: r: %f, l: %f", m_rdaSetV[0], m_rdaSetV[1]);
					break;

				case 100: // 'd' >> turn right; r: [0]; l: [1]
	//					m_rdaSetV[0] -= 0.005;
	//					m_rdaSetV[1] += 0.005;

					m_rdaSetV[0] -= 0.005;
					if(fabs(m_rdaSetV[0]) >= 0.5)
					{m_rdaSetV[0] = -0.5;}

					m_rdaSetV[1] += 0.005;
					if(fabs(m_rdaSetV[1]) >= 0.5)
					{m_rdaSetV[1] = 0.5;}

	//				printw("\nInput: %c, command turn right. ", iAscii);
	//				printw("The current velocity set value: r: %f, l: %f", m_rdaSetV[0], m_rdaSetV[1]);
					break;

				case 98:  // 'b' >> brake

					m_rdaSetV[0] = 0;
					m_rdaSetV[1] = 0;

	//				printw("\nInput: %c, command pause.      ", iAscii);
	//				printw("The current velocity set value: r: %f, l: %f", m_rdaSetV[0], m_rdaSetV[1]);
					break;

				default:
					break;
			}// end of switch(iAscii)
			clear();
			printw("Input command: %c\n", iAscii);
			printw("The current SetV: l = %f, r = %f.\n", m_rdaSetV[1], m_rdaSetV[0]);
			printw("The current ActV: l = %f, r = %f.", m_rdaActV[1], m_rdaActV[0]);
		} // end of if(iAscii != -1)

	}// end of while-loop 1

	// loop 02: ensure Safe-Quitting
	while(m_rdaActV[0] != 0 or m_rdaActV[1] != 0)
	{
		m_rdaSetV[0] = 0;
		m_rdaSetV[1] = 0;
//		double* daActV = interface.GetInput();
//		setActV(daActV[0], daActV[1]);

		if(m_rdaActV[0] == 0 and m_rdaActV[1] == 0)
		{
			break;
		}
	}

	endwin();
	sigprocmask(SIG_BLOCK, &interface.mask, nullptr);
}

void KeyboardCtrl::Step() // Input darrSetV[2], darrActV[2], Output signal length
{
	// catch ActV, save into attribute m_rdaSetV
	double* pdaActV = interface.GetInput();
//	setActV(pdaActV[0], pdaActV[1]);
	m_rdaActV[0] = pdaActV[0];
    m_rdaActV[1] = pdaActV[1];

    // SetV in SignalLen translate
//	int iaSignalLen[2] = {1500, 1500};
//	iaSignalLen[0] = (int) 1500 + 1000 * (m_rdaSetV[0]);
//	iaSignalLen[1] = (int) 1500 + 1000 * (m_rdaSetV[1]);

	// call PIDCtrl, calculate U and translate to control SignalLen.
	controllerR.calcU(m_rdaSetV[0], m_rdaActV[0]);
	m_iaSignalLen[0] = (int) 1500 + controllerR.getU();
	controllerL.calcU(m_rdaSetV[1], m_rdaActV[1]);
	m_iaSignalLen[1] = (int) 1500 + controllerL.getU();

	// ensure SiginalLen in [1000, 2000]
	if(m_iaSignalLen[0] < 1000 or m_iaSignalLen[0] > 2000 or m_iaSignalLen[1] < 1000 or m_iaSignalLen[1] > 2000)
	{
		if(m_iaSignalLen[0] < 1000)
		{m_iaSignalLen[0] = 1000;}
		else if(m_iaSignalLen[0] > 2000)
		{m_iaSignalLen[0] = 2000;}

		if(m_iaSignalLen[1] < 1000)
		{m_iaSignalLen[1] = 1000;}
		else if(m_iaSignalLen[1] > 2000)
		{m_iaSignalLen[1] = 2000;}
	}
	// send SignalLen to robot
	interface.SetOutputs(m_iaSignalLen);
}

KeyboardCtrl::~KeyboardCtrl(){}
