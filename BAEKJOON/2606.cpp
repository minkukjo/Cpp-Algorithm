//
// Created by 조민국 on 2019-03-30.
//

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> comp[101];
bool visit[101];
int ans;

void dfs(int n)
{
    visit[n] = true;


    for(int i=0; i<comp[n].size(); i++)
    {
        if(!visit[comp[n][i]])
        {
            ans++;
            dfs(comp[n][i]);
        }
    }



}

int main()
{
    int m,n;
    int l1,l2;

    memset(visit,false,sizeof(false));

    scanf("%d",&m);

    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&l1,&l2);
        comp[l1].push_back(l2);
        comp[l2].push_back(l1);
    }



    dfs(1);

    printf("%d",ans);

    return 0;
}