//
// Created by 조민국 on 2019-01-21.
//

// 정다압~!

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    bool trigger = true;
    int ans=0;
    getline(cin,str);

    for(int i=0; i<str.size(); i++)
    {
        if ( str[i] == ' ')
        {
            trigger = true;
        } else
        {
            if(trigger == true)
            {
                ans++;
            }
            trigger = false;
        }
    }


    cout << ans<<endl;

}