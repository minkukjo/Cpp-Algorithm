//
// Created by 조민국 on 11/01/2019.
//

// 너무 어렵네 말도 안된다 진짜...

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long long ans;
long long min_n;
long long max_n;
bool isNo[1000001];

void isprime()
{
    for(long long i=2; i*i<=max_n; i++)
    {
        long long start = min_n / (i*i);
        if(i*i*start != min_n )
        {
            start++;
        }

        for(long long j=start; i*i*j<=max_n; j++)
        {
            isNo[i*i*j-min_n]= true;
        }
    }
}

int main()
{


    cin >> min_n >> max_n;



    isprime();

    for(int i=0; i<max_n-min_n +1; i++)
    {
        if(isNo[i] == false)
        {
            ans++;
        }
    }

    cout << ans << endl;





    return 0;
}