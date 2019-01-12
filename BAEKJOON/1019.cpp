//
// Created by 조민국 on 12/01/2019.
//

// 어렵다... 혼자 힘으로는 못풀었네

#include <iostream>

using namespace std;
long long ans[10];

void calc(long long n, long long k)
{
    while(n>0)
    {
        ans[n%10] += k;
        n = n/10;
    }
}

int main()
{
    long long N;
    long long k=1;

    cin >> N;

    while(true)
    {
        while(N%10 != 9 && N>=0)
        {
            calc(N,k);
            N--;
        }

        if(N<=0)
        {
            break;
        }

        for(int i=0; i<=9; i++)
        {
            ans[i] += ((N/10)+1)*k;
        }

        ans[0] -= k;

        k *= 10;
        N = N/10;
    }

    for(int i=0; i<=9; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
