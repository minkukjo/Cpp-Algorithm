#include <iostream>

using namespace std;

int map[501][501];

int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	return b;
}
int main()
{
	int n, m;
	int ans = 0;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) map[i][j] = 0;
			else map[i][j] = 999999;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) map[i][j] = min(map[i][j], map[i][k] + map[k][j]);

	for (int i = 1; i <= n; i++)
	{
		int flag = 1;
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 999999 && map[j][i] == 999999)
			{
				flag = 0;
				break;
			}
		}
		if (flag) ans++;
	}

	cout << ans << endl;

	return 0;
}