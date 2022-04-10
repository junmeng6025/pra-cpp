/*
 * readFile.h
 *
 *  Created on: Apr 2, 2022
 *      Author: jun
 */

#ifndef READFILE_H_
#define READFILE_H_

#include <iostream>
#include <fstream>
#include <string>
#include "NoFileException.h"

bool read_file(std::string filename)
{
	std::ifstream ifile;
	ifile.open(filename.c_str(), std::ios::in);

	//############ catch the error ############
//	NoFileException nofile = NoFileException(filename);
	NoFileException nofile;
	if(ifile.fail())
	{
		throw nofile;
		ifile.clear();
	}
	//#########################################

	if(ifile.is_open())
	{
		std::cout << "\nReading from the file:\n" << std::endl;
		std::string textline;
		while(getline(ifile, textline))
		{
			std::cout << textline << std::endl;
		}
		ifile.close();
		return true;
	}
	else
	{
		std::cout << "ERROR: File <" << filename << "> was not successfully loaded." << std::endl;
		return false;
	}

}

#endif /* READFILE_H_ */
