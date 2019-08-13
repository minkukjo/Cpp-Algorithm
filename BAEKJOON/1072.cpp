#include <iostream>

using namespace std;

int main()
{
	long long X, Y;
	long long Z;
	scanf("%lld %lld", &X, &Y);

	Z = (Y * 100/ X);

	if (Z >= 99) { printf("-1"); return 0; }
	long long K = Z + 1;
	long long ans = (100 *Y - (Z*X)-X) / (Z-99);


	printf("%lld", ans);

	return 0;
}