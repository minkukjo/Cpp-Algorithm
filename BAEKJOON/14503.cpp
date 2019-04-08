//
// Created by 조민국 on 2019-04-08.
//

// 로봇 청소기

#include <iostream>


using namespace std;



int dx[4] = {-1,0,1,0}; // 북 서 남 동
int dy[4] = {0,-1,0,1};

int ans;
int copy_map[51][51];
int map[51][51];
int N,M;

int n = 2;

void print()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            printf("%2d ",map[i][j]-1);
        }
        cout << endl;
    }
    cout << endl;
}

void compare()
{
    for(int i=0;i <N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(!copy_map[i][j] && map[i][j] > 1)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
}

void dfs(int x,int y, int r)
{
    if(!map[x][y])
    {
        map[x][y] = n++;
    }
    //print();


    for(int i=1; i<=4; i++)
    {
        int nx = x + dx[(r+i)%4];
        int ny = y + dy[(r+i)%4];

        if(nx >=0 && ny >=0 && nx<N && ny < M && !map[nx][ny])
        {
            dfs(nx, ny, (r + i) % 4);
        }
    }

        int xx = x + dx[(r+2)%4];
        int yy = y + dy[(r+2)%4];

        if(map[xx][yy] == 1)
        {
            compare();
            exit(0);
        }
        else if(map[xx][yy] > 1 )
        {
            dfs(xx,yy,r);
        }




}

int main()
{


    cin >> N >> M;

    int x,y,r;
    cin >>x >> y>> r;

    if(r == 3)
    {
        r = 1;
    }
    else if(r == 1)
    {
        r = 3;
    }

    for(int i=0;i <N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> map[i][j];
        }
    }

    for(int i=0;i <N; i++)
    {
        for(int j=0; j<M; j++)
        {
            copy_map[i][j] = map[i][j];
        }
    }

    dfs(x,y,r);





    return 0;
}