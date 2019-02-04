//
// Created by 조민국 on 2019-02-01.
//

#include <iostream>
#include <cmath>
using namespace std;

int n[10];
int max_n = 0;

int main()
{
    int N;
    cin >> N;
    int last = 0;
    bool triger = true;

    while(true)
    {
        last = N%10;
        N = N/10;

        if(last == 6 || last == 9)
        {
            if(triger)
            {
                n[6] += 1;
                triger = false;
            }
            else
            {
                n[9] += 1;
                triger = true;
            }
        }
        else
        {
            n[last] += 1;
        }

        if(N == 0)
        {
            break;
        }
    }


    for(int i=0; i<10; i++)
    {
        if(n[i] > max_n)
        {
            max_n = n[i];
        }
    }
    cout << max_n << endl;

    return 0;
}