//
// Created by 조민국 on 2019-03-28.
//

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int arr[101][101];
bool visit[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int N,M;
int ans = 9999999;

class route
{
public:
    int x;
    int y;
    int walk;
    route(int a,int b, int c):x(a),y(b),walk(c){};
};


void bfs(int x, int y)
{
    queue<route> q;

    q.push(route(x,y,1));
    visit[x][y] = 1;

    while(!q.empty())
    {
        int size = q.size();

        for(int i=0; i<size; i++)
        {
            int x = q.front().x;
            int y = q.front().y;
            int now_walk = q.front().walk;

            q.pop();

            if(x == N-1 && y == M-1 && now_walk<ans)
            {
                ans = now_walk;
            }

            for(int j=0; j<4; j++)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if(nx >=0 && ny >=0 && nx<N && ny<M && visit[nx][ny] != 1 && arr[nx][ny] != 0)
                {
                    visit[nx][ny] = 1;
                    q.push(route(nx,ny,now_walk+1));
                }
            }

        }
    }
}



int main()
{

    char c;
    memset(visit, false,sizeof(visit));

    scanf("%d %d",&N,&M);

    getchar();

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            scanf("%c",&c);
            arr[i][j] = c - '0';
        }
        getchar();
    }

//    for(int i=0; i<N; i++)
//    {
//        for(int j=0; j<M; j++)
//        {
//            printf("%d ",arr[i][j]);
//        }
//        printf("\n");
//    }

    bfs(0,0);

    printf("%d",ans);





    return 0;
}