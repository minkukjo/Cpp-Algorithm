#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int n,l,r;
int ans;
int map[51][51];

bool chk = true;
int sum;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

queue<pair<int,int>> q;
queue<pair<int,int>> pos;

void bfs()
{


    while(chk)
    {
        bool visit[51][51]={};
        chk = false;
        ans+=1;

        for(int i=0;i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(visit[i][j]) continue;
                sum = map[i][j];
                q.push(make_pair(i,j));
                pos.push(make_pair(i,j));
                visit[i][j] = true;

                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visit[nx][ny] &&
                            abs(map[x][y] - map[nx][ny]) >= l && abs(map[x][y] - map[nx][ny]) <= r) {
                            chk = true;
                            q.push(make_pair(nx, ny));
                            pos.push(make_pair(nx, ny));
                            sum += map[nx][ny];
                            visit[nx][ny] = true;

                        }

                    }
                }

                int avg = sum/pos.size();

                while(!pos.empty())
                {
                    map[pos.front().first][pos.front().second] = avg;
                    pos.pop();
                }
            }
        }




    }
}

int main()
{

    cin >> n>> l >> r;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> map[i][j];
        }
    }

    bfs();

    cout << ans-1;
    return 0;
}