//
// Created by 조민국 on 2019-01-21.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<char,int> m;
    string str;
    cin>> str;

    for(int i=97; i<123; i++)
    {
        m[i] = -1;
    }

    for(int i=0; i<str.size(); i++)
    {
        if(m[str[i]] == -1)
        {
            m[str[i]] = i;
        }

    }

    for(int i=97; i<123; i++)
    {
        //cout << char(i);
        cout << m[char(i)] << " ";
    }


    return 0;
}