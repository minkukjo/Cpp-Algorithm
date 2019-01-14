//
// Created by 조민국 on 2019-01-14.
//

// 또 DP에서 깨짐 좀 더 공부해봐야함 분석

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int dp[301][3];

int main()
{
    int n;
    cin >> n;
    vector<int> stair;
    int score = 0;
    stair.push_back(0);
    for(int i=1; i<=n; i++)
    {
        cin>>score;
        stair.push_back(score);
    }

    dp[1][1] = stair[1];
    dp[1][2] = stair[1];
    for(int i=2; i<=n; i++)
    {
        dp[i][1] = dp[i-1][2] + stair[i];
        dp[i][2] = max(dp[i-2][1],dp[i-2][2]) + stair[i];
    }

    cout << max(dp[n][1],dp[n][2]);




    return 0;
}