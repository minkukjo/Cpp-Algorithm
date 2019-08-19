#include <iostream>

using namespace std;

long long recur(long long N, long long M)
{
	static long long memo[1001][1001];

	if (memo[N][M] > 0)
	{
		return memo[N][M];
	}

	if (N == M || M == 0) return memo[N][M] = 1;

	return memo[N][M] = ( recur(N - 1, M - 1) % 10007 + recur(N - 1, M) % 10007) % 10007;
}

int main()
{
	long long N, M;
	long long sum = 0;
	scanf("%lld %lld", &N, &M);

	sum = recur(N, M) ;
	cout << sum << endl;
	return 0;
}