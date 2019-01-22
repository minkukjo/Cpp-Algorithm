//
// Created by 조민국 on 2019-01-22.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;


    while(t--)
    {
        int N;
        cin >> N;

        string str;
        cin >> str;

        for(int i=0; i<str.size(); i++)
        {
            for(int j=0; j<N; j++)
            {
                cout << str[i];
            }
        }
        cout<<endl;


    }
    return 0;
}