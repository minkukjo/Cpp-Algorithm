#include <iostream>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int N, M;
		int DP[31][31] = { 0, };

		cin >> N >> M;
		// N개의 사이트와 M개의 사이트를 잇는 경우의 수
		// 여기서는 1개의 사이트와 M개의 사이트를 잇는 경우의 수를 미리 찾아놓음
		for (int i = 1; i <= M; i++)
		{
			DP[1][i] = i;
		}

		for (int i = 2; i <= N; i++)
		{
			for (int j = i; j <= M; j++)
			{
				for (int k = j; k >= i; k--)
				{
					DP[i][j] += DP[i - 1][k - 1];
				}
			}
		}

		cout << DP[N][M] << endl;

	}
	return 0;
}