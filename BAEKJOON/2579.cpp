#include <iostream>
#include <algorithm>
using namespace std;

int A[301];
int DP[301];

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}
	
	DP[1] = A[1];
	DP[2] = max(A[1] + A[2], A[2]);
	DP[3] = max(A[1] + A[3], A[2] + A[3]);
	for (int i = 4; i <= N; i++)
	{
		DP[i] = max(DP[i - 2] + A[i], A[i - 1] + A[i] + DP[i - 3]);
	}

	cout << DP[N] << endl;

	return 0;
}