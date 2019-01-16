//
// Created by 조민국 on 2019-01-16.
//

#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N,X;
    int A;
    cin >> N >> X;

    for(int i=0; i<N; i++)
    {
        cin >> A;
        if(A <X)
        {
            cout << A << " ";
        }
    }

    return 0;
}