#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int map[1001][1001];

int main()
{
	string tmp1, tmp2;
	cin >> tmp1 >> tmp2;

	string str1, str2;
	str1 = '0' + tmp1;
	str2 = '0' + tmp2;

	int len1 = str1.size();
	int len2 = str2.size();

	for (int i = 1; i < len1; i++)
	{
		for (int j = 1; j < len2; j++)
		{
			if (str1[i] == str2[j])
			{
				map[i][j] = map[i - 1][j - 1] + 1;
			}
			else
			{
				map[i][j] = max(map[i - 1][j], map[i][j - 1]);
			}
		}
	}

	cout << map[len1-1][len2-1] << endl;



	return 0;
}