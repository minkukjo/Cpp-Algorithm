//
// Created by 조민국 on 2019-04-14.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class fish
{
public:
    int x;
    int y;
    int s;
    int t;
    int e;
    fish(int a,int b,int c,int d,int e):x(a),y(b),s(c),t(d),e(e){};
};

int map[21][21];
bool visit[21][21];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int N;
int ans;

queue<fish> q;
vector<fish> pos;

bool compare(fish a, fish b)
{
    if(a.s < b.s)
    {
        return true;
    }
    else if(a.s == b.s)
    {
        if(a.x < b.x)
        {
            return true;
        }
        else if(a.x == b.x)
        {
            if(a.y < b.y)
            {
                return true;
            }
        }
    }

    return false;

}

void bfs()
{
    int time = 0;
    int eat_count = 0;
    while(!q.empty())
    {
        int size = q.size();
        int x = q.front().x;
        int y = q.front().y;
        int s = q.front().s;
        int t = q.front().t;
        int e = q.front().e;
        q.pop();

        for(int i=0; i<size; i++)
        {
                for(int j=0; j<4; j++)
                {
                    int nx = x+ dx[j];
                    int ny = y+ dy[j];

                    if(nx>0 && ny>0 && nx<=N && ny<=N && s >= map[nx][ny] && !visit[nx][ny])
                    {
                        visit[nx][ny] = true;
                        q.push(fish(nx,ny,s,t+1,e));
                    }
                }

        }
    }
}



int main()
{


    for(int i=0; i<100; i++)
    {

        for(int j=0; j<100; j++)
        {
            cout << i << " " << j << endl;
        }
        cout << endl;
    }




    cin >> N;




    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin >> map[i][j];

            if(map[i][j] == 9)
            {
                q.push(fish(i,j,2,0,0));
                map[i][j] = 0;
                visit[i][j] = true;
            }


        }
    }

    sort(pos.begin(),pos.end(),compare);

    memset(visit,false,sizeof(visit));
    cout << q.size() << endl;

    bfs();

    cout << ans << endl;




    return 0;
}