/*
 * KeyboardCtrl.h
 *
 *  Created on: Apr 4, 2022
 *      Author: jun
 */

#ifndef KEYBOARDCTRL_H_
#define KEYBOARDCTRL_H_

#include "ncurses.h"
#include "InterfaceSIM.h"
#include <cmath>
#include <string>
#include <iostream>
#include "PIDCtrl.h"

class KeyboardCtrl
{
private:
	double m_rdaSetV[2]; // [0] right side; [1] left side;
	double m_dtimestep;

public:
	double m_rdaActV[2]; // [0] right side; [1] left side;

	KeyboardCtrl();
	~KeyboardCtrl();

	double* getSetV();
	void setActV(double dActVr, double dActVl);
	void Communicate(); // Input command 'wasdbq'via ncurses, manipulate darrSetV[2]
	void Step(); // Input darrSetV[2], darrActV[2], manipulate SignalLen

	InterfaceSIM interface = InterfaceSIM();
	static KeyboardCtrl* transferPointer;
	static void transferFunction();

	int m_iaSignalLen[2];

	PIDCtrl controllerR = PIDCtrl(0, 0, 0, 0);
	PIDCtrl controllerL = PIDCtrl(0, 0, 0, 0);
};

#endif /* KEYBOARDCTRL_H_ */
