//
// Created by 조민국 on 2019-04-12.
//

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string a,b;
    int temp;

    for(int i=0; i<n; i++)
    {
        cin >> a>> b;
        cout << "Distances:";
        for(int j=0; j<a.size(); j++)
        {
            if(a[j] <= b[j])
            {
                temp = b[j]-a[j] ;
            }
            else
            {
                temp = b[j]+26-a[j];
            }

            cout << " " <<temp ;
        }
        cout << endl;
    }


    return 0;
}