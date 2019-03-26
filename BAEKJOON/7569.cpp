//
// Created by 조민국 on 2019-03-26.
//

#include <iostream>
#include <queue>

using namespace std;

class tomato
{
public:
    int x;
    int y;
    int h; // 몇층인지
    int value; // 값
    tomato(int a, int b, int c, int d):x(a),y(b),h(c),value(d){};
};

int box[101][101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

queue<tomato> q;

void bfs(int M,int N, int H, int count, int block)
{
    int days = 0;

    while(1)
    {
        int size = q.size();

        if(size == 0 && M*N*H-block > count)
        {
            cout << "-1"<<endl;
            return;
        }
        else if( size == 0 && M*N*H-block == count)
        {
            cout <<days<<endl;
            return;
        }


//        for(int k=1; k<=H; k++)
//        {
//            for(int i=1; i<=M; i++)
//            {
//                for(int j=1; j<=N; j++)
//                {
//                   cout << box[k][i][j] << " ";
//                }
//                cout << endl;
//            }
//            cout << endl;
//            cout << endl;
//            cout << endl;
//        }

        for(int i=0; i<size; i++)
        {
            int x = q.front().x;
            int y = q.front().y;
            int h = q.front().h;
            int value = q.front().value;
            q.pop();

            for(int j=0; j<4; j++)
            {
                int nx = x  +dx[j];
                int ny = y + dy[j];

                if(nx > 0 && ny > 0 && nx <= M && ny <= N && box[h][nx][ny] == 0 )
                {
                    box[h][nx][ny] = 1;
                    q.push(tomato(nx,ny,h,box[h][nx][ny]));
                    count++;
                }
            }

            if(h-1 > 0)
            {
                if(box[h-1][x][y] == 0)
                {
                    box[h-1][x][y] = 1;
                    q.push(tomato(x,y,h-1,box[h-1][x][y]));
                    count++;
                }


            }

            if(h+1 <= H)
            {
                if(box[h+1][x][y] == 0)
                {
                    box[h+1][x][y] = 1;
                    q.push(tomato(x,y,h+1,box[h+1][x][y]));
                    count++;
                }
            }

        }
        if(!q.empty())
        {
            days++;
        }
    }
}

int main()
{
    // M 가로칸, N 세로칸 , H 층
    int M,N,H,count = 0,blank=0,block=0;

    cin >> N >> M >> H;

    for(int k=1; k<=H; k++)
    {
        for(int i=1; i<=M; i++)
        {
            for(int j=1; j<=N; j++)
            {
                cin >> box[k][i][j];
                if(box[k][i][j] == 1)
                {
                    q.push(tomato(i,j,k,box[k][i][j]));
                    count++;
                }
                else if(box[k][i][j] == 0)
                {
                    blank++;
                }
                else
                {
                    block++;
                }
            }
        }
    }

    bfs(M,N,H,count,block);



    return 0;
}