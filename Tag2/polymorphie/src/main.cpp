/*
 * main.cpp
 *
 *  Created on: Apr 2, 2022
 *      Author: jun
 */

#include "Poly.h"

int main()
{
	A a = A();
	a.f();
	// output: A.f A.h A.i

	B b = B();
	b.g();
	// output: B.g  B.f   A.f A.h A.i   A.h A.i
	// B::g() overrides A::g()
	// B::f() overrides A::f()
	// B::h = A::h; B::i = A::i >> directly inherited from A
	// B::i() is virtual, can be overridden by B's child
	// B::h() is NOT virtual, CANNOT be overridden, it keeps B::h = A::h

	C c = C();
	c.g();
	c.h();
	// output: C.g  B.f   A.f A.h C.i   A.h C.i
	// C::g() overrides B::g()
	// C::f = B::f >> directly inherited from B
	// C::h() is a brand new h for C, which is different from A::h()
	// C also inherits A::h() per B. i.e. here C::h is overloaded.
	// C::i() overrides B::i(), which was inherited from A

//	B b0 = A();
//	b0.g();
	// Error: cannot declare a child class object using parent class
	// B has all what A has; but A does not have all what B has.

	A a1 = B();
	a1.f();
	// output: A.f A.h A.i
	// B has all what A has

	A a2 = b;
	a2.f();
	// output: A.f A.h A.i
	// ?????

	A* a3 = &b;
	a3->f();
	// output: B.f   A.f A.h A.i   A.h A.i
	// a3 is a pointer, an address of a class A object
	// a3 points to objects b

	return 0;
}
