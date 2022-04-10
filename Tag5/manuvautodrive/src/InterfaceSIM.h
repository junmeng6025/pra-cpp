/*
 * InterfaceSIM.h
 *
 *  Created on: Apr 5, 2022
 *      Author: jun
 */

#ifndef INTERFACESIM_H_
#define INTERFACESIM_H_

#include <ctime>
#include <csignal>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <csignal>
#include <time.h>
#include <ncurses.h>
#include <jsoncpp/json/json.h>
#include <typeinfo>

#define SIGSTEP SIGRTMIN

class InterfaceSIM {

public:
	//Constructor
	InterfaceSIM();

	//Destructor
	virtual ~InterfaceSIM();

	void Initialize (double, void (*pFunction)(void));

	//Read current velocity
	double* GetInput();

	//Set desired velocity in servo signal values
	void SetOutputs(int *iMicros);

	//Variable to manipulate signals
	sigset_t mask;

	//Pointer to desired funktion for looped execution
	static void (*p_LoopFunction)(void);

private:
	//variables for real-time timer
	struct sigaction _sigaSA;
	struct sigevent _sigevSE;
	struct itimerspec _itVAL;
	static timer_t _tTimerID;

	//Array for holding old values
	double _daInput_old[2];

	//Array for input data
	double _daInput_data[2];

	//Interval Handler
	static void HandleSignal (int sig, siginfo_t* info, void *uc);

	// Version: 14.02.2019
	// variables for read and write the Json files
	Json::Reader _reader;
	Json::StyledWriter _writer;
	Json::Value _jV_output_data;
	Json::Value _jV_input_data;
	std::string _sjValue;
};



#endif /* INTERFACESIM_H_ */
