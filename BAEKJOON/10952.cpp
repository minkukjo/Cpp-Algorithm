//
// Created by 조민국 on 2019-04-12.
//

#include <iostream>
using namespace std;

int main()
{
    int a=55,b=55;

    while(true)
    {
        scanf("%d %d",&a,&b);
        if(a == 0 && b == 0)
        {
            break;
        }
        cout << a+b<< endl;
    }
    return 0;
}