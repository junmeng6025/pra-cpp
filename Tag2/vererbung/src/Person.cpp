/*
 * Person.cpp
 *
 *  Created on: Apr 1, 2022
 *      Author: jun
 */

#include "Person.h"
using namespace std;

Person::Person(string name, string suname, int age)
{
	m_sName = name;
	m_sSuname = suname;
	m_iAge = age;
}

Person::~Person(){}

string Person::getName()
{
	return m_sName;
}

string Person::getSuname()
{
	return m_sSuname;
}

int Person::getAge()
{
	return m_iAge;
}

bool Person::setAge(int inAge)
{
	if(inAge >= 0)
	{
		m_iAge = inAge;
		return true;
	}
	else
	{
		return false;
	}
}
