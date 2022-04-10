/*
 * Student.cpp
 *
 *  Created on: Apr 1, 2022
 *      Author: jun
 */

#include "Student.h"
#include "Person.h"
using namespace std;

Student::Student(string name, string suname, int age, unsigned int stuID): Person(name, suname, age)
{
	m_uiStudentID = stuID;
}

Student::~Student(){}

unsigned int Student::getStudentID()
{
	return m_uiStudentID;
}

string Student::getName()
{
	return ("Student " + this->Person::getName());
	// without "this->Person::" ahead of getName(), it means Student::getName() itself.
	// to overwrite getName() from class Person, we must call it using the inner-defined pointer "this" and the operator "->".
}
