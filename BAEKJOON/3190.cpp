//
// Created by 조민국 on 2019-04-01.
//

// 뱀대가리 뿌수기

#include <iostream>
#include <queue>
#include <cstring>

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
int ans = 0;

void print()
{
    cout << endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            printf("%d ",visit[i][j]);
        }
        cout << endl;
    }
}


void dfs(int x,int y, char dir,int time,unsigned int count)
{
    if(x>n || y>n || x<1 || y<1 || visit[x][y])
    {
        ans = time;
        return;
    }
    q.push(bam(x,y,dir));
    visit[x][y] = true;

    //print();

    if(map[x][y] == 1)
    {
        visit[x][y] = true;
        map[x][y] = 0;
    }
    else
    {
        int temp_x = q.front().x;
        int temp_y = q.front().y;
        visit[temp_x][temp_y] = false;
        q.pop();
    }

    //print();



    if(count <= d.size())
    {
        if(time == d[count].first)
        {
            if(dir == 'U' && d[count].second == 'L')
            {
                dir = 'L';
            }
            else if(dir == 'U' && d[count].second == 'D')
            {
                dir = 'R';
            }
            else if(dir == 'R' && d[count].second == 'L')
            {
                dir = 'U';
            }
            else if(dir == 'R' && d[count].second == 'D')
            {
                dir = 'D';
            }
            else if(dir == 'L' && d[count].second == 'L')
            {
                dir = 'D';
            }
            else if(dir == 'L' && d[count].second == 'D')
            {
                dir = 'U';
            }
            else if(dir == 'D' && d[count].second == 'L')
            {
                dir = 'R';
            }
            else if(dir == 'D' && d[count].second == 'D')
            {
                dir = 'L';
            }

            count++;
        }
    }



    if(dir == 'U')
    {
        dfs(x-1,y,dir,time+1,count);
    }
    else if(dir == 'L')
    {

        dfs(x,y-1,dir,time+1,count);
    }
    else if(dir == 'R')
    {

        dfs(x,y+1,dir,time+1,count);
    }
    else if(dir=='D')
    {
        dfs(x+1,y,dir,time+1,count);
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


    dfs(1,1,'R',0,0);

    cout << ans;



    return 0;
}