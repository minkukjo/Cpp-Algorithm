//
// Created by 조민국 on 2019-04-09.
//


// 스타트와 링크

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int map[21][21];
int N;
int ans = 999999;
bool visit[21];
bool visit_map[21][21];

int sum = 0;
int sum2 = 0;
void dfs(int cur,int n)
{

    if(n == N/2)
    {
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                if(i==j)
                {
                    continue;
                }
                if(i!=j&&visit[i]&&visit[j]&&!visit_map[i][j]&&!visit_map[j][i])
                {
                    visit_map[i][j] = true;
                    visit_map[j][i] = true;
                    sum += map[i][j] + map[j][i];
                }
            }
        }

        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                if(i==j)
                {
                    continue;
                }
                if(i!=j&&!visit[i]&&!visit[j]&&!visit_map[i][j]&&!visit_map[j][i])
                {
                    visit_map[i][j] = true;
                    visit_map[j][i] = true;
                    sum2 += map[i][j] + map[j][i];
                }
            }
        }

        memset(visit_map,false,sizeof(visit_map));

        ans = min(ans,abs(sum-sum2));
        sum = 0;
        sum2 = 0;
        return;
    }

    for(int i=cur+1; i<=N; i++)
    {
        if(!visit[i])
        {
            visit[i] = true;
            dfs(i,n+1);
            visit[i] = false;
        }
    }
}

void print()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cout<< map[i][j] <<" ";
        }
        cout << endl;
    }
}

int main()
{

    cin >> N;


    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin >> map[i][j];
        }
    }

    //print();


    dfs(0,0);

    cout << ans << endl;


    return 0;
}