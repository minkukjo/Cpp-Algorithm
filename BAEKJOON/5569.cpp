#include <iostream>

using namespace std;

int DP[110][110][2][2]; // dir 1, or over2
const int m = 100000;
int main()
{
	int x, y;
	cin >> x >> y;

	for (int i = 2; i <= x; i++) DP[i][1][0][0] = 1;
	for (int i = 2; i <= y; i++) DP[1][i][1][0] = 1;

	for (int i = 2; i <= x; i++)
	{
		for (int j = 2; j <= y; j++)
		{
			DP[i][j][0][0] = (DP[i - 1][j][0][0] + DP[i - 1][j][0][1]) % m;
			DP[i][j][0][1] = DP[i - 1][j][1][0];
			DP[i][j][1][0] = (DP[i][j - 1][1][0] + DP[i][j - 1][1][1]) % m;
			DP[i][j][1][1] = DP[i][j - 1][0][0];
		}
	}

	int ans = 0;

	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) ans += DP[x][y][i][j];
	cout << ans%m << endl;

	return 0;
}