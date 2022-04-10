/*
 * flaschen.cpp
 *
 *  Created on: Mar 30, 2022
 *      Author: jun
 */

#include "Flasche.h"
#include <string>
#include <iostream>
using namespace std;

// Constructor
Flasche::Flasche()
{
	// Definition of attributes
	dVolumen = 0;
	sMaterial = "material";
}

Flasche::~Flasche()
{}

void Flasche::setVolumen(double volume)
{
	if(volume >= 0)
	{dVolumen = volume;}
}
double Flasche::getVolumen()
{
	return dVolumen;
}

void Flasche::setMaterial(std::string material)
{
	sMaterial = material;
}

void Flasche::getMaterial()
{
	cout << sMaterial << endl;
}

void Flasche::printFlasche()
{
	cout << "volume(ml):" << getVolumen() << endl;
	cout << "made of: ";
	getMaterial();
	cout << endl;
}

void Flasche::adoptFlasche(Flasche f2)
{
	setVolumen(f2.dVolumen);
	setMaterial(f2.sMaterial);
}
