//
// Created by 조민국 on 2019-03-31.
//

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[11][11];
int visit[11][11][11][11];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

class ball
{
public:
    int r_x;
    int r_y;
    int b_x;
    int b_y;
    ball(int a,int b,int c, int d):r_x(a),r_y(b),b_x(c),b_y(d){};
};

queue<ball> q;

int bfs()
{
    int time = 10;
    while(time--)
    {
        int size = q.size();

        for(int i=0; i<size; i++)
        {
            int r_x = q.front().r_x;
            int r_y = q.front().r_y;
            int b_x = q.front().b_x;
            int b_y = q.front().b_y;
            q.pop();


            for(int i=0; i<4; i++)
            {
                bool red_goal = false;
                bool blue_goal = false;

                int r_nx = r_x;
                int r_ny = r_y;
                int r = 0;

                int b_nx = b_x;
                int b_ny = b_y;
                int b = 0;

                while(true)
                {
                    int temp_b_nx = b_nx + dx[i];
                    int temp_b_ny = b_ny + dy[i];
                    if(map[temp_b_nx][temp_b_ny] == 2)
                    {
                        blue_goal = true;
                        break;
                    }

                    if(map[temp_b_nx][temp_b_ny] == 0 )
                    {
                        break;
                    }
                    b_nx = temp_b_nx;
                    b_ny = temp_b_ny;
                    b++;
                }

                // 파란 공이 드갔다면 다시
                if(blue_goal)
                {
                    continue;
                }

                while(true)
                {
                    int temp_r_nx = r_nx + dx[i];
                    int temp_r_ny = r_ny + dy[i];
                    if(map[temp_r_nx][temp_r_ny] == 2)
                    {
                        red_goal = true;
                        break;
                    }

                    if(map[temp_r_nx][temp_r_ny] == 0 )
                    {
                        break;
                    }

                    r_nx = temp_r_nx;
                    r_ny = temp_r_ny;
                    r++;
                }

                if(red_goal)
                {
                    return 10-time;
                }

                if(r_nx == b_nx && r_ny == b_ny)
                {
                    if(r > b)
                    {
                        r_nx = r_nx - dx[i];
                        r_ny = r_ny - dy[i];

                    }
                    else
                    {
                        b_nx = b_nx - dx[i];
                        b_ny = b_ny - dy[i];
                    }
                }

                if(visit[r_nx][r_ny][b_nx][b_ny])
                {
                    continue;
                }
                visit[r_nx][r_ny][b_nx][b_ny] = 1;

                q.push(ball(r_nx,r_ny,b_nx,b_ny));

            }
        }
    }

    return -1;

}

int main()
{
    int N,M;
    char c;
    int rx,ry;
    int bx,by;

    memset(visit,false,sizeof(visit));
    // N 가로 M 세로
    cin >> N >> M;

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            cin >> c;
            // #: 0, . : 1, 0 : 2
            if(c == '.')
            {
                map[i][j] = 1;
            }
            else if(c == 'O')
            {
                map[i][j] = 2;
            }
            else if(c == 'R')
            {
                map[i][j] = 1;
                rx = i;
                ry = j;
            }
            else if(c == 'B')
            {
                map[i][j] = 1;
                bx = i;
                by = j;
            }
        }
    }

    visit[rx][ry][bx][by] = 1;

    q.push(ball(rx,ry,bx,by));



    cout << bfs() << endl;

    return 0;
}