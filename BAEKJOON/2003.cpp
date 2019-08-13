#include <iostream>

using namespace std;

int main()
{
	int A[10001];
	int N;
	int M;
	int sum = 0;
	int ans = 0;
	int* s, *e;
	s = &A[1];
	e = &A[1];

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]);
	}

	for (;;)
	{
		

		if (sum < M)
		{
			sum += *e;
			e++;
		}
		else
		{
			sum -= *s;
			s++;
		}

		if (sum == M)
		{
			ans++;
		}
		if (s == &A[N])
		{
			break;
		}
	}


	printf("%d", ans);

	return 0;
}