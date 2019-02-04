//
// Created by 조민국 on 2019-02-01.
//

#include <iostream>

using namespace std;

int arr[15][15];
int main()
{
    int t;
    int temp = 0;
    cin >> t;

    for(int i=1; i<=14; i++)
    {
        arr[0][i] = i;
    }

    for(int i=1; i<=14; i++)
    {
        for(int j=1; j<=14; j++)
        {
            for(int k=0; k<=j; k++)
            {
                arr[i][j] += arr[i-1][k];
            }
        }
    }

    while(t--)
    {
        int k;
        int n;
        cin >> k >> n;
        cout << arr[k][n] << endl;
    }
    return 0;
}