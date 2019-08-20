#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
int n, a[1000000], p[1000000];
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}
int main()
{
	cin >> n;

	v.push_back(make_pair(-1, -1e9 - 1));
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (v.back().second < a[i])
		{
			p[i] = v.back().first;
			v.push_back(make_pair(i, a[i]));
		}
		else
		{
			auto low = lower_bound(v.begin(), v.end(), make_pair(0, a[i]),compare);
			low->first = i;
			low->second = a[i];
			int idx = low - v.begin() - 1;
			p[i] = v[idx].first;
		}
	}
	int len = v.size() - 1;
	int ptr = v.back().first;
	stack<int> st;
	for (int i = 0; i < len; i++)
	{
		st.push(a[ptr]);
		ptr = p[ptr];
	}

	printf("%d\n", len);
	while (!st.empty())
	{
		printf("%d ", st.top());
		st.pop();
	}

	return 0;
}