//
// Created by 조민국 on 2019-01-16.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string n;
    char c;
    cin >> n;
    for(int i=1; i<=n.size(); i++)
    {
        c = n.at(i-1);
        cout << c;
        if(i%10 == 0)
        {
            cout << "\n";
        }
    }


    return 0;
}