//
// Created by 조민국 on 2019-01-30.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

// max_element()의 발견

using namespace std;

int DP[105][100035];
int solution(int K, vector<vector<int>> travel) {
    int answer = 0;

    DP[0][travel[0][0]] = travel[0][1];
    DP[0][travel[0][2]] = travel[0][3];

    for(int i=1; i<travel.size(); i++)
    {
        for(int j=0; j<K; j++)
        {
            if(DP[i-1][j] != 0)
            {
                DP[i][j + travel[i][0]] = max(DP[i][j + travel[i][0]],DP[i-1][j]+travel[i][1]);
                DP[i][j + travel[i][2]] = max(DP[i][j + travel[i][2]],DP[i-1][j]+travel[i][3]);
            }
        }
    }

    answer = *max_element(DP[travel.size()-1],DP[travel.size()-1]+K+1);

    return answer;
}

int main()
{
    int K = 3000;
    vector<vector<int>> travel = {
            {1000,2000,300,700},
            {1100,1900,400,900},
            {900,1800,400,700},
            {1200,2300,500,1200}
    };

//    int K = 1650;
//    vector<vector<int>> travel = {
//            {500,200,200,100},
//            {800,370,300,120},
//            {700,250,300,90}
//    };
    solution(K,travel);
}