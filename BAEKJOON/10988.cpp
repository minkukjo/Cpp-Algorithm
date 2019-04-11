//
// Created by 조민국 on 2019-04-12.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    string b;
    cin >> a;

    for(auto iter = a.rbegin(); iter != a.rend(); iter++)
    {
        b += (*iter);
    }

    for(int i=0; i<a.size(); i++)
    {
        if(a[i] != b[i])
        {
            cout << "0";
            return 0;
        }
    }
    cout << "1";

    return 0;
}