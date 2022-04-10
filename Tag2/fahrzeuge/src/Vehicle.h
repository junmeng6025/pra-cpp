/*
 * Vehicle.h
 *
 *  Created on: Mar 31, 2022
 *      Author: jun
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>
using namespace std;

class Vehicle
{
public:
	enum color{blue, red, green, white, black};

private:
	int m_ID;
	int m_buildyear;
	double m_price;
	static int siCountID;
	color m_color;

public:
	Vehicle(int by, double p);
	~Vehicle();
	int getBuildyear();
	double getPrice();
	string getColor();
	int getID();
	static bool isOldtimer(Vehicle car);
	void printInfo();
};

#endif /* VEHICLE_H_ */
