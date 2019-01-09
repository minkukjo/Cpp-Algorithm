//
// Created by 조민국 on 09/01/2019.
//

#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    int t;
    cin >> t;



    while(t--)
    {
        int a;
        int b;
        cin >> a >> b;
        int data = a;

        for(int i=0;i<b-1; i++)
        {
            a = data * a % 10;
        }

        if(a==0)
        {
            a=10;
        }
        cout << a << endl;
    }




    return 0;
}