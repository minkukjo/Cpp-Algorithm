#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int map[4001][4001];

int main()
{
	string a, b;
	string smallstr;
	string bigstr;
	cin >> a >> b;
	int bigsize;
	int smallsize;
	int ans = 0;
	if (a.length() < b.length())
	{
		bigsize = b.length();
		smallsize = a.length();
		bigstr = b;
		smallstr = a;
	}
	else
	{
		bigsize = a.length();
		smallsize = b.length();
		bigstr = a;
		smallstr = b;
	}



	for (int i = 1; i <= smallsize; i++)
	{
		for (int j = 1; j <= bigsize; j++)
		{
			if (smallstr[i-1] == bigstr[j-1])
			{
				if (map[i - 1][j - 1])
				{
					map[i][j] = map[i - 1][j - 1] + 1;
					ans = max(ans, map[i][j]);
				}
				else
				{
					map[i][j] = 1;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}