//
// Created by 조민국 on 2019-01-21.
//

#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int,int> number;
    int N,N2,N3;
    int multiplication = 0;
    cin >> N >> N2 >> N3;

    multiplication = N*N2*N3;

    for(int i = multiplication; i>0; i /= 10)
    {
        number[i%10]++;
    }

    for(int i=0; i<10; i++)
    {
        cout << number[i] << endl;
    }



    return 0;
}