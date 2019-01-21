//
// Created by 조민국 on 2019-01-21.
//

#include <iostream>

using namespace std;

int main()
{
    int n;
    int total = 0;
    for(int i=0; i<5; i++)
    {
        cin >> n;
        if(n < 40)
        {
            n = 40;
        }
        total += n;
    }
    cout << total/5 << endl;



    return 0;
}