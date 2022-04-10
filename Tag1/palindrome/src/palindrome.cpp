/*
 * palindrome.cpp
 *
 *  Created on: Mar 29, 2022
 *      Author: jun
 */

#include <string>
#include <iostream>
using namespace std;

char toLowercase(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		return ch - 'A' + 'a';
	}
	else
	{
		return ch;
	}
}

int main()
{
	string strin, chari, strinv="";
	cout << "Input a word: " << endl;
	cin >> strin;

	// Convert all chars in the string to lower-case ###########################################
	for(int k = 0; k < strin.size(); k++)
	{
		strin[k] = toLowercase(strin[k]);
	}

	// Execute the string inversion. #############################################################
	for(int i = strin.size() - 1; i >= 0; i--)
	{
		// Extract the i th char from the end to the head.
		chari = strin[i];
		// Add the extracted char to the top of the blank str to build a mirrored string "strinv".
		strinv.append(chari);
	}

	if(strin.compare(strinv) == 0)
	{
		// == 0: the inverted string is the same as the original.
		cout << "The word '" << strin << "' is a Palindrom!" << endl;
	}
	else
	{
		// != 0: the inverted string is different from the original.
		cout << "The word '" << strin << "' is NOT a Palindrom!" << endl;
	}
	return 0;
}
