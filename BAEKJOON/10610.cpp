#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main()
{
	string a;
	long long ans = 0;

	cin >> a;

	sort(a.begin(), a.end());

	for (int i = 0; i < a.size(); i++)
	{
		int temp = a[i] - '0';
		ans += temp;
	}




	if ( (a[0] == '0') && (ans % 3 == 0) )
	{
		reverse(a.begin(), a.end());
		cout << a << endl;
	}
	else
	{
		cout << -1 << endl;
	}


	return 0;
}