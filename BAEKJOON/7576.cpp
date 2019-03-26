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
    int value;
    tomato(int a, int b, int c):x(a),y(b),value(c){};
};

queue<tomato> q;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int box[1001][1001];


void bfs(int M,int N, int block,int count)
{
    int days = 0;

    while(1)
    {
        int size = q.size();

        if(size == 0 && M*N-block > count)
        {
            cout << "-1" << endl;
            return;
        }
        else if(size == 0 && M*N-block == count)
        {
            cout << days << endl;
            return;
        }

//        cout<< endl;
//        cout<< endl;
//
//        for(int i=1; i<=M; i++)
//        {
//            for(int j=1; j<=N; j++)
//            {
//                cout << box[i][j] << " ";
//            }
//            cout<< endl;
//        }

        for(int i=0; i<size; i++)
        {
            int x = q.front().x;
            int y = q.front().y;
            int value = q.front().value;
            q.pop();


            for(int j=0; j<4; j++)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if(nx >0 && ny > 0 && nx<=M && ny <=N && box[nx][ny] == 0 )
                {
                    box[nx][ny] = 1;
                    q.push(tomato(nx,ny,1));
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
    int M,N,blank=0,block=0,count=0;

    // M이 행 N이 열
    cin >> N >> M;

    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin >> box[i][j];
            if(box[i][j] == 1)
            {
                q.push(tomato(i,j,box[i][j]));
                count++;
            }
            else if(box[i][j] == 0)
            {
                blank++;
            }
            else
            {
                block++;
            }
        }
    }

//    for(int i=1; i<=M; i++)
//    {
//        for(int j=1; j<=N; j++)
//        {
//            cout << box[i][j] << " ";
//        }
//        cout<< endl;
//    }


    bfs(M,N,block,count);







    return 0;
}