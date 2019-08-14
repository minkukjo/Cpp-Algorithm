#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	queue<int> q;
	queue<int> ans;
	int arr[32001] = { 0, };
	vector<int> v[32001];
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		arr[b]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (arr[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		ans.push(temp);

		for (int i = 0; i < v[temp].size(); i++)
		{
			arr[v[temp][i]]--;

			if (arr[v[temp][i]] == 0)
			{
				q.push(v[temp][i]);
			}
		}
	}


	while (!ans.empty())
	{
		cout << ans.front() << " ";
		ans.pop();
	}
	return 0;
}