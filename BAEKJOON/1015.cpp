//
// Created by 조민국 on 10/01/2019.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >>n;
    vector<pair<int,int>> a;
    int p[51];
    for(int i=0; i<n; i++)
    {
        int push;
        cin >> push;
        a.push_back(make_pair(push,i));
    }


    sort(a.begin(),a.end());

    for(int i=0; i<n; i++)
    {
        p[a[i].second] = i;
    }


    for(int i=0; i<n; i++)
    {
        cout << p[i] << " ";
    }
    return 0;
}