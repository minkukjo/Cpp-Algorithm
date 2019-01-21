//
// Created by 조민국 on 2019-01-21.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    int ans = 0;
    int combo =0;
    cin >> T;

    while(T--)
    {
        char c;
        string str;
        cin>>str;

        for(int i=0; i<str.size(); i++)
        {
            c = str[i];
            if(c == 'O')
            {
                combo += 1;
            } else
            {
                combo = 0;
            }
            ans += combo;
        }

        cout << ans << endl;
        ans = 0;
        combo = 0;
    }



    return 0;
}