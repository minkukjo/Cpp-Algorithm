#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;


int main()
{
	stack<char> s;
	string a;

	int sum = 0;
	int temp = 1;
	bool impossibble = false;
	cin >> a;

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '(')
		{
			temp *= 2;
			s.push('(');
		}
		else if (a[i] == '[')
		{
			temp *= 3;
			s.push('[');
		}
		else if (a[i] == ')' && (s.empty() || s.top() != '('))
		{
			impossibble = true;
			break;
		}
		else if (a[i] == ']' && (s.empty() || s.top() != '['))
		{
			impossibble = true;
			break;
		}
		else if (a[i] == ')')
		{
			if (a[i - 1] == '(')
			{
				sum += temp;
			}
			s.pop();
			temp /= 2;
		}
		else if (a[i] == ']')
		{
			if (a[i - 1] == '[')
			{
				sum += temp;
			}
			s.pop();
			temp /= 3;
		}
	}

	if (impossibble|| !s.empty())
	{
		cout << 0 << endl;
	}
	else
	{
		cout << sum << endl;
	}


	

	return 0;
}