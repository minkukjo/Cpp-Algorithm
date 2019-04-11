//
// Created by 조민국 on 2019-04-12.
//

#include <iostream>

using namespace std;

int askii[125];

int main()
{
    string a;
    cin >> a;

    for(int i=0; i<a.size(); i++)
    {
        askii[a[i]]++;
    }

    for(int i=97; i<=122; i++)
    {
        cout << askii[i] << " ";
    }

    return 0;
}