//
// Created by 조민국 on 2019-04-12.
//


#include <iostream>

using namespace std;

long long facto(long long n)
{
    if(n>1)
    {
        return n*facto(n-1);
    }
    else
    {
        return 1;
    }
}

int main()
{
    long long a;
    cin >> a;



    cout << facto(a);

    return 0;
}