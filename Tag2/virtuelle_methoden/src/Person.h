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
public:
	enum language{chn, en, de};

	// Declaration of virtual methods
//	virtual ~Person();
	virtual std::string getName() = 0;
	virtual int getAge() = 0;
	virtual std::string getLanguage() = 0;
	virtual void isOlder21() = 0;
};

#endif /* PERSON_H_ */
