/*
 * buchstaben.cpp
 *
 *  Created on: Mar 29, 2022
 *      Author: jun
 */

#include <string>
#include <iostream>
using namespace std;

// Disarrange the char in a word:
string disarrange(string wordin)
{
	char chrtemp;
	for(unsigned i = 1; i < wordin.size() - 2; i = i + 2)
	{
		chrtemp = wordin[i];
		wordin[i] = wordin[i+1];
		wordin[i+1] = chrtemp;
	}

	return wordin;
}

// Wipe the vowels in a word.
// TODO: didn't consider Umlauten ä, ö, ü.
string wipeVowel(string wordin)
{
	for(unsigned i = 0; i < wordin.size(); i++)
	{
		// TODO: Improvement: Use a vector vowels={'a', 'e', 'i', 'o', 'u'} to check if wordin[i] is a vowel.
		if(wordin[i] == 'a' or wordin[i] == 'e' or wordin[i] == 'i' or wordin[i] == 'o' or wordin[i] == 'u')
		{
			wordin.replace(i, 1, "");
			// Rest the indicator i the former position.
			i--;
		}
		else
		{
			continue;
		}
	}

	return wordin;
}

// Main function:
int main()
{
	string wordin, worddisarr, wordnonvo;
	cout << "Input a word: " << endl;
	cin >> wordin;

	worddisarr = disarrange(wordin);
	cout << "The disarranged word: " << worddisarr << endl;

	wordnonvo = wipeVowel(wordin);
	cout << "The word without vowel: " << wordnonvo << endl;

	return 0;
}
