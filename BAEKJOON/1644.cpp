#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> v;
int arr[4000001];



int main()
{
	int N;
	cin >> N;

	fill(begin(arr), begin(arr) + N+1, 1);


	for (int i = 2; i*i <= N; i++)
	{
		if (arr[i])
		{
			for (int j = i * i; j <= N; j += i)
				arr[j] = 0;
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (arr[i])
		{
			v.push_back(i);
		}
	}

	int first = 0;
	int last = 0;
	int sum = 0;
	int ans = 0;


	while (1)
	{

		if (sum > N)
		{
			sum -= v[first++];
		}
		else if (last == v.size()) break;
		else
		{
			sum += v[last++];
		}

		if (sum == N) ans++;

	}
	cout << ans << endl;



	return 0;
}