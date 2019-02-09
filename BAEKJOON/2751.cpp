//
// Created by 조민국 on 2019-02-09.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    vector<int> v;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(),v.end());

    for(int i=0; i<t; i++)
    {
        printf("%d\n",v[i]);
    }

    return 0;
}