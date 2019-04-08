//
// Created by 조민국 on 2019-04-08.
//

// 연구소

// 0 : 빈칸 , 1: 벽, 2: 바이러스
// 벽은 3개를 세울 수 있고 반드시 3개를 세워야함

#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

class virus{
public:
    int x;
    int y;
    virus(int a, int b):x(a),y(b){};
};

int ans;

int temp[9][9];
int map[9][9];
int N,M;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void print()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cout << map[i][j] << " ";
        }
        cout<<endl;
    }
}




void bfs()
{
    queue<virus> q;
    int count = 0;
    int virus_map[9][9];

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            virus_map[i][j] = temp[i][j];
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(temp[i][j] == 2)
            {
                q.push(virus(i,j));
            }
        }
    }


    while(!q.empty())
    {
        int size = q.size();

        for(int i=0; i<size; i++)
        {
            int x = q.front().x;
            int y = q.front().y;
            q.pop();

            for(int j=0; j<4; j++)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if(nx >= 0 && ny >= 0 && nx<N && ny < M && !virus_map[nx][ny])
                {
                    virus_map[nx][ny] = 2;
                    q.push(virus(nx,ny));
                }
            }

        }
    }




    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(!virus_map[i][j])
            {
                count++;
            }
        }
    }

    ans = max(count,ans);

}



void init()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            temp[i][j] = map[i][j];
        }
    }
}




void dfs(int n)
{

    if(n == 3)
    {
        bfs();
        return;
    }
    else
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(!temp[i][j])
                {
                    temp[i][j] = 1;
                    dfs(n+1);
                    temp[i][j] = 0;
                }
            }
        }
    }


}

int main()
{

    cin >> N>> M;


    for(int i=0; i<N;i++)
    {
        for(int j=0; j<M;j++)
        {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<N;i++)
    {
        for(int j=0; j<M;j++)
        {
            if(!map[i][j])
            {
                init();
                temp[i][j] = 1;
                dfs(1);
                temp[i][j] = 0;
            }
        }
    }



    cout << ans << endl;

    return 0;
}