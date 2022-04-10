/*
 * printList.hpp
 *
 *  Created on: Apr 3, 2022
 *      Author: jun
 */

#ifndef PRINTLIST_HPP_
#define PRINTLIST_HPP_

#include "Coord.hpp"
#include <iostream>
#include <string>

int printlist(std::list<Coord>* pCoordLs)
{
	std::list<Coord>::iterator i;
	for(i = pCoordLs->begin(); i != pCoordLs->end(); i++)
		{std::cout << "X: " << i->m_fX << ", Y: " << i->m_fY << std::endl;}
	return 0;
}

#endif /* PRINTLIST_HPP_ */
