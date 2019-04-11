//
// Created by 조민국 on 2019-04-12.
//

#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    for(int i=0; i<N; i++)
    {
        int a,b;
        scanf("%d,%d",&a,&b);
        cout << a+b<< endl;
    }
    return 0;
}