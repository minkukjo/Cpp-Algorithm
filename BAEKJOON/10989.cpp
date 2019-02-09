//
// Created by 조민국 on 2019-02-09.
//

#include <iostream>

using namespace std;

int v[10001];

int main()
{
    int t;

    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        int n;
        scanf("%d",&n);
        v[n]++;
    }

    for(int i=0; i<10001; i++)
    {
        if(v[i] != 0)
        {
            for(int j=0; j<v[i]; j++)
            {
                printf("%d\n",i);
            }
        }
    }

    return 0;
}