/*
 * main.cpp
 *
 *  Created on: Apr 1, 2022
 *      Author: jun
 */

#include "Person.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Person p1 = Person("JunMeng", "", 25);
	cout<< "Name of p1: " << p1.getName() << endl;

	Student s1 = Student("JunMeng", "", 25, 3741999);
	cout<< "Name of s1: " << s1.getName() << endl;

	Person p2 = Person("JunMeng", "", 25);
	cout<< "Name of p2: " << p2.getName() << endl;

	p2 = s1;
	cout<< "Name of overwritten p2 (i.e. p2 = s1): " << p2.getName() << endl;

	return 0;
}
