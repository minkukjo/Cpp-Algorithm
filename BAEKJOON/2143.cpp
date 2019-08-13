#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[1000], b[1000];
int main()
{
	int T,N,M;
	vector<int> A;
	vector<int> B;
	scanf("%d", &T);

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &a[i]);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int temp;
		scanf("%d", &b[i]);
	}


	for (int i = 0; i < N; i++)
	{
		int sum = a[i];
		A.push_back(sum);
		for (int j = i+1; j < N; j++)
		{
			sum += a[j];
			A.push_back(sum);
		}
	}

	for (int i = 0; i < M; i++)
	{
		int sum = b[i];
		B.push_back(sum);
		for (int j = i+1; j < M; j++)
		{
			sum += b[j];
			B.push_back(sum);
		}
	}

	sort(B.begin(), B.end());

	long long ans = 0;
	for (auto item : A)
	{
		int temp = T - item;
		auto lower = lower_bound(B.begin(), B.end(), temp);
		auto upper = upper_bound(B.begin(), B.end(), temp);
		ans += (upper - lower);
	}

	printf("%lld", ans);




	return 0;
}