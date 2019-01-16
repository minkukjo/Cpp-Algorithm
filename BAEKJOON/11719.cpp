//
// Created by 조민국 on 2019-01-15.
//

#include <iostream>

using namespace std;

int main()
{
    char c;
    while(true)
    {
        c = getchar();
        if( c == EOF)
        {
            break;
        }
        cout << c;
    }
    return 0;
}