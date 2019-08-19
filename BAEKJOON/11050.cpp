#include <iostream>

using namespace std;

int recur(int N, int K)
{
	if (N == K || K == 0) return 1;

	return recur(N - 1, K - 1) + recur( N - 1, K);
}

int main()
{
	int N, K;
	int sum = 0;
	scanf("%d %d", &N, &K);

	sum = recur(N, K);

	cout << sum << endl;

	return 0;
}