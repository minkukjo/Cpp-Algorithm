#include <iostream>

using namespace std;
int a[501][501];
int DP[501][501];
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i][0] >> a[i][1];
	}

	for (int i = 1; i <= N; i++)
	{
		DP[i][i + 1] = a[i][0] * a[i][1] * a[i + 1][1];
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= N-i; j++)
		{
			int t = i + j;
			for (int k = j; k < t; k++)
			{
				int temp = DP[j][k] + DP[k + 1][t] + a[j][0] * a[k][1] * a[t][1];
				if (DP[j][t] == 0 || DP[j][t] > temp)
				{
					DP[j][t] = temp;
				}
			}
		}
	}
	cout << DP[1][N] << endl;

	return 0;
}