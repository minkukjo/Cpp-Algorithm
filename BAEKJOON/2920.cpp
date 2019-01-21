//
// Created by 조민국 on 2019-01-21.
//

#include <iostream>

using namespace std;

int main()
{
    int n[9];
    int N;
    bool ascending = true;
    bool descending = true;

    for(int i=0; i<8; i++)
    {
        cin >> N;
        n[i] = N;

        if (ascending && i != 0 && n[i] - n[i - 1] == 1)
        {
            ascending = true;
            descending = false;
        }
        else if (descending && i != 0 && n[i - 1] - n[i] == 1)
        {
            descending = true;
            ascending = false;
        }
        else if (i != 0)
        {
            descending = false;
            ascending = false;
        }


    }

    if(ascending)
    {
        cout << "ascending" << endl;
    }
    else if(descending)
    {
        cout << "descending" << endl;
    } else
    {
        cout << "mixed" << endl;
    }



    return 0;
}