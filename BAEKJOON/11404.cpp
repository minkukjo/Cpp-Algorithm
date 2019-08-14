#include <iostream>
#include <string>
using namespace std;

int city[103][103];

int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main()
{
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			city[i][j] = 999999;
		}
	}

	for (int i = 0; i< m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (city[a][b] == 999999)
		{
			city[a][b] = c;
		}
		else
		{
			if (city[a][b] > c)
			{
				city[a][b] = c;
			}
		}
		
	}


	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i != j)
				{
					city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
				}
				
			}
		}
	}



	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (city[i][j] == 999999)
			{
				cout << 0 ;
			}
			else
			{
				cout << city[i][j];
			}

			if (j != n ) cout << " ";
		}
		cout << endl;
	}


	return 0;
}