/*
 * Person.h
 *
 *  Created on: Apr 1, 2022
 *      Author: jun
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <string>

class Person
{
private:
	std::string m_sName;
	std::string m_sSuname;
	int m_iAge;

public:
	Person(std::string sName, std::string sSuname, int iAge);
	~Person();
	std::string getName();
	std::string getSuname();
	int getAge();
	bool setAge(int iAge);
};

#endif /* PERSON_H_ */
