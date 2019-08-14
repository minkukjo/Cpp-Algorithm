#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long n;

	while(1 == scanf("%lld",&n))
	{
		if (n == 1)
		{
			cout << 1 << endl;
		}
		else
		{
			long long k, ans;
			for (k = ans = 1; ans; k++)
			{
				ans = (ans * 10 + 1) % n;
			}
			cout << k << endl;
		}
		
	}
	return 0;
}