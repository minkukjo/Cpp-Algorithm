//
// Created by 조민국 on 2019-03-30.
//

// 단지 번호 붙이기

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int map[26][26];
bool visit[26][26];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<int> ans;
int counter=1;

void dfs(int x,int y)
{
    visit[x][y] = true;

    for(int i=0; i<4; i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx >= 0 && ny >= 0 && nx<N && ny <N && !visit[nx][ny] && map[nx][ny])
        {
            counter++;
            dfs(nx,ny);
        }
    }

}

int main()
{

    char temp;

    memset(visit,false,sizeof(visit));
    scanf("%d",&N);
    getchar();

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%c",&temp);
            map[i][j] = temp-'0';
        }
        getchar();
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(map[i][j] && !visit[i][j])
            {
                dfs(i,j);
                ans.push_back(counter);
                counter=1;
            }

        }
    }

    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());

    for(int i=0; i<ans.size(); i++)
    {
        printf("%d\n",ans[i]);
    }



    return 0;
}