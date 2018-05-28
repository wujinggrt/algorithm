#include <sstream>
#include <iostream>
#include <vector>
#include <string>

#include "Stack.h"

using namespace std;

// enter decimal number and output octal format
void Coversion()
{
	SqStack<int> st;
	int decimal = 0;
	int octal = 0;
	cout << "enter demcial number:";
	cin >> decimal;
	while (decimal)
	{
		st.Push(decimal % 8);
		decimal /= 8;
	}
	while (!st.StackEmpty())
	{
		int out;
		st.Pop(out);
		cout << out;
	}
	cout << endl;
}

void ParentheseCheck()
{
	cout << "Enter parenthese:";
	SqStack<char> st;
	bool status = true;
	string data;
	cin >> data;
	for(auto c : data)
	{
		cout << c << endl;
		switch (c)
		{
		case '(':
			st.Push(c);
			break;
		case ')':
			if (st.StackEmpty()) 
			{
				status == false;
			}
			else
			{
				char temp;
				st.Pop(temp);
			}
			break;
		default:
			break;
		}
	}
	if (status && st.StackEmpty()) 
	{
		cout << "right" << endl;
	}
	else
	{
		cout << "ERROR" << endl;
	}
}

// �ж�string�Ƿ�����
bool IsDigit(const string &s)
{
	for (const auto &c : s)
	{
		if (c > '9' || c < '0')
		{
			return false;
		}
	}
	return true;
}

void EvaluatePostfixExpress()
{
	SqStack<char> st;
	cout << "enter numbers you want to calculate, and separat them by at least one space" << endl;
	string lines;
	getline(cin, lines);
	istringstream is(lines);
	string data;
	SqStack<int> numStack;
	SqStack<string> operatorStack;
	while (is >> data)
	{
		if (IsDigit(data))
		{
			numStack.Push(stoi(data));
		}
		else
		{
			if (data == "+")
			{

			}
			else if (data == "-")
			{

			}
			operatorStack.Push(data);
		}
	}

}


int main()
{
	cin.ignore();
	cin.get();
	return 0;
}
