//
// Created by 조민국 on 2019-04-09.
//

// 경사로요맨

#include <iostream>
#include <cmath>
using namespace std;

int map[101][101];
int N;
int L;
int ans;

bool col_check(int x, int y)
{
    for(int i=0;)
}

bool col(int cur_col)
{
    for(int i=0; i<N-1; i++)
    {
        if( (abs(map[i][cur_col] - map[i+1][cur_col]) == 1) && map[i][cur_col] > map[i+1][cur_col] )
        {
            if(col_check(cur_col,i+1))
            {

            }
        }
    }
}

void solve()
{
    for(int i=0; i<N; i++)
    {
        ans += col(i);
    }
}

int main()
{

    int combo_count = 0;
    cin >> N >> L;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> map[i][j];
        }
    }


    return 0;
}