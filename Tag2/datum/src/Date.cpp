/*
 * Date.cpp
 *
 *  Created on: Mar 31, 2022
 *      Author: jun
 */

#include "Date.h"
#include <cstdlib>
#include <iostream>
using namespace std;


Date::Date()
{
	m_year = rand()% (2030 - 1970) + 1970;
//	m_year = 2022;
	m_month = rand()% 12 + 1;
//	m_month = 3;
	if(m_month == 1 or m_month == 3 or m_month == 5 or m_month == 7 or m_month == 8 or m_month == 10 or m_month == 12)
	{m_day = rand()% 31 + 1;}
	else if (m_month == 2)
	{m_day = rand()% 28 + 1;}
	else
	{m_day = rand()% 30 + 1;}
}

// Fehler im Listing: abwesend Date:: vor getDay()
int Date::getDay()
{return m_day;}

int Date::getMonth()
{return m_month;}

int Date::getYear()
{return m_year;}

//void Date::setDay(int d)
//{m_day = d;}
//
//void Date::setMonth(int m)
//{m_month = m;}
//
//void Date::setYear(int y)
//{m_year = y;}

bool Date::isEqual(Date dd)
{
	if(m_day == dd.m_day && m_month == dd.m_month && m_year == dd.m_year)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Date::compare(Date d2)
{
	// hierarchical comparison: year comp. >> month comp. >> day comp.
	if(getYear() > d2.getYear())
	{return 1;}
	else if(getYear() == d2.getYear() and getMonth() > d2.getMonth())
	{return 1;}
	else if(getYear() == d2.getYear() and getMonth() == d2.getMonth() and getDay() > d2.getDay())
	{return 1;}

	else if(getYear() == d2.getYear() and getMonth() == d2.getMonth() and getDay() == d2.getDay())
	{return 0;}

	else
	{return -1;}
}

void Date::printDate()
{
	cout << "The date in the form of dd,mm,yyyy is: " << getDay() << "," << getMonth() << "," << getYear() << "." << endl;
}
