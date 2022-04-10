/*
 * nofileException.h
 *
 *  Created on: Apr 3, 2022
 *      Author: jun
 */

#ifndef NOFILEEXCEPTION_H_
#define NOFILEEXCEPTION_H_

#include <iostream>
#include <exception>

class NoFileException: public std::exception
{
// TODO: How could I also print the filename in the ERROR message?

//private:
//	std::string m_sFilename;
//
//public:
//	NoFileException(std::string sFilename)
//	{
//		m_sFilename = sFilename;
//	}
//
//	~NoFileException(){}
public:
	virtual const char* what() const throw()
	{
		return "The file does not exist.";
//		return "The file <" + m_sFilename + "> does not exist.";
		// Tried to print filename in the error message
		// Error Report: const cannot be modified.
	}
};

#endif /* NOFILEEXCEPTION_H_ */
