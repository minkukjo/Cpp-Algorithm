//
// Created by 조민국 on 2019-04-01.
//

#include <iostream>
#include <cstring>
using namespace std;

char map[101][101];
char visit[101][101];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

char dfs(int x, int y,char c)
{
    visit[x][y] = c;

    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(map[x][y] == map[nx][ny] && visit[nx][ny] != c)
        {
            dfs(nx,ny,c);
        }
    }
    return c;
}

int main()
{
    int n;
    char c;
    int R=0;
    int G=0;
    int B=0;
    int N_R=0;
    int N_B=0;
    cin >> n;

    memset(visit,'D',sizeof(visit));

    getchar();

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%c",&map[i][j]);
        }
        getchar();
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(visit[i][j] != map[i][j])
            {
                c = dfs(i,j,map[i][j]);
                if(c == 'R')
                {
                    R++;
                }
                else if(c == 'G')
                {
                    G++;
                }
                else if(c == 'B')
                {
                    B++;
                }
            }
        }
    }

    memset(visit,'D',sizeof(visit));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(map[i][j] == 'G')
            {
                map[i][j] = 'R';
            }
        }
    }

//    for(int i=0; i<n; i++)
//    {
//        for(int j=0; j<n; j++)
//        {
//            cout << map[i][j];
//        }
//        cout << endl;
//    }


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(visit[i][j] != map[i][j])
            {
                c = dfs(i,j,map[i][j]);
                if(c == 'R')
                {
                    N_R++;
                }
                else if(c == 'B')
                {
                    N_B++;
                }
            }
        }
    }

    cout << R + G + B << " ";

    cout << N_R + N_B;

//    for(int i=0; i<n; i++)
//    {
//        for(int j=0; j<n; j++)
//        {
//            cout << visit[i][j];
//        }
//        cout << endl;
//    }





    return 0;
}