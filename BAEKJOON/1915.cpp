#include <iostream>
#include <algorithm>
using namespace std;

int a[1001][1001];
int DP[1001][1001];
int main()
{
	int N, M;
	cin >> N >> M;

	int ans = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &a[i][j]);
			if (a[i][j])
			{
				DP[i][j] = min(min(DP[i - 1][j - 1], DP[i][j - 1]), DP[i - 1][j]) + 1;
				ans = ans > DP[i][j] ? ans : DP[i][j];
			}
		}
	}

	cout << ans*ans << endl;

	return 0;
}