//
// Created by 조민국 on 2019-04-12.
//

#include <iostream>

using namespace std;

int main()
{
    int n;
    int a,b;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a >> b;
        cout << "Case #" << i+1 << ": " << a << " + " << b << " = " <<a+b << endl;
    }

    return 0;
}