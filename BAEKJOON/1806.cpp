#include <iostream>

using namespace std;

int min(int a, int b)
{
	if (a > b)
	{
		return b;
	}
	else
	{
		return a;
	}
}
int main()
{
	int N,M;
	long long* s, *e;
	long long S;
	long long A[100001];
	int sum = 0;
	int len = 0;
	int ans = 999999;
	s = &A[1];
	e = &A[1];

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]);
	}

	while (true)
	{

		if (sum < M && e <= &A[N])
		{
			sum += *e;
			len++;
			e++;
		}
		else
		{
			sum -= *s;
			len--;
			s++;
		}

		if (sum >= M)
		{
			ans = min(len, ans);
		}

		if (s == &A[N])
		{
			break;
		}
	}

	if (ans == 999999) ans = 0;
	printf("%d", ans);

	


	return 0;
}