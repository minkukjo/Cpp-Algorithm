#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[4001];
int B[4001];
int C[4001];
int D[4001];

int main()
{

	vector<int> E;
	vector<int> F;
	long long ans = 0;

	long long N;
	scanf("%lld", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
	}

	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			E.push_back(A[i] + B[j]);
			F.push_back(C[i] + D[j]);
		}
	}

	sort(E.begin(),E.end());
	sort(F.begin(), F.end());

	for (int i = 0; i < E.size(); i++)
	{
		auto a = lower_bound(F.begin(), F.end(), -E[i]);
		auto b = upper_bound(F.begin(), F.end(), -E[i]);

		while (a != b)
		{
			ans++;
			a++;
		}
	}


	printf("%lld", ans);


	return 0;
}