//
// Created by 조민국 on 2019-03-31.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;

    cin >> a;

    for(int i=0; i<a.size(); i++)
    {
        if(a[i] >= 65 && a[i] <= 90)
        {
            cout << a[i];
        }
    }
    return 0;
}