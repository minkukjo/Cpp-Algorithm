#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int map[1001][1001];
string str1, str2;
int main()
{
	string tmp1, tmp2;
	cin >> tmp1 >> tmp2;


	str1 = '0' + tmp1;
	str2 = '0' + tmp2;

	int len1 = str1.size();
	int len2 = str2.size();

	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (i == 0 || j == 0)
			{
				map[i][j] = 0;
				continue;
			}

			if (str1[i] == str2[j])
			{
				map[i][j] = map[i - 1][j - 1] + 1;
			}
			else
			{
				if (map[i - 1][j] > map[i][j - 1])
				{
					map[i][j] = map[i - 1][j];
				}
				else
				{
					map[i][j] = map[i][j - 1];
				}
			}
		}
	}

	int x, y;
	stack<int> st;
	x = len1 - 1;
	y = len2 - 1;
	

	while (map[x][y] != 0)
	{

		if (map[x][y] == map[x][y - 1])
		{
			y--;
		}
		else if (map[x][y] == map[x - 1][y])
		{
			x--;
		}
		else if (map[x][y] -1 == map[x-1][y-1])
		{
			st.push(x);
			x--;
			y--;
		}
	}

	
	cout << map[len1 - 1][len2 - 1] << endl;

	while (!st.empty())
	{
		cout << str1[st.top()];
		st.pop();
	}
	return 0;
}