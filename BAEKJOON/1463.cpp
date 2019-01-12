//
// Created by 조민국 on 12/01/2019.
//

// DP에 대한 심도깊은 공부가 절실하다.

#include <iostream>
#include <cmath>

using namespace std;

int memo[1000001];

int main()
{
    int X;
    cin >> X;

    memo[1] = 0;

    for(int i = 2; i<=X; i++)
    {
        // 1을 뺀다.
        memo[i] = memo[i-1]+ 1;
        if(i%2 == 0)
        {
            memo[i] = min(memo[i],memo[i/2] + 1);
        }
        if(i%3 == 0)
        {
            memo[i] = min(memo[i],memo[i/3] + 1);
        }
    }

    cout <<memo[X] << endl;


    return 0;
}