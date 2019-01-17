//
// Created by 조민국 on 2019-01-17.
//

#include <iostream>

using namespace std;

int arr[1001];

int isSequence(int n)
{
    int sn = n/10;
    int sign = n%10 - sn%10 ;

    if(n == 1000 || n == 100)
    {
        return 0;
    }

    int sign_compare = sn%10 - (sn/10)%10;
    if(sign_compare != sign)
    {
        return 0;
    }

    return 1;

}

int main()
{
    int N;
    int ans = 0;
    cin >> N;

    if(N >= 100)
    {
        for(int i=1; i<=99; i++)
        {
            arr[i] = 1;
        }

        for(int i=100; i<=N; i++)
        {
            int input = isSequence(i);
            if(input)
            {
                arr[i] = input;
            }
        }

        for(int i=1; i<=N; i++)
        {
            if(arr[i])
            {
                ans++;
            }
        }
        cout << ans << endl;
    } else
    {
        cout << N << endl;
    }




    return 0;
}