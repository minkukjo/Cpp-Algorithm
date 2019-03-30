//
// Created by 조민국 on 2019-03-30.
//

// Count Circle Groups

#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

class Map
{
public:
    int x;
    int y;
    int r;
    Map(int a,int b,int c):x(a),y(b),r(c){};
};

bool visit[5001];

void dfs(int n,vector<int> adj[])
{
    if(visit[n] == 1 )
    {
        return;
    }
    visit[n] = true;

    for(int i=0; i<adj[n].size(); i++)
    {
        dfs(adj[n][i],adj);
    }
}

void make()
{
    vector<int> adj[5001];

    vector<Map> map;
    int n;
    int x,y,r;
    int ans = 0;

    memset(visit,false,sizeof(visit));
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d",&x,&y,&r);
        map.push_back(Map(x,y,r));
    }


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=j)
            {
                if(pow(map[i].r+map[j].r,2) >= pow(map[i].x-map[j].x,2) + pow(map[i].y-map[j].y,2))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        if(!visit[i])
        {
            ans++;
            dfs(i,adj);
        }
    }

    printf("%d\n",ans);



}

int main()
{
    int t;

    scanf("%d",&t);

    while(t--)
    {
        make();
    }
    return 0;
}