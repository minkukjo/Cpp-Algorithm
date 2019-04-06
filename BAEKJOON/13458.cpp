//
// Created by 조민국 on 2019-04-04.
//


// 시험 감독


#include <iostream>

long long room[1000001];
using namespace std;

int main()
{
    int N;
    int master;
    int sub;
    int temp;
    long long ans = 0;

    scanf("%d",&N);

    for(int i=1; i<=N; i++)
    {
        scanf("%lld",&room[i]);
    }


    cin >> master >> sub;

    for(int i=1; i<=N; i++)
    {
        room[i] -= master;
        ans+=1;
    }

    for(int i=1; i<=N; i++)
    {
        if(room[i] >= sub)
        {
            temp = room[i]%sub;
            ans += room[i]/sub;
            if(temp != 0)
            {
                ans += 1;
            }
            room[i] = temp;
        }
        else if(room[i] < sub && room[i] > 0)
        {
            ans+=1;
        }
    }







    printf("%lld",ans);



    return 0;
}