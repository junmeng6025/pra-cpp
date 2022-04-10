/*
 * Poly.h
 *
 *  Created on: Apr 2, 2022
 *      Author: jun
 */

#ifndef POLY_H_
#define POLY_H_

#include <iostream>
#include <string>

class A
{
public:
	virtual void g(){std::cout << "A.g\n"; f();}
	virtual void f(){std::cout << "A.f\n"; h();}
	void h(){std::cout << "A.h\n"; i();}
	virtual void i(){std::cout << "A.i\n";}
};

class B: public A
{
public:
	void g(){std::cout << "B.g\n"; f();}
	void f(){std::cout << "B.f\n"; A::f(); h();}
};

class C: public B
{
public:
	void g(){std::cout << "C.g\n"; f();}
	void h(){std::cout << "C.h\n"; i();}
	void i(){std::cout << "C.i\n";}
};

#endif /* POLY_H_ */
