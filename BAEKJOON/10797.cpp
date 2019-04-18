//
// Created by 조민국 on 2019-04-18.
//

#include <iostream>

using namespace std;

int main()
{
    int N;
    int ans = 0;
    int car;
    cin >> N;

    for(int i=0; i<5; i++)
    {
        cin >> car;
        if(car == N)
        {
            ans++;
        }
    }

    cout << ans;

    return 0;
}