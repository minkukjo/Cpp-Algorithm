//
// Created by 조민국 on 2019-04-16.
//

#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int dx[8] = {-1,0,1, 1, 0,-1,1,-1};
int dy[8] = { 1,1,1,-1,-1,-1,0, 0};

class wood
{
public:
    int x;
    int y;
    int age;
    wood(int a,int b, int c):x(a),y(b),age(c){};
};

struct compare
{
    bool operator()(wood a, wood b)
    {
        return a.age > b.age;
    }
};


priority_queue<wood,vector<wood>,compare> pq;

queue<wood> q;
vector<wood> die;


int N,M,K;

int S2D2[11][11];
int map[11][11];
int ans;


void bfs()
{
    int year = 0;
    while(year < K)
    {
        int size = pq.size();

        // 봄
        for(int i=0; i<size; i++)
        {
            int x = pq.top().x;
            int y = pq.top().y;
            int age = pq.top().age;


            pq.pop();

            // 나이만큼 양분을 먹을 수 있는 경우
            if(map[x][y] >= age)
            {
                map[x][y] -= age;
                q.push(wood(x,y,age+1));
            }
            // 나이보다 양분이 적어서 못먹는 경우, 나무 죽음 죽은 나무 수거해놓음 일단
            else if(map[x][y] < age)
            {
                die.push_back(wood(x,y,age));
            }
        }

        // 여름

        int d_size = die.size();

        for(int i=0; i<d_size; i++)
        {
            int x = die.back().x;
            int y = die.back().y;
            int age = die.back().age;

            map[x][y] += age/2;

            die.pop_back();
        }


        size = q.size();



        // 가을 시작
        for(int i=0; i<size; i++)
        {
            int x = q.front().x;
            int y = q.front().y;
            int age = q.front().age;
            q.pop();
            pq.push(wood(x,y,age));

            if(age % 5 == 0)
            {
                for(int j=0; j<8; j++)
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];

                    if(nx > 0 && ny > 0 && ny<=N && nx<=N)
                    {
                        pq.push(wood(nx,ny,1));
                    }
                }
            }
        }

        // 겨울 양분 추가
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                map[i][j] += S2D2[i][j];
            }
        }

        year++;

    }


    ans = pq.size();

}



int main()
{
    cin >> N >> M >> K;

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin >> S2D2[i][j];
        }
    }

    for(int i=0; i<M; i++)
    {
        int x,y,age;
        cin >> x >> y >> age;
        pq.push(wood(x,y,age));
    }

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            map[i][j] = 5;
        }
    }


    bfs();

    cout << ans;



    return 0;
}