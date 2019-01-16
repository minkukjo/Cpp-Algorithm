//
// Created by 조민국 on 2019-01-16.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> a;
    int n;
    for(int i=0; i<3; i++)
    {
        cin >> n;
        a.push_back(n);
    }
    sort(a.begin(),a.end());
    cout << a[1] << endl;
    return 0;
}