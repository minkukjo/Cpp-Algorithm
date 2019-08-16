#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

#define INF 1000000000

using namespace std;

int main()
{
	int V, E, K;
	vector<pair<int, int>> vec[20001];
	scanf("%d %d %d", &V, &E, &K);
	K--;
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		vec[u - 1].push_back(make_pair(v - 1, w));
	}

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	int dist[20001];
	fill(dist, dist + 20001, INF);
	bool visit[20001] = { false, };
	pq.push(make_pair(0,K));
	dist[K] = 0;

	while (!pq.empty())
	{
		int cur;
		do
		{
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visit[cur]);
		if (visit[cur]) break;

		visit[cur] = true;
		for (auto a : vec[cur])
		{
			int next = a.first;
			int d = a.second;

			if (dist[next] > dist[cur] + d)
			{
				dist[next] = dist[cur] + d;
				pq.push(make_pair(dist[next],next));
			}
		}
	}

	for (int i = 0; i < V; i++)
	{
		if (dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}

	return 0;
}
