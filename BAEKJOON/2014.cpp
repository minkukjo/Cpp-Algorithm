#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

priority_queue<long long,vector<long long>,greater<long long>> pq;
bool check[10000] = { false, };
vector<int> v;
int main()
{
	int K, N;

	scanf("%d %d", &K, &N);

	for (int i = 0; i < K; i++)
	{
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}

	for (int i = 0; i < v.size(); i++)
	{
		pq.push(v[i]);
	}

	long long head = 0;
	for (int i = 0; i < N; i++)
	{
		head = pq.top();
		pq.pop();
		for (int j = 0; j < K; j++)
		{
			long long value = head * v[j];
			pq.push(value);

			if (head%v[j] == 0)
			{
				break;
			}
		}
	}

	cout << head << endl;

	return 0;
}