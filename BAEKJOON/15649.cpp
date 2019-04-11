//
// Created by 조민국 on 2019-04-11.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;



int N,M;
bool visit[11];
vector<int> v;

void print(vector<int> v)
{
    for(int i=0; i<v.size(); i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");
}


void dfs(int n,vector<int> v)
{

    if(n == M)
    {
        print(v);
        return;
    }


    for(int i=1; i<=N; i++)
    {
        if(visit[i])
        {
            continue;
        }
        visit[i] = true;
        v.push_back(i);
        dfs(n+1,v);
        v.pop_back();
        visit[i] = false;
    }
}

int main()
{
    bool visit[11];
    memset(visit,false,sizeof(visit));

    scanf("%d %d",&N,&M);


    dfs(0,v);


    return 0;
}