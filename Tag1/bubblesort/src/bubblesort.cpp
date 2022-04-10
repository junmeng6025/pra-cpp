/*
 * bubblesort.cpp
 *
 *  Created on: Mar 29, 2022
 *      Author: jun
 */

#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubblesort(int arr[], int sz)
{
	for(int i = 0; i < sz-1; i++)
	{
		for(int j = 0; j < sz-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
			}
			else
			{
				continue;
			}
		}
	}
}

void printArray(int arr[], int sz)
{
	int i;
	for(i = 0; i < sz; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	srand(time(nullptr));

	// Dynamic storage reservation.
	int sz = 32;
	int* iStack = new int[sz];

	for(int i = 0; i < sz; i++)
	{
		iStack[i] = rand()%100 + 0;
	}

	cout << "The origin array is:" << endl;
	printArray(iStack, sz);

	// Bubble sort:
	bubblesort(iStack, sz);
	cout << "The sorted array is:" << endl;
	printArray(iStack, sz);

	// Free the storage of a dynamic arranged array.
	delete[] iStack;

	return 0;
}
