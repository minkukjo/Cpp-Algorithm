#include <iostream>

using namespace std;

int main()
{
	int x1, y1, x2, y2, x3, y3;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	int temp = x1*y2 + x2*y3 + x3*y1;
	temp -= x1*y3 + x2*y1 + x3*y2;

	if (temp > 0) cout << 1 << endl;
	else if (temp == 0) cout << 0 << endl;
	else cout << -1 << endl;

	return 0;
}