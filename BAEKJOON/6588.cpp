#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000001];


int main()
{
	int N;

	for (int i = 2; i*i <= 1000000; i++)
	{
		if (!arr[i])
		{
			for (int j = i*i; j <= 1000000; j += i)
			{
				arr[j] = 1;
			}
		}
	}

	while (1)
	{
		scanf("%d", &N);
		if (N == 0) break;


		for (int i = 2; i <= 1000000; i++)
		{
			if (!arr[i])
			{
				int j = N - i;
				if (!arr[j])
				{
					printf("%d = %d + %d\n", N, i, j);
					break;
				}
			}
		}

		//cout << N << " = " << a << " + " << b << endl;
		

	}
	


	return 0;
}