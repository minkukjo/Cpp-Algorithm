#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[1001];



int find(int n)
{
	if (parent[n] == n)
	{
		return n;
	}
	return parent[n] = find(parent[n]);
}

bool Union(int a, int b)
{
	int x = find(a);
	int y = find(b);
	if (x == y)
	{
		return false;
	}
	parent[y] = x;
	return true;
}

class edge
{
public:
	int u, v, cost;
	edge(int a, int b, int c) : u(a), v(b), cost(c) { ; }
};

bool compare(edge a, edge b)
{
	return a.cost < b.cost;
	
}

int main()
{
	int N, M;
	vector<edge> v;
	int sum = 0;
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		v.push_back(edge(a, b, c));
	}

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}


	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < M; i++)
	{
		if (find(v[i].u) != find(v[i].v))
		{
			Union(v[i].u, v[i].v);
			sum += v[i].cost;
		}
	}

	cout << sum << endl;


	return 0;
}