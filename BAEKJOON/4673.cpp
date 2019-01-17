//
// Created by 조민국 on 2019-01-17.
//

// 셀프넘버

#include <iostream>

using namespace std;

int arr[10001];

int selfnumber(int n)
{
    int sn =n;

    while(n>0)
    {
        sn += n%10;
        n /= 10;
    }
    return sn;
}
int main()
{
    int n = 1;

    while(n <= 10000)
    {
        int selfnum = selfnumber(n);

        if(selfnum <= 10000)
        {
            arr[selfnum] = 1;
        }
        n++;
    }


    for(int i=1; i<=10000; i++)
    {
        if(arr[i] == 0)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}