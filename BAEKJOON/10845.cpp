#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	queue<int> q;
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
			q.push(k);
		}
		else if (!a.compare("front"))
		{
			if (q.empty())
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", q.front());
			}
			
		}
		else if (!a.compare("back"))
		{
			if (q.empty())
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", q.back());
			}
			
		}
		else if (!a.compare("size"))
		{
			printf("%d\n", q.size());
		}
		else if (!a.compare("empty"))
		{
			if (q.empty())
			{
				printf("1\n");
			}
			else if (!q.empty())
			{
				printf("0\n");
			}
		}
		else if (!a.compare("pop"))
		{
			if (q.empty())
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", q.front());
				q.pop();
			}
		}
	}
	return 0;
}