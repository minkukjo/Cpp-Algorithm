//
// Created by 조민국 on 2019-01-29.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Map[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int v_size = puddles.size();
    int row = 0;
    int col = 0;
    if(puddles.size() != 0)
    {
        for(int i=0; i<v_size; i++)
        {
            row = puddles[i][0];
            col = puddles[i][1];
            Map[col][row] = -1;
        }
    }


    Map[1][1] = 1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(i == 1 && j == 1)
            {
                continue;
            }
            if(Map[i][j] == -1)
            {
                Map[i][j] = 0;
                continue;
            }
            Map[i][j] = ( Map[i][j-1] + Map[i-1][j] ) % 1000000007;
        }
    }

    answer = Map[n][m] ;

    cout << answer << endl;


    return answer;
}

int main()
{
    int m = 4;
    int n = 3;
    vector<vector<int>> puddles = { { 2,2 }};

    solution(m,n,puddles);
    return 0;
}