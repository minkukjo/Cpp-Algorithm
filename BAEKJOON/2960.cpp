#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> ans;

bool prime(int n)
{

	for (int i = 2; i*i <= n; i++)
	{
		if (i != n && n%i == 0)
		{
			return false;
		}
	}
	return true;
}
void calculate(int n, int k)
{
	bool visit[1001] = { false, };

	for (int i = 2; i <= n; i++)
	{
		if (prime(i))
		{
			v.push_back(i);
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = v[i]; j <= n; j+=v[i])
		{
			if (!visit[j])
			{
				visit[j] = true;
				ans.push_back(j);
			}
		}
	}


	cout << ans[k-1] << endl;

}

int main()
{
	int n,k;
	scanf("%d %d", &n, &k);
	calculate(n, k);
	return 0;
}