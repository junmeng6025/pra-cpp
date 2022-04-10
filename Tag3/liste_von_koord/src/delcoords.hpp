/*
 * delCoords.hpp
 *
 *  Created on: Apr 3, 2022
 *      Author: jun
 */

#ifndef DELCOORDS_HPP_
#define DELCOORDS_HPP_

#include "Coord.hpp"

std::list<Coord> delcoords(std::list<Coord>& rCoordLs)
{
	std::list<Coord>::iterator i;
	for(i = rCoordLs.begin(); i != rCoordLs.end();)
	{
		if(i->m_fX < i->m_fY)
		{
			i = rCoordLs.erase(i);
		}
		else
		{++i;}
	}
	return rCoordLs;
}

#endif /* DELCOORDS_HPP_ */
