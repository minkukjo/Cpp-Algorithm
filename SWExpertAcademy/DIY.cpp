//
// Created by 조민국 on 2019-03-19.
//


#include <iostream>
#include <queue>

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int map[701][701];

using namespace std;

class cell
{
public:
    int x,y,life;
    // 생성자를 통해 값 넣음.
    cell(int a,int b,int c) : x(a),y(b),life(c){};
};

int bfs(int t)
{
    queue<cell> q[11];

    int N,M,K;
    cin >> N >> M >> K;

    // memset 안해주니까 틀렸음. 충격
    memset(map,0,sizeof(map));

    for(int i=350; i<350+N; i++)
    {
        for(int j=350; j<350+M; j++)
        {
            cin >> map[i][j];

            // 세포값에 *2를 하는 이유는 세포가 활성화되고 나서 죽는 시간이 *2시간이기 때문
            // 0인 값들은 큐에넣지않음.
            if(map[i][j])
            {
                q[map[i][j]].push(cell(i,j,map[i][j]*2));
            }

        }
    }

    while(K--)
    {
        // 큐의 크기는 10이기 때문에 큐의 크기를 줄여가며 계산
        for(int i=10; i>=1; i--)
        {
            int size = (int)q[i].size();

            for(int j=0; j<size; j++)
            {
                int x = q[i].front().x;
                int y = q[i].front().y;
                int life = q[i].front().life;
                q[i].pop();

                life--;


                // 활성화 여부를 확인함
                // i가 5라고 가정하면 map[x][y]는 5고, life는 10이므로 life는 5초간 비활성 상태.
                // 그러다가 5보다 작아지는 시점이 바로 활성화 상태.
                if(map[x][y] > life)
                {
                    for(int k=0; k<4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        // 현재 보고 있는 곳에 번식이 가능하다면
                        if(map[nx][ny] == 0)
                        {
                            map[nx][ny] = map[x][y];
                            q[i].push(cell(nx,ny,map[nx][ny]*2));
                        }
                    }
                }


                // 생명력이 0보다 작은 애들은 넣지않음
                // 죽지 않은 세포들만 다시 큐에 넣어줌으로써
                // 결과적으로 마지막에 큐에 생존한 세포들의 수만 더해서 답을 찾음.
                if(life > 0)
                {
                    q[i].push(cell(x,y,life));
                }

            }

        }
    }

    int ans = 0;

    // 큐에 남아있는 세포들의 개수를 다 더해줌
    // 큐에는 살아있는(활성,비활성)세포들만 남아있을거기 때문에
    for(int i=1; i<11; i++)
    {
        ans += q[i].size();
    }

    cout << "#" << t << " " << ans << endl;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>> T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        // 큰놈부터 번식시키기 위해 queue를 이용함

        bfs(test_case);


    }
    return 0;
}