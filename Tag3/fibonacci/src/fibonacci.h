/*
 * fibonacci.h
 *
 *  Created on: Apr 2, 2022
 *      Author: jun
 */

#ifndef FIBONACCI_H_
#define FIBONACCI_H_

int fibonacciRec (int iIn)
{
	if(iIn <= 0)
	{return 0;}
	else if(iIn <=2 )
	{return 1;}
	else
	{return fibonacciRec(iIn - 1) + fibonacciRec(iIn - 2);}
}

#endif /* FIBONACCI_H_ */
