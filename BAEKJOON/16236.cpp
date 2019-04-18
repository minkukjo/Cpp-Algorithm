#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class fish
{
public:
    int x;
    int y;
    int t; // 시간
    int s; // 몸집
    int e; // 얼마나 먹었는지
    fish(int a,int b,int c, int d, int e):x(a),y(b),t(c),s(d),e(e){};
};

queue<fish> q;
vector<fish> v;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool visit[21][21];
int ans;
int N;
int map[21][21];

bool compare(fish a , fish b)
{
    if(a.t <= b.t)
    {
        if(a.t == b.t)
        {
            if(a.x <= b.x)
            {
                if(a.x == b.x)
                {
                    if(a.y < b.y)
                    {
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}
void bfs()
{

    while(1)
    {
        v.clear();
        memset(visit,false,sizeof(visit));
        visit[q.front().x][q.front().y] = 1;

        while(!q.empty())
        {
            int x = q.front().x;
            int y = q.front().y;
            int t = q.front().t;
            int s = q.front().s;
            int e = q.front().e;
            q.pop();

            for(int i=0; i<4 ;i++)
            {
                int nx = x+dx[i];
                int ny = y +dy[i];
                if(nx>=0 && ny >=0 && nx<N && ny< N)
                {
                    if(!visit[nx][ny])
                    {
                        if(map[nx][ny] == 0 || map[nx][ny] == s)
                        {
                            visit[nx][ny] = 1;
                            q.push(fish(nx,ny,t+1,s,e));
                        }
                        else if(map[nx][ny] < s)
                        {
                            visit[nx][ny] = 1;
                            v.push_back(fish(nx,ny,t+1,s,e+1));
                        }
                    }

                }
            }
        }

        if(v.size() == 0)
        {
            return;
        }

        sort(v.begin(),v.end(),compare);
        if(v[0].s == v[0].e)
        {
            v[0].s ++;
            v[0].e = 0;
        }

        map[v[0].x][v[0].y] = 0;

        ans += v[0].t;

        q.push(fish(v[0].x,v[0].y,0,v[0].s,v[0].e));
    }
}

int main()
{

    cin >> N;


    for(int i= 0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 9)
            {
                q.push(fish(i,j,0,2,0));
                map[i][j] = 0;
            }
        }
    }


    bfs();

    cout << ans;

    return 0;
}