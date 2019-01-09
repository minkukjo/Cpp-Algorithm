//
// Created by 조민국 on 09/01/2019.
//
// 나는 DP에 약한듯
// DP 연습을 좀 더 해야겠다.

#include <iostream>

using namespace std;


int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int N,M;
        cin >> N >> M;
        int dp[31][31] = {0};
        for(int i=1; i<=M; i++)
        {
            dp[1][i] = i;
        }

        for(int i=2; i<=N; i++)
        {
            for(int j=i; j<=M; j++)
            {
                for(int k=j; k>=i; k--)
                {
                    dp[i][j] += dp[i-1][k-1];
                }
            }
        }
        cout << dp[N][M] << endl;
    }
    return 0;
}