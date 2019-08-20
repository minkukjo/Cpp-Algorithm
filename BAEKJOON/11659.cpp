#include <iostream>

using namespace std;

int A[100001];
int D[100001];

int main()
{
	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		D[i] = D[i - 1] + A[i];
	}

	int s, e;
	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d", &s, &e);
		printf("%d\n", D[e] - D[s-1]);
	}



	return 0;
}