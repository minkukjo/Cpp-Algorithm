#include <iostream>

using namespace std;

int min(int a, int b) {
	if (a < b) return a;
	return b;
}

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int min1 = 0;
int min2 = 0;
int min3 = 0;
int min4 = 0;
int min5 = 0;
int min6 = 0;
int main()
{
	int A[3] = { 0, };
	int data[6] = { 0, };

	int N;


	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &A[0], &A[1], &A[2]);

		min1 = min(data[0], data[1]) + A[0];
		min2 = max(data[3], data[4]) + A[0];
		min3 = min(min(data[0], data[1]),data[2]) + A[1];
		min4 = max(max(data[3], data[4]),data[5]) + A[1];
		min5 = min(data[1], data[2]) + A[2];
		min6 = max(data[4], data[5]) + A[2];

		data[0] = min1;
		data[3] = min2;
		data[1] = min3;
		data[4] = min4;
		data[2] = min5;
		data[5] = min6;
	}

	int min_ans = 9999999;
	int max_ans = -1;

	for (int i = 0; i < 3; i++)
	{
		min_ans = min(min_ans, data[i]);
		max_ans = max(max_ans, data[i+3]);
	}

	printf("%d %d", max_ans, min_ans);





	return 0;
}