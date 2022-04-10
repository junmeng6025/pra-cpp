/*
 * Square.h
 *
 *  Created on: Mar 31, 2022
 *      Author: jun
 */

#ifndef SQUARE_H_
#define SQUARE_H_

class Square
{
private:
	double m_sidelen;
public:
	Square(double sidelen);
	~Square();
	double getSidelen() const;
	Square(const Square &sqr1);
	double getCircum() const;
	double getArea() const;
};

#endif /* SQUARE_H_ */
