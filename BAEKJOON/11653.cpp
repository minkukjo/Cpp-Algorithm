#include <iostream>

using namespace std;

int main()
{
	int N;
	int div = 2;
	scanf("%d", &N);

	while (1)
	{
		if (N == 1)
		{
			break;
		}

		if (N%div == 0)
		{
			N = N / div;
			cout << div << endl;
			div = 2;
		}
		else
		{
			div++;
		}
	}

	return 0;
}