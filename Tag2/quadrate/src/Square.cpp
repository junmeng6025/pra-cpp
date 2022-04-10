/*
 * Square.cpp
 *
 *  Created on: Apr 1, 2022
 *      Author: jun
 */

#include "Square.h"

Square::Square(double sidelen)
{
	m_sidelen = sidelen;
}

Square::~Square(){}

double Square::getSidelen() const
{
	return m_sidelen;
}

Square::Square(const Square &sqr1)
{
	m_sidelen = sqr1.getSidelen();
}


double Square::getCircum() const
{
	return 4 * m_sidelen;
}

double Square::getArea() const
{
	return m_sidelen * m_sidelen;
}
