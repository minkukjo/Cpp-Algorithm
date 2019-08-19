#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int number[101] = { 0, };
	long long DP[101][21];
	fill(&DP[0][0], &DP[100][21], 0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> number[i];
	}

	DP[1][number[1]] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (DP[i - 1][j])
			{
				if (j - number[i] >= 0)
				{
					DP[i][j - number[i]] += DP[i-1][j];
				}

				if (j + number[i] <= 20)
				{
					DP[i][j + number[i]] += DP[i - 1][j];
				}

			}
		}
	}

	
	cout << DP[N - 1][number[N]] << endl;


	return 0;
}