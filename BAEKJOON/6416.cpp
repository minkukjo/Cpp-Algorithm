#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main()
{
	int u, v;
	int count = 1;
	bool flag = false;
	
	while (true)
	{
		s.clear();
		int temp = 0;
		while(true)
		{	
			scanf("%d %d", &u, &v);
			if (u == 0 && v == 0)
			{
				break;
			}
			if (u == -1 && v == -1) 
			{
				flag = true;
				break;
			}
			s.insert(v), s.insert(u);
			temp++;
		}

		if (flag) break;

		if (temp == 0 || (int)s.size() == temp +1)
		{
			printf("Case %d is a tree.\n", count);
		}
		else
		{
			printf("Case %d is not a tree.\n", count);
		}
		count++;

	}
	return 0;
}