//
// Created by 조민국 on 09/01/2019.
//

#include <iostream>

using namespace std;

// 동서남북
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int filed[51][51];
bool check[51][51];
int M,N,K;
int total;

void dfs(int x,int y)
{
    check[x][y] = true;
    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0<=nx && nx<N && 0<=ny && ny<M)
        {
            if(filed[nx][ny] && !check[nx][ny])
            {
                check[nx][ny] = true;
                dfs(nx,ny);
            }
        }
    }
}



int main()
{
    int t;
    cin >> t;
    while(t--)
    {

        cin >> M >> N >> K;
        total = 0;
        for(int i=0; i<51; i++)
        {
            for(int j=0; j<51; j++)
            {
                filed[i][j] = 0;
                check[i][j] = false;
            }
        }

        for(int i=0; i<K; i++)
        {
            int x,y;
            cin >> x >> y;
            filed[y][x]= 1;
        }


        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(filed[i][j] && !check[i][j])
                {
                    dfs(i,j);
                    total++;
                }
            }
        }


        cout<<total<<endl;

    }
    return 0;
}