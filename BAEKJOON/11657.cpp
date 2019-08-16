#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

int main()
{
	int N;
	int M;
	int dist[501];
	vector<pair<int, int>> v[501];
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a - 1].push_back(make_pair(b - 1, c));
	}
	fill(dist, dist + N, INF);
	dist[0] = 0;
	bool negativecycle = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (auto p : v[j])
			{
				int next = p.first;
				int d = p.second;
				if (dist[j] != INF && dist[next] > dist[j] + d)
				{
					dist[next] = dist[j] + d;
					if (i == N - 1)
					{
						negativecycle = true;
					}
					
				}
			}
		}
	}

	if (negativecycle)
	{
		//puts("-1");
		printf("-1\n");
	}
	else
	{
		for (int i = 1; i < N; i++)
		{
			printf("%d\n", dist[i] != INF ? dist[i] : -1);
		}
	}

	

	return 0;
}