//
// Created by 조민국 on 2019-01-15.
//

#include <iostream>

using namespace std;

char a[101];

int main()
{
    char c;

    int count = 0;
    while(true)
    {
        c = getchar();

        if( c == EOF)
        {
            break;
        }

        a[count++] = c;
        if(c == '\n')
        {
            cout << a;
            for(int i= 0; i<count; i++)
            {
                a[i] = '\0';
            }
            count = 0;
        }
    }

    return 0;
}