//
// Created by 조민국 on 2019-03-19.
//


#include<iostream>
#include <cstring>

using namespace std;
int map[9][9] ={0,};

int dx[8] = { 0,0,1,-1,1,1,-1,-1};
int dy[8] = { 1,-1,0,0,1,-1,1,-1};
int n,m;

void othello(int x, int y)
{
    for(int i=0; i<8; i++)
    {
        int color = map[x][y];
        int nx = x + dx[i];
        int ny = y + dy[i];
        bool combo = false;

        while(nx >= 0 && ny >= 0 && nx <= n && ny <= n && map[nx][ny] != 0)
        {
            if(map[nx][ny] == color)
            {
                combo = true;
                break;
            }
            nx += dx[i];
            ny += dy[i];
        }

        while(combo)
        {
            if(nx == x && ny == y)
            {
                break;
            }
            map[nx][ny] = color;
            nx -= dx[i];
            ny -= dy[i];
        }


    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        memset(map,0,sizeof(map));
        int b=0,w=0;
        cin >> n >> m;

        map[n/2][n/2] = 2;
        map[n/2+1][n/2+1]= 2;
        map[n/2+1][n/2] = 1;
        map[n/2][n/2+1] =1;

        for(int i=0; i<m; i++)
        {
            int x,y,color;
            cin >> x >> y>> color;
            map[x][y] = color;
            othello(x,y);
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(map[i][j] == 1 )
                {
                    b++;
                }
                else if(map[i][j] == 2)
                {
                    w++;
                }
            }
        }

        cout << "#" << test_case << " " << b << " " << w << endl;

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}