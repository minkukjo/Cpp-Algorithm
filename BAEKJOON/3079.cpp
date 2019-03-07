//
// Created by 조민국 on 2019-03-07.
//

#include <iostream>

using namespace std;

long long times[100001];

int main()
{
    long long n;
    long long m;
    long long ans = 0;
    long long input;
    cin >> n >> m;

    for(long long i=0; i<n; i++)
    {
        cin >> input;
        times[i] = input;
    }

    long long start = 0;
    long long end = 1000000000000000000LL;

    while(start <= end)
    {
        long long mid = (end+start)/2;
        long long sum = 0;

        for(long long i =0; i<n; i++)
        {
            sum += mid/times[i];
        }

        if(sum >= m)
        {
            end = mid-1;
            ans = mid;
        }
        else if( sum < m)
        {
            start = mid+1;
        }
    }

    cout << ans << endl;



    return 0;
}