//
// Created by 조민국 on 2019-01-14.
//

// dp로 안풀 수 있지만 dp인 문제.

#include <iostream>

using namespace std;



int main()
{

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        int dp[11];
        cin >> n;

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        for(int i=4; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        cout<<dp[n] << endl;
    }



    return 0;
}