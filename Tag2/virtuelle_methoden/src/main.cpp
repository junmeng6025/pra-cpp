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
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(nullptr));

	Person* persons[2];
	// dynamic implement
	// Initialize: Student(sName, iAge, uiStuID)
	persons[0] = new Student("MJ", 25, 3741999);
	persons[1] = new Student("AA", 20, 3742000);

	for(int i = 0; i < 2; i++)
	{
		cout << "The information about the student No." << i+1 <<": " << endl;
		cout << "Name:     " << persons[i]->getName() << endl;
		cout << "Age:      " << persons[i]->getAge();
		persons[i]->isOlder21();
		cout << "Language: " << persons[i]->getLanguage() << endl << endl;
		// CANNOT call the additional method and attribute "StudentID" of the child class Student
	}

	//
	Student s1 = Student("KK", 21, 3742001);

	cout << "The information about this student" << endl;
	cout << "Name:     " << s1.getName() << endl;
	cout << "Age:      " << s1.getAge();
	s1.isOlder21();
	cout << "Language: " << s1.getLanguage() << endl;
	// Call the additional method and attribute "StudentID" of the child class Student
	cout << "StudentID:" << s1.getStudentID() << endl;

	return 0;
}
