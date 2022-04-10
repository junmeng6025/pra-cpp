/*
 * Coord.h
 *
 *  Created on: Apr 6, 2022
 *      Author: pi
 */

#ifndef COORD_H_
#define COORD_H_

struct Coord
{
	double m_dX, m_dY, m_dV;
	Coord(double dX, double dY, double dV)
	{
		m_dX = dX;
		m_dY = dY;
		m_dV = dV;
	}
};

#endif /* COORD_H_ */
