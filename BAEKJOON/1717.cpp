#include <cstdio>

using namespace std;
int parent[1000001];
int Find(int x)
{
	if (x == parent[x])
	{
		return x;
	}

	return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
	int x = Find(a);
	int y = Find(b);

	if (x != y)
	{
		parent[y] = x;
	}
}

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}
	int a, b, c;


	for(int i=0; i<m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a)
		{
			if (Find(b) == Find(c))
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
		else
		{
			Union(b, c);
		}
	}

	return 0;
}