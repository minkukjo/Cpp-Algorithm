#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char s[110];
int K;
int arr[2000001];
vector<int> v;

bool know(char* s, int p)
{
	int ret = 0;
	for (int i = 0; s[i]; i++)
	{
		ret *= 10;
		ret += s[i] - '0';
		ret %= p;
	}
	return ret == 0;
}

int main()
{
	scanf("%s %d", &s, &K);

	for (int i = 2; i <= 2000000; i++)
	{
		if (!arr[i])
		{
			v.push_back(i);
			for (int j = i + i; j <= 2000000; j += i)
			{
				arr[j] = 1;
			}
		}
		
	}



	int r = 0;
	int pp = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] >= K) break;
		if (know(s, v[i]))
		{
			printf("BAD %d\n", v[i]);
			return 0;
		}
	}
	printf("GOOD\n");

	return 0;

}