//
// Created by 조민국 on 2019-04-18.
//

#include <iostream>

using namespace std;

string a[16];
char map[6][16];

void print(int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(map[j][i] == '%')
            {
                continue;
            }
            cout << map[j][i];
        }
    }
}
int main()
{
    int size = 0;
    for(int i=0; i<5; i++)
    {
        cin >> a[i];
    }

    for(int i=0; i<5; i++)
    {
        if(size < a[i].size())
        {
            size = a[i].size();
        }
    }


    for(int i=0; i<5; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(j+1 >a[i].size())
            {
                map[i][j] = '%';
            }
            else
            {
                map[i][j] = a[i][j];
            }
        }
    }

    print(size);




    return 0;
}