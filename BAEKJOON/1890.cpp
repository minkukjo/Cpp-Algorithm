//
// Created by 조민국 on 2019-03-30.
//

#include <iostream>
#include <cstring>

using namespace std;

//class direction
//{
//public:
//    int x;
//    int y;
//    direction(int c, int d):x(c),y(d){};
//};
//
//int map[101][101];
//int ans = 0;
//
//void bfs(int x, int y,int n)
//{
//    queue<direction> q;
//
//    q.push(direction(x,y));
//
//    while(!q.empty())
//    {
//        int size = q.size();
//
//
//        for(int i=0; i<q.size(); i++)
//        {
//            x = q.front().x;
//            y = q.front().y;
////            bool r = q.front().r;
////            bool d = q.front().d;
//            int power = map[x][y];
//            q.pop();
//
//            if(map[x][y] == 0)
//            {
//                ans++;
//                continue;
//            }
//
//            if(x+power < n) // right가 false라면
//            {
//                q.push(direction(x+power,y));
//            }
//
//            if(y + power < n) // down이 false라면
//            {
//                q.push(direction(x,y+power));
//            }
//
//        }
//    }
//
//}

long long map[101][101];
long long DP[101][101];
long long ans=0;

//void dp(long long x,long long y,long long n)
//{
//    if(x == n-1 && y== n-1)
//    {
//        ans++;
//        return;
//    }
//
//    if(x<0 || y<0 || x >= n || y >= n)
//    {
//        return;
//    }
//
//    if(visit[x][y] || !map[x][y])
//    {
//        return;
//    }
//    visit[x][y] = true;
//
//    if(x + map[x][y] < n )
//    {
//
//        dp(x+map[x][y],y,n);
//    }
//
//    if(y + map[x][y] < n )
//    {
//        dp(x,y+map[x][y],n);
//    }
//}

int main()
{
    long long n;
    long long temp;

    scanf("%lld",&n);

    for(long long i=0; i<n; i++)
    {
        for(long long j=0; j<n; j++)
        {
            scanf("%lld",&temp);
            map[i][j] = temp;
        }
    }

//  bfs(0,0,n);


//    dp(0,0,n);

    DP[0][0] = 1;

    for(long long i=0; i<n; i++)
    {
        for(long long j=0; j<n; j++)
        {
            if(!map[i][j])
            {
                continue;
            }

            if(i+map[i][j] < n)
            {
                DP[i+map[i][j]][j] += DP[i][j];
            }
            if(j + map[i][j] < n)
            {
                DP[i][j+map[i][j]] += DP[i][j];
            }
        }
    }



    cout<< DP[n-1][n-1] <<endl;



    return 0;
}