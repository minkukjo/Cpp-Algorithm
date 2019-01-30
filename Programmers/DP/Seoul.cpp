//
// Created by 조민국 on 2019-01-30.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int DP[105][100005];
int solution(int K, vector<vector<int>> travel) {
    int answer = 0;

    if(travel[0][0] <= K)
    {
        DP[0][travel[0][0]] = max(DP[0][travel[0][0]],travel[0][1]);
    }
    if(travel[0][2]<=K)
    {
        DP[0][travel[0][2]] = max(DP[0][travel[0][2]],travel[0][3]);
    }

    for(int i=0; i<travel.size()-1; i++)
    {
        for(int j=0; j<=K; j++)
        {
            if(DP[i][j] != 0)
            {
                int compare = j + travel[i+1][0];
                if(compare<=K)
                {
                    DP[i+1][compare] = max(DP[i+1][compare],DP[i][j]+travel[i+1][1]);
                    compare = j + travel[i+1][2];
                }

                if(compare<=K)
                {
                    DP[i+1][compare] = max(DP[i+1][compare],DP[i][j]+travel[i+1][3]);
                }
            }
        }
    }

    for(int i=0; i<=K; i++)
    {
        if(DP[travel.size()-1][i] > answer)
        {
            answer = DP[travel.size()-1][i];
        }
    }

    cout << answer << endl;


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
    solution(K,travel);
}