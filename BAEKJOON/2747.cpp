//
// Created by 조민국 on 2019-04-12.
//


#include <iostream>

using namespace std;

int DP[50];

int main()
{
    int n;
    cin >> n;
    DP[0] = 0;
    DP[1] = 1;

    for(int i=2; i<=n; i++)
    {
        DP[i] = DP[i-1] + DP[i-2];
    }

    cout << DP[n];


    return 0;
}