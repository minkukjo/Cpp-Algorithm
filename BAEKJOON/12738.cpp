#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	vector<int> D;
	D.push_back(-1000000000);

	for (int num : v)
	{
		if (D.back() < num)
		{
			D.push_back(num);
			ans++;
		}
		else
		{
			// iterator ¹ÝÈ¯
			auto it = lower_bound(D.begin(), D.end(), num);
			*it = num;
		}
	}

	printf("%lld\n", ans);

	return 0;
}