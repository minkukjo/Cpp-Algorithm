#include <iostream>

using namespace std;

int main()
{

	int N, M;
	long long first;
	long long last;
	int height[1000000];
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", height + i);
	}

	first = 0;
	last = 1000000000;


	while (first + 1<last)
	{
		long long mid = (first + last) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (height[i] > mid)
			{
				sum += height[i] - mid;
			}
		}

		if (sum >= M)
		{
			first = mid;
		}
		else
		{
			last = mid;
		}
	}

	printf("%d", first);
	return 0;
}