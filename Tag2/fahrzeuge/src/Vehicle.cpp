/*
 * Vehicle.cpp
 *
 *  Created on: Mar 31, 2022
 *      Author: jun
 */

#include "Vehicle.h"
#include <iostream>
#include <string>
using namespace std;

int Vehicle::siCountID = 0;

Vehicle::Vehicle(int buildyear, double price)
{
	siCountID++;
	m_ID = siCountID;
	m_buildyear = buildyear;
	m_price = price;
	m_color = color(rand()%5);
}

Vehicle::~Vehicle(){}

int Vehicle::getBuildyear()
{return m_buildyear;}

double Vehicle::getPrice()
{return m_price;}

int Vehicle::getID()
{return m_ID;}

string Vehicle::getColor()
{
	switch (m_color)
	{
		case(blue):
			return "blue";
			break;
		case(red):
			return "red";
			break;
		case(green):
			return "green";
			break;
		case(white):
			return "white";
			break;
		case(black):
			return "black";
			break;
		default:
			return "ERROR";
	}
}

bool Vehicle::isOldtimer(Vehicle car)
{
	// need an exact object
	if(car.m_buildyear < 1980)
	{return true;}
	else
	{return false;}
}

void Vehicle::printInfo()
{
	cout << endl;
	cout << "Car ID: " << getID() << endl;
	cout << "Build-Year: " << getBuildyear() << endl;
	cout << "Color:      " << getColor() << endl;
	cout << "Price:      " << getPrice() << " thd. EURO" << endl;
}
// TODO: How could I also print the result of isOldtimer via printInfo() ?
