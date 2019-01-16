//
// Created by 조민국 on 2019-01-16.
//

#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        for(int j=N-i+1; j>0; j--)
        {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}