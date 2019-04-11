//
// Created by 조민국 on 2019-04-12.
//

#include <iostream>
#include <string>
#include <algorithm>


using namespace std;



string add(string a,string b)
{
    int sum = 0;
    string ans;
    while(!a.empty() || !b.empty() || sum)
    {
        if(!a.empty()) sum += a.back() - '0',a.pop_back();
        if(!b.empty()) sum+= b.back() - '0',b.pop_back();
        ans.push_back((sum%10) + '0');
        sum /= 10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    string a,b;
    string ans;

    cin >> a >> b;

    ans = add(a,b);

    cout << ans;



    return 0;
}