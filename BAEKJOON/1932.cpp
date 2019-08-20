#include <iostream>
#include <algorithm>

using namespace std;

int DP[501][501];
int A[501][501];
int main()
{
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> A[i][j];
			DP[i][j] = A[i][j] + max(DP[i - 1][j - 1], DP[i - 1][j]);
		}
	}

	int ans = -1;
	for (int i = 1; i <= N; i++)
	{
		ans = max(DP[N][i], ans);
	}
	cout << ans << endl;



	return 0;
}