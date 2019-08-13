#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	stack<int> s;
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		if (!a.compare("push"))
		{
			int k;
			cin >> k;
			s.push(k);
		}
		else if (!a.compare("top"))
		{
			if (s.empty())
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", s.top());
			}

		}
		else if (!a.compare("size"))
		{
			printf("%d\n", s.size());
		}
		else if (!a.compare("empty"))
		{
			if (s.empty())
			{
				printf("1\n");
			}
			else if (!s.empty())
			{
				printf("0\n");
			}
		}
		else if (!a.compare("pop"))
		{
			if (s.empty())
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", s.top());
				s.pop();
			}
		}
	}
	return 0;
}