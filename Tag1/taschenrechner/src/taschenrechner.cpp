/*
 * taschenrechner.cpp
 *
 *  Created on: Mar 28, 2022
 *      Author: jun
 */

#include <iostream>
using namespace std;

int main()
{
	char op;
	float num1, num2, ans;
	bool flg_op = false;

	cout << "Input the first number: " << endl;
	cin >> num1;
	while(cin.fail())
	{
		cout << "ERROR: Wrong data type. Please input a number." << endl;
		cin.clear();
		cin.ignore(1, '\n');
		cin >> num1;
	}

	cout << "Select an operator from +, -, *, and /: " << endl;
	cin >> op;

	do
	{
		// TODO: Improvement: Use a vector ops={'+', '-', '*', '/'} to check if op is legal
		if (op == '+' or op == '-' or op == '*' or op == '/')
		{
			flg_op = true;
		}
		else
		{
			flg_op = false;
			cout << "ERROR: Wrong operator. Please select an operator from +, -, *, and /." << endl;
			cin >> op;
		}

	}
	while(flg_op == false);

	cout << "Input the second number: " << endl;
	cin >> num2;
	while(cin.fail())
	{
		cout << "ERROR: Wrong data type. Please input a number." << endl;
		cin.clear();
		cin.ignore(1, '\n');
		cin >> num2;
	}

	switch(op)
	{
		case '+':
			ans = num1 + num2;
			break;

		case '-':
			ans = num1 - num2;
			break;

		case '*':
			ans = num1 * num2;
			break;

		case '/':
			if (num2 == 0)
			{
				cout << "ERROR: cannot divided by 0." << endl;
				break;
			}
			else
			{
			ans = num1 / num2;
			break;
			}
		default:
			cout << "ERROR: Select an operator from +, -, *, and /" << endl;
			break;
	}
	cout << "= " << ans << endl;
	return 0;
}
