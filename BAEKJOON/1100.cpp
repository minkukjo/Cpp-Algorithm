//
// Created by 조민국 on 2019-04-12.
//
#include <iostream>

using namespace std;

char map[9][9];
int ans;

int main()
{
    char c;

    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
        {
            cin >> map[i][j];
        }
    }

    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
        {
            if(i%2 == 1)
            {
                if(j%2 == 1 && map[i][j] == 'F')
                {
                    ans++;
                }
            }
            else if(i%2 == 0)
            {
                if(j%2 == 0 && map[i][j] == 'F')
                {
                    ans++;
                }
            }
        }
    }

    cout << ans;


    return 0;
}