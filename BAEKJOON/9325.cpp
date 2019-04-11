//
// Created by 조민국 on 2019-04-12.
//



#include <iostream>

using namespace std;


int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int total =  0;
        int s;
        cin >> s;
        total += s;
        int n;
        cin >> n;
        for(int i=0; i<n; i++)
        {
            int a,b;
            cin >> a >> b;
            total += a*b;
        }

        cout << total << endl;
    }

    return 0;
}