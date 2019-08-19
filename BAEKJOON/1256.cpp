#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX_K 1000000010
int N, M, K;
int dic[101*2+2][101*2+2];

void calcBino()
{
	for (int i = 0; i <= N + M; i++)
	{
		dic[i][0] = dic[i][i] = 1;

		for (int j = 1; j < i; j++)
		{
			dic[i][j] = min(MAX_K, dic[i - 1][j - 1] + dic[i - 1][j]);
		}
	}
}

string solve(int n, int m, int skip)
{
	if (n == 0) return string(m, 'z');

	if (skip <= dic[n + m - 1][n - 1]) return  "a" + solve(n - 1, m, skip);
	return "z" + solve(n, m - 1, skip - dic[n + m - 1][n - 1]);
}
int main()
{
	cin >> N >> M >> K;

	calcBino();

	if (dic[N + M][N] < K)
	{
		cout << -1;
	}
	else
	{
		cout << solve(N, M, K);
	}

	return 0;
}