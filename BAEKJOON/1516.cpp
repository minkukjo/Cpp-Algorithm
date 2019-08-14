#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> vc[501];
int line[501];
int result[501];
int wating[501];

int main()
{
	int N;
	vector<int> v(501);
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{

		scanf("%d", &wating[i]);

		while(1)
		{
			int temp;
			scanf("%d",&temp);
			if(temp == -1) break;
			line[i]++;
			vc[temp].push_back(i);
		}
	}

	queue<int> q;
	for(int i=1; i<=N; i++)
	{
		if(line[i] == 0)
		{
			q.push(i);
		}
		result[i] += wating[i];
	}


	for(int i=0;i<N;i++)
	{
		int top = q.front();
		q.pop();
		for(int j=0;j<vc[top].size(); j++)
		{
			int next = vc[top][j];
			result[next] = max(result[next],result[top]+wating[next]);

			if(--line[next] == 0)
			{
				q.push(next);
			}

		}
	}

	for(int i=1; i<=N; i++)
	{
		printf("%d\n",result[i]);

	}


	return 0;
}