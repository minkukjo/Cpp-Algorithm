#include <iostream>

using namespace std;

int A[1025][1025];
int DP[1025][1025];
int main()
{
	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];
			DP[i][j] = A[i][j] + DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1];
		}
	}

	int x1, x2, y1, y2;

	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", DP[x2][y2] - DP[x1 - 1][y2] - DP[x2][y1 - 1] + DP[x1 - 1][y1 - 1]);
	}


	return 0;
}