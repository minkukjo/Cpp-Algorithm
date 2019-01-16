//
// Created by 조민국 on 2019-01-16.
//

#include <iostream>

using namespace std;

int main()
{
    int n;
    int ans = 0;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        ans += i;
    }
    cout << ans << endl;
    return 0;
}