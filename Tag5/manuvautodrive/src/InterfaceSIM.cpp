/*
 * InterfaceSIM.cpp
 *
 *  Created on: 27.01.2014
 *  Updated on: 26.01.2015
 *      Author: Shiyue Liu
 * 	Updated on: 14.02.2019
 * 		Report: Changing the data outputs and inputs to JSON format to Work with the Version ** of the Rover
 * 		Author: Jan Niklas Rodewald on behalf of Simon Ziegltrum
 */

#include "InterfaceSIM.h"
using namespace std;

//Pfade zu Ausgabedateien festlegen
// Update: 14.02.2019:
//#define OUTPUT_FILE "/home/pi/Rover Linux 32bit/data_output.txt"
//#define INPUT_FILE	 "/home/pi/Rover Linux 32bit/data_input.txt"
// Update: 14.02.2019:
//#define OUTPUT_FILE "/home/pi/Rover Linux 32bit/target_value.json" 			// Änderung 14.02.2019
//#define INPUT_FILE	 "/home/pi/Rover Linux 32bit/actual_value.json"			// Änderung 14.02.2019
// Fuer Ubuntu:
#define OUTPUT_FILE "/home/pi/Schreibtisch/target_value.json" 			// Änderung 14.02.2019
#define INPUT_FILE	 "/home/pi/Schreibtisch/actual_value.json"			// Änderung 14.02.2019

using namespace std;

timer_t InterfaceSIM::_tTimerID;
void (*InterfaceSIM::p_LoopFunction)(void) = NULL;

//Constructor, Initialisiert Linux Timer und System Interrupt Routine
InterfaceSIM::InterfaceSIM() {

	//Reset output values
	fstream f0(OUTPUT_FILE, ios::out);

	// Version: 26.01.2015
//	f0 << 0 << endl;
//	f0 << 0 << endl;

// Version: 14.02.2019
	_jV_output_data["speed"]["right"] = 0;
	_jV_output_data["speed"]["left"] = 0;
	f0 << _writer.write(_jV_output_data);
	//
	f0.close();

	//Initializing"\n"
	_daInput_old[0] = 0;
	_daInput_old[1] = 0;
	_daInput_data[0] = 0;
	_daInput_data[1] = 0;
}

void InterfaceSIM::Initialize(double Zeitbasis, void (*pFunction)(void)) {
	p_LoopFunction = pFunction;
	Zeitbasis = Zeitbasis * 1000000;

	//Set up System Interrupt Routine
	sigemptyset(&_sigaSA.sa_mask);
	_sigaSA.sa_flags = SA_SIGINFO;
	_sigaSA.sa_sigaction = HandleSignal;
	if (sigaction(SIGSTEP, &_sigaSA, NULL) == -1) {
		cout << "sigaction failed" << endl;
		exit(EXIT_FAILURE);
	}
	sigaction(SIGINT, &_sigaSA, NULL);
	_sigevSE.sigev_notify = SIGEV_SIGNAL;
	_sigevSE.sigev_signo = SIGSTEP;
	_sigevSE.sigev_value.sival_ptr = &_tTimerID;

	sigemptyset(&mask);
	sigaddset(&mask, SIGSTEP);
	if (sigprocmask(SIG_SETMASK, &mask, NULL) == -1)
		exit(EXIT_FAILURE);

	cout << "System Interrupt Routine ready" << endl;

	if (timer_create(CLOCK_REALTIME, &_sigevSE, &_tTimerID) == 0) {
		_itVAL.it_value.tv_sec = Zeitbasis / 1000000;
		_itVAL.it_value.tv_nsec = ((int) Zeitbasis % 1000000) * 1000;
		_itVAL.it_interval.tv_sec = _itVAL.it_value.tv_sec;
		_itVAL.it_interval.tv_nsec = _itVAL.it_value.tv_nsec;

		if (timer_settime(_tTimerID, 0, &_itVAL, NULL) != 0) {
			cout << "settime_error!" << endl;
		}
	} else {
		cout << "timer_create error!" << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Timer ready" << endl;
}

//Einlesen der aktuellen Geschwindigkeit
/*ACHTUNG: Reihenfolge im Array genau andersrum wie SetOutputs!
 *LINKS:  _daInput_data[1]
 *RECHTS: _daInput_data[0]
 */

double* InterfaceSIM::GetInput(void) {
	// Version: 26.01.2015
	/*
	 fstream in(INPUT_FILE, ios::in);

	 for (int i = 0; i<32; i++)
	 {
	 char ctemp[15];
	 in >> ctemp;
	 }

	 for(int i = 0; i<2; i++)
	 in >> _daInput_data[i];

	 in.close();

	 double temp = _daInput_data[0];
	 _daInput_data[0] = _daInput_data[1]/(0.3891*10);
	 _daInput_data[1] = temp/(0.389+1*10);
	 */

	// Version: 14.02.2019
	// open the json file
	std::ifstream input_file(INPUT_FILE, std::ifstream::binary);

	if (!(input_file.peek() == std::ifstream::traits_type::eof())) {
		// write the input of the json file in a string
		input_file >> _jV_input_data;
		// read the speed input for the right speed and convert it to a double
		_daInput_data[0] = _jV_input_data["speed"]["right"].asDouble();
		// read the speed input for the left speed and convert it to a double
		_daInput_data[1] = _jV_input_data["speed"]["left"].asDouble();
	}

	input_file.close();
	return _daInput_data;
}

//Setzen der Geschwindigkeitswerte
void InterfaceSIM::SetOutputs(int *iMicros) {
	// Version: 26.01.2015
	/*
	 double _daOutput[2];
	 _daOutput[0] = 0;
	 _daOutput[1] = 0;

	 //left
	 _daOutput[0] = ((double)*(iMicros+1)-1500)/1000;
	 //right
	 _daOutput[1] = ((double)*(iMicros)-1500)/1000;

	 f2 << _daOutput[0]*10 << endl;
	 f2 << _daOutput[1]*10 << endl;

	 */

	// Version: 14.02.2019
	fstream f2(OUTPUT_FILE, ios::out);
	_jV_output_data["speed"]["right"] = ((double) *(iMicros) - 1500) / 1000;
	_jV_output_data["speed"]["left"] = ((double) *(iMicros + 1) - 1500) / 1000;
	f2 << _writer.write(_jV_output_data);
	//

	f2.close();
}

InterfaceSIM::~InterfaceSIM() {

}

//System Interrupt Handler
void InterfaceSIM::HandleSignal(int sig, siginfo_t *info, void *uc) {
	//If timer signal caught
	if (sig == SIGSTEP) {
		p_LoopFunction();
	}

	//If ctrl+c
	else if (sig == SIGINT) {
		timer_delete(_tTimerID);
		endwin();
		cout << "Emergency exit" << endl;
		exit(EXIT_SUCCESS);
	}
}
