
//
// Created by 조민국 on 2019-01-16.
//

#include <iostream>

using namespace std;

int main()
{
    int n;
    int count= 0;
    char c;
    cin >>n;
    c = getchar();
    for(int i=0; i<n; i++)
    {
        c = getchar();
        count += c - '0';
    }
    cout << count << endl;

    return 0;
}