//
// Created by 조민국 on 09/01/2019.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long ans;
        int x,y;
        scanf("%d%d",&x,&y);
        int dist = y-x;

        for(long long n=1;;n++)
        {
            long long max_n,min_n;
            max_n = n*n + n;
            min_n = n*n -n +1;

            if(min_n<=dist && max_n >= dist)
            {
                if(n*n < dist)
                {
                    ans = 2*n;
                } else
                {
                    ans = 2*n-1;
                }
                break;
            }

        }
        printf("%d\n",ans);
    }
    return 0;
}