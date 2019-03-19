//
// Created by 조민국 on 2019-03-19.
//


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int map[54][54];
int N,M;
// R = N-i-j;
int change(int W, int B,int R)
{
    int count = 0;
    for(int i=1; i<=W; i++)
    {
        for(int j=1; j<=M; j++)
        {
            if(map[i][j] != 1)
            {
                count++;
            }
        }
    }

    for(int i=1; i<=B; i++)
    {
        for(int j=1; j<=M; j++)
        {
            if(map[i+W][j] != 2)
            {
                count++;
            }
        }
    }

    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=M; j++)
        {
            if(map[i+W+B][j] != 3)
            {
                count++;
            }
        }
    }

    return count;

}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int temp = 99999;
        int ans = 99999;
        cin >> N >> M;

        memset(map,0,sizeof(map));

        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=M; j++)
            {
                char c;
                cin >> c;

                // W => 1 B => 2 R => 3
                if(c == 'W')
                {
                    map[i][j] = 1;
                }
                else if(c=='B')
                {
                    map[i][j]  = 2;
                }
                else
                {
                    map[i][j]  = 3;
                }
            }
        }


        for(int i =1; i<=N-2; i++) // W
        {
            for(int j=1; j<=N-2; j++) // B
            {
                if(i+j >= N)
                {
                    break;
                }
                temp = change(i,j,N-i-j);
                ans = min(temp,ans);
            }
        }

        cout << "#" << test_case << " " << ans << endl;




    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}


