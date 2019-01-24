//
// Created by 조민국 on 2019-01-24.
//

#include <iostream>

using namespace std;

int main()
{
    long long N;
    int start = 0;
    int count = 0;
    int x = 1;
    int y = 1;
    cin >> N;

    while(true)
    {
        if(count >= N)
        {
            break;
        }
        start++;
        count += start;
    }

    if(start%2 == 0)
    {
        x = 1;
        y = start;
    }
    else
    {
        x = start;
        y = 1;
    }



    for(int i=count-start+1; i<=count; i++)
    {
        if(i == N)
        {
            break;
        }

        if(start%2 == 0)
        {
            x++;
            y--;
        }
        else
        {
            x--;
            y++;
        }

    }

    cout << x << "/" << y << endl;


    return 0;
}