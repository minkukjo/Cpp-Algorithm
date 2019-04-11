//
// Created by 조민국 on 2019-04-12.
//

//
// Created by 조민국 on 2019-04-12.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> ans;


int main()
{
    string a;

    int size;
    cin >> a;

    size = a.size();


    for(int i=0; i<size; i++)
    {
        ans.push_back(a);
        reverse(a.begin(),a.end());
        a.pop_back();
        reverse(a.begin(),a.end());
    }

    sort(ans.begin(),ans.end());

    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << endl;
    }




    return 0;
}