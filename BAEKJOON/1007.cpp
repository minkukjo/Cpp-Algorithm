//
// Created by 조민국 on 09/01/2019.
//

// DFS, 재귀 공부 더 필요
#include <iostream>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <algorithm>

using namespace std;

double ans;
int vec[21][2];
bool check[21];
int n;

void go(int cnt,int index)
{
    if(cnt == n/2)
    {
        double x = 0, y = 0;
        for(int i=0; i<n; i++)
        {
            if(check[i])
            {
                x -= vec[i][0];
                y -= vec[i][1];
            }
            else
            {
                x += vec[i][0];
                y += vec[i][1];
            }
        }
        ans = min(ans,sqrt(x*x + y*y));
        return;
    }
    if( index == n) return;

    go(cnt,index+1);
    check[index]=true;
    go(cnt+1,index+1);
    check[index]=false;
}

int main()
{
    int t;
    cin >>t;
    while(t--)
    {

        cin >> n;
        ans =  numeric_limits<double>::max();
        for(int i=0; i<n; i++)
        {
            int v1,v2;
            cin >> v1 >> v2;
            vec[i][0] = v1;
            vec[i][1] = v2;
        }

        go(0,0);
        printf("%.6lf\n",ans);
    }
    return 0;
}