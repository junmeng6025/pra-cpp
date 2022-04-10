/*
 * Student.h
 *
 *  Created on: Apr 1, 2022
 *      Author: jun
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include "Person.h"

class Student : public Person
{
private:
	// common attributes from parent class
	std::string m_sName;
	int m_iAge;
	language m_language;
	// special attribute for child class
	unsigned int m_uiStudentID;

public:
	Student(std::string name, int age, unsigned int stuID);
//	~Student();

	// overwrite virtual methods from class Person
	std::string getName();
	int getAge();
	std::string getLanguage();
	void isOlder21();

	// special
	unsigned int getStudentID();


};

#endif /* STUDENT_H_ */
