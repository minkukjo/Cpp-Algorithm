#include <iostream>

using namespace std;

int main()
{
	long long A[100];
	int N;
	scanf("%d", &N);

	A[0] = 0;
	A[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		A[i] = A[i - 1] + A[i - 2];
	}

	printf("%ld", A[N]);

	return 0;
}