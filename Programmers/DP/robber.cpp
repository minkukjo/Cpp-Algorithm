//
// Created by 조민국 on 2019-02-07.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> arr;

// 첫집을 턴 경우
int First_DP[1000001];
// 첫집을 안턴 경우
int Second_DP[1000001];

int solution(vector<int> money) {
    int answer = 0;

    First_DP[0] = money[0];
    First_DP[1] = money[0];

    Second_DP[0] = 0;
    Second_DP[1] = money[1];

    for(int i=2; i<money.size(); i++)
    {
        First_DP[i] = max(First_DP[i-1],First_DP[i-2]+money[i]);
        Second_DP[i] = max(Second_DP[i-1],Second_DP[i-2]+money[i]);
    }

    answer = max(First_DP[money.size()-2],Second_DP[money.size()-1]);




    return answer;
}

int main()
{
    vector<int> money = {1,2,3,1};
    solution(money);

    return 0;
}