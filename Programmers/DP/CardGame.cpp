//
// Created by 조민국 on 2019-01-30.
//

// 사쓰가 레벨 4 어렵

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

// 왼쪽이 i, 오른쪽이 j
int DP[2001][2001];

int solution(vector<int> left, vector<int> right) {
    int answer = 0;


    for(int i=1; i<=left.size()+1; i++)
    {
        DP[0][i] = -1;
    }

    for(int i=1; i<=left.size(); i++)
    {
        for(int j=1; j<=left.size(); j++)
        {
            DP[i][j] = max(DP[i-1][j-1],DP[i-1][j]);
            if(DP[i][j-1] != -1 && left[i-1] > right[j-1])
            {
                DP[i][j] = max(DP[i][j-1]+right[j-1],DP[i][j]);
            }
        }
    }
    answer = DP[left.size()][right.size()];




    return answer;
}

int main()
{
    vector<int> left = {3,2,5};
    vector<int> right = {2,4,1};

    solution(left,right);

    return 0;
}