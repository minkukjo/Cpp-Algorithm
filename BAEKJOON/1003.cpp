//
// Created by 조민국 on 27/12/2018.
//

#include <iostream>
#include <vector>
using namespace std;

int dp[2][41];

int fibonacci(int n)
{
    dp[0][0] = 1;
    dp[0][1] = 0;

    dp[1][0] = 0;
    dp[1][1] = 1;

//    if(n==0)
//    {
//        return 0;
//    }
//    if(n==1)
//    {
//        return 1;
//    }
//    else
//    {
//        return fibonacci(n-1) + fibonacci(n-2);
//    }

    for(int i=2; i<41; i++)
    {
        dp[0][i] = dp[0][i-1] + dp[0][i-2];
        dp[1][i] = dp[1][i-1] + dp[1][i-2];
    }
    cout << dp[0][n] << " " << dp[1][n] << endl;
}

int main() {
    int t;
    int n;
    //std::cout << "Hello, BackJoon!" << std::endl;
    cin >> t;

    for(int i=0; i!=t; i++)
    {
        cin >> n;
        fibonacci(n);
    }


    return 0;
}