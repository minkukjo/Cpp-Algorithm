#include <iostream>
#include <algorithm>
using namespace std;

int a[101], b[101];
int d[1000001];
int sum;

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		sum += b[i];
	}
	for (int i = 0; i < n; i++) 
	{
		for (int j = sum; j >= b[i]; j--)
		{
			d[j] = max(d[j], d[j - b[i]] + a[i]);
		}
	}
	int i;
	for (i = 0; i < sum && d[i] < m; i++);
	cout << i << endl;
	return 0;
}