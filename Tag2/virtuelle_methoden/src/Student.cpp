/*
 * Student.cpp
 *
 *  Created on: Apr 1, 2022
 *      Author: jun
 */

#include "Student.h"
#include "Person.h"
#include<iostream>
using namespace std;

Student::Student(std::string name, int age, unsigned int stuID)
{
	m_sName = name;
	m_iAge = age;
	m_language = language(rand()%3);
	m_uiStudentID = stuID;
}

//Student::~Student(){}

unsigned int Student::getStudentID()
{
	return m_uiStudentID;
}

string Student::getName()
{
	return m_sName;
}

int Student::getAge()
{
	return m_iAge;
}

void Student::isOlder21()
{
	if(m_iAge <= 21)
	{cout << "(SemesterTicket Young)" << endl;}
	else
	{cout << "(SemesterTicket)" << endl;}
}

string Student::getLanguage()
{
	switch(m_language)
	{
	case(chn):
		return "Chinese";
		break;
	case(en):
		return "English";
		break;
	case(de):
		return "German";
		break;
	default:
		return "ERROR";
		break;
	}
}
