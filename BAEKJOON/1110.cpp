//
// Created by 조민국 on 2019-01-17.
//

#include <iostream>

using namespace std;

int main()
{
    int N;
    int ans;
    int count=0;
    cin >> N;
    ans = N;


    while(true)
    {
        int nl,nr,sum;
        nl = N/10;
        nr = N%10;
        sum = nl+nr;
        if(sum <10)
        {
            N = nr*10 + sum;
        } else
        {
            N = nr*10 + sum%10;
        }
        count++;


        if(N == ans)
        {
            break;
        }

    }

    cout << count << endl;
    return 0;
}