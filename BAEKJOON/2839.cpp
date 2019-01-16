//
// Created by 조민국 on 2019-01-15.
//

#include <iostream>

using namespace std;

int main()
{
    int N;
    int count=0;
    cin >> N;

    while(true)
    {
        if(N%5 == 0)
        {
            cout << N/5 + count << endl;
            break;
        }
        else if(N<0)
        {
            cout << -1 << endl;
            break;
        }
        N -= 3;
        count++;

    }


    return 0;
}