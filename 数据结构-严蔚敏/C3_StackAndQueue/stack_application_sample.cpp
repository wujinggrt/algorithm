#include <sstream>
#include <iostream>
#include <vector>
#include <string>

#include "Stack.h"

using namespace std;

class StackSample
{
public:
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

	// To do...
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

	void move(string x, int n, string z)
	{
		static int count = 0;
		cout << (++count) 
			<< ". Move disk " 
			<< n 
			<< " from " 
			<< x
			<< " to "
			<< z 
			<< endl;
	}

	// 编号由上至下1->n
	void Hanoi(int n, string x, string y, string z)
	{
		if (n == 1)
		{
			move(x, 1, z);
		}
		// 一直递归到n = 2,那么下面else的内容就会被展开成
		// move，也就是三个move
		// 第一个:move最顶层
		// 第二个:move次顶层
		// 第三个:move最顶层的那一个（注意已经move过了）

		else
		{
			// x 上编号为1 到 n - 1的圆盘移动到y
			// z 是辅助
			Hanoi(n - 1, x, z, y); 
			// 移动第n个，也就是底端上那个到z
			move(x, n, z);
			// y上编号为1到n-1的圆盘移动到z
			// x是辅助
			Hanoi(n - 1, y, x, z);
		}
	}
	// Hanoir

	void RunHanoi()
	{
		int i;
		cin >> i;
		Hanoi(i, "A", "B", "C");
	}
};

int main()
{
	StackSample sp;
	sp.RunHanoi();
	return 0;
}
