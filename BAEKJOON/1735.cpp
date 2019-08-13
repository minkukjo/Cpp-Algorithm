#include <iostream>

using namespace std;


int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int Icm(int a, int b)
{
	return a*b / gcd(a, b);
}

int main()
{
	int N, M;
	int N2, M2;
	int iter = 1;
	int temp, temp2;
	int mother,child;
	scanf("%d %d", &N, &M);
	scanf("%d %d", &N2, &M2);

	mother = Icm(M, M2);
	N = N * (mother / M);
	N2 = N2 * (mother / M2);
	child = N + N2;

	if (gcd(mother, child) != 1)
	{
		int div = gcd(mother, child);
		mother = mother / div;
		child = child / div;
		printf("%d %d", child, mother);
	}
	else
	{
		printf("%d %d", child, mother);
	}
	

	return 0;
}