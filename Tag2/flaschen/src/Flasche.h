/*
 * flasche.h
 *
 *  Created on: Mar 30, 2022
 *      Author: jun
 */

#ifndef FLASCHE_H_
#define FLASCHE_H_

#include <string>

// Declaration class
class Flasche
{
// Declaration attributes
private:
	double dVolumen;
	std::string sMaterial;

// Declaration methods
public:
	Flasche();
	~Flasche();

	void setVolumen(double);
	double getVolumen();

	void setMaterial(std::string);
	void getMaterial();

	void printFlasche();
	void adoptFlasche(Flasche f2);
};

#endif /* FLASCHE_H_ */
