/*
 * writeFile.h
 *
 *  Created on: Apr 2, 2022
 *      Author: jun
 */

#ifndef WRITEFILE_H_
#define WRITEFILE_H_

#include <iostream>
#include <fstream>
#include <string>

int write_file(std::string filename)
{
	std::ofstream ofile;
	ofile.open(filename.c_str(), std::ios::app);
	if(ofile.is_open())
	{
		std::string newtext;
		std::cout << "\nPlease type new text to add to the file:\n(type < exit > to quit)\n" << std::endl;
		while(getline(std::cin, newtext))
		{
			if(newtext == "exit")
			{break;}
			else
			{ofile << newtext << std::endl;;}
		}
		ofile.close();
	}
	else
	{
		std::cout << "ERROR: File <" << filename << "> was not successfully loaded." << std::endl;
	}

	return 0;
}

#endif /* WRITEFILE_H_ */
