/*
 * main.cpp
 *
 *  Created on: Apr 1, 2022
 *      Author: jun
 */

#include "Square.h"
#include <iostream>
#include <string>

Square operator+(Square sqr1, Square sqr2)
{
	return Square(sqr1.getSidelen() + sqr2.getSidelen());
}

Square operator-(Square sqr1, Square sqr2)
{
	return Square(sqr1.getSidelen() - sqr2.getSidelen());
}

std::ostream& operator<<(std::ostream &os, const Square &sqr)
{
	return os << "Quadrat: Kantenlänge=" << sqr.getSidelen() << ", Fläsche=" << sqr.getArea() << ", Umfang=" << sqr.getCircum();
}

int main()
{
	Square sqr1 = Square(4);
	std::cout<<"sqr1:               " << sqr1 << std::endl;
	Square sqr2 = Square(8);
	std::cout<<"sqr2:               " << sqr2 << std::endl;

	Square sqr3 = sqr1 + sqr2;
	std::cout<<"sqr3 = sqr1 + sqr2: " << sqr3 << std::endl;
	Square sqr4 = sqr1 - sqr2;
	std::cout<<"sqr4 = sqr1 - sqr2: " << sqr4 << std::endl;
	Square sqr5 = sqr2 - sqr1;
	std::cout<<"sqr5 = sqr2 - sqr1: " << sqr5 << std::endl;

	Square sqr6 = Square(sqr5);
	std::cout<<"sqr6 = sqr5:        " << sqr5 << std::endl;

	return 0;
}
