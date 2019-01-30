//
// Created by 조민국 on 2019-01-28.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


int DP[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int temp = 0;
    int compare = 0;
    int old_left = 0;
    DP[0][0] = triangle[0][0];
    DP[1][0] += DP[0][0] + triangle[1][0];
    DP[1][1] += DP[0][0] + triangle[1][1];


    for(int i=2; i<triangle.size(); i++)
    {
        for(int j=0; j<triangle[i-1].size(); j++)
        {
            DP[i][j] = max(old_left,DP[i-1][j] + triangle[i][j]);
            DP[i][j+1] += DP[i-1][j] + triangle[i][j+1];
            old_left = DP[i][j+1];
            compare = max(DP[i][j], DP[i][j+1]);
            temp = max(compare,temp);
        }
    }

    for(int i=0; i<triangle.size(); i++)
    {
        answer = max(answer,DP[triangle.size()-1][i]);
    }

    cout << answer << endl;


    return answer;
}

int main()
{
    vector<vector<int>> triangle = {
            {7},
            {3,8},
            {8,1,0},
            {2,7,4,4},
            {4,5,2,6,5}
    };

    solution(triangle);

    return 0;
}