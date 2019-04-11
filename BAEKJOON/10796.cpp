//
// Created by 조민국 on 2019-04-12.
//


#include <iostream>
using namespace std;
int main(void)
{
    string a;
    int happy = 0;
    int sad = 0;
    getline(cin,a);

    for(int i=0; i<a.size(); i++)
    {
        if(a[i] == ':')
        {
            if(a[i+1] == '-')
            {
                if(a[i+2] == ')')
                {
                    happy++;
                }
                else if(a[i+2] == '(')
                {
                    sad++;
                }
            }
        }
    }

    if(happy > sad)
    {

        cout << "happy";
    }
    else if(happy < sad)
    {
        cout << "sad";
    }
    else if(happy == sad && (happy != 0 || sad != 0))
    {
        cout << "unsure";
    }
    else if(happy == 0 && sad == 0)
    {
        cout << "none";
    }



    return 0;
}
