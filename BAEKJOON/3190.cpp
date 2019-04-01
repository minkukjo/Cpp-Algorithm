//
// Created by 조민국 on 2019-04-01.
//

// 뱀대가리 뿌수기

#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
bool visit[101][101];

class bam
{
public:
    int x;
    int y;
    char dir;
    bam(int a, int b, char c):x(a),y(b),dir(c){};
};

int n;
// 뱀의 몸체를 저장할 큐
queue<bam> q;
// 시간과 방향 저장
vector<pair<int,char>> d;

void bfs()
{
    int time = 1;
    int turn_count = 0;

    while(!q.empty())
    {
        int size = q.size();

        for(int i=0; i<size; i++)
        {
            int x = q.front().x;
            int y = q.front().y;
            char dir = q.front().dir;
            visit[x][y] = true;
            q.pop();

            if(i==0 && d[turn_count].first == time)
            {
                dir = d[turn_count++].second;
            }

            if(dir == 'R')
            {
                // 뱀이 벽에 대가리를 박거나, 자기 몸을 밟을 경우 에러표시
                if(x+1 > n && visit[x+1][y])
                {
                    return;
                }

                // 이동시 꼬리를 비워줘야함.
                if(map[x+1][y] == 1)
                {
                    q.push(bam(x,y,dir));
                }


                visit[x][y] = false;
                visit[x+1][y] = true;
                q.push(bam(x+1,y,dir));
            }
            else if(dir=='L')
            {

            }
            else if(dir =='U')
            {

            }
            else if(dir == 'D')
            {
                // 뱀이 벽에 대가리를 박거나, 자기 몸을 밟을 경우 에러표시
                if(y+1 > n && visit[x][y+1])
                {
                    return;
                }

                // 이동시 꼬리를 비워줘야함.
                if(map[x][y+1] == 1)
                {
                    q.push(bam(x,y,dir));
                }
                else
                {
                    while(!q.empty())
                    {
                        int t_size = q.size();

                        char h_dir = dir;

                        for(int i=0; i<t_size; i++)
                        {
                            int t_x = q.front().x;
                            int t_y = q.front().y;
                            char t_dir = h_dir;
                            h_dir = q.front().dir;
                            q.pop();
                        }

                    }
                }

                visit[x][y] = false;
                visit[x][y+1] = true;
                q.push(bam(x,y+1,dir));
            }

        }

        time++;
    }
}

int main()
{

    int apple;
    int dir;
    int time;
    char b_dir;
    cin >> n;
    cin >> apple;

    memset(map,-1,sizeof(map));
    memset(visit,false,sizeof(visit));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            map[i][j] = 0;
        }
    }

    for(int i=1; i<=apple; i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        map[x][y] = 1;
    }

    q.push(bam(1,1,'R'));

    cin >> dir;

    for(int i=0; i<dir; i++)
    {
        cin >> time >> b_dir;
        d.push_back(make_pair(time,b_dir));
    }





    return 0;
}