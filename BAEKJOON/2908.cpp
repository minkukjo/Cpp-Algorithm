//
// Created by 조민국 on 2019-01-22.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());

    int i1,i2;

    i1 = stoi(s1);
    i2 = stoi(s2);
    if(i1>i2)
    {
        cout << i1 << endl;
    }
    else
    {
        cout << i2 << endl;
    }
    return 0;
}