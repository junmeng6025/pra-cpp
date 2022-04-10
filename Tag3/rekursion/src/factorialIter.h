/*
 * factorialIter.h
 *
 *  Created on: Apr 2, 2022
 *      Author: jun
 */

#ifndef FACTORIALITER_H_
#define FACTORIALITER_H_

int factorialIter(int inNum)
{
	if(inNum <= 0)
	{
		return 0;
	}
	else
	{
		int outNum = inNum;
		for(int iter = 1; iter < inNum; iter++)
		{
			outNum = outNum * (inNum - iter);
		}
		return outNum;
	}
}

#endif /* FACTORIALITER_H_ */
