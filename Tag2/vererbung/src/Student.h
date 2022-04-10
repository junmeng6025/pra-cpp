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
	unsigned int m_uiStudentID;

public:
	Student(std::string name, std::string suname, int age, unsigned int stuID);
	~Student();
	unsigned int getStudentID();
	std::string getName();
};

#endif /* STUDENT_H_ */
