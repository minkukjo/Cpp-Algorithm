//
// Created by 조민국 on 2019-01-21.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<char, int> m;
    char max_c;
    int max_n = 0;
    int count = 0;
    bool search = false;
    string str;
    cin >> str;

    for(int i=65; i<91; i++)
    {
        m[i] = 0;
    }

    for(int i=0; i<str.size(); i++)
    {
        str[i] = toupper(str[i]);
        m[str[i]]++;
    }


    for(int i=0; i<str.size(); i++)
    {
        if ( m[str[i]] > max_n )
        {
                max_n = m[str[i]];
                max_c = str[i];
        }
    }

    for(int i=65; i<91; i++)
    {
        if ( m[i] == max_n )
        {
            count++;
        }

        if(count == 2)
        {
            cout << "?" << endl;
            return 0;
        }
    }



    cout << max_c << endl;



    return 0;
}