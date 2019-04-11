//
// Created by 조민국 on 2019-04-12.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int ans = 0;
    string a;
    cin >> a;

    for(int i=0; i<a.size(); i++)
    {
        if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
        {
            ans++;
        }
    }

    cout << ans;
    return 0;
}