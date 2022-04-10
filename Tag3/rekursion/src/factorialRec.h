/*
 * factorialRec.h
 *
 *  Created on: Apr 2, 2022
 *      Author: jun
 */

#ifndef FACTORIALREC_H_
#define FACTORIALREC_H_


int factorialRec(int n)
{
	if(n < 1)
	{
		return 0;
	}
	else if(n == 1)
	{
		return 1;
		// Recursion ends at factorialRec(1) = 1;
	}
	else
	{
		return n * factorialRec(n - 1);
	}
}


#endif /* FACTORIALREC_H_ */
