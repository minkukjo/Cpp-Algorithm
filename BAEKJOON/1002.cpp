//
// Created by 조민국 on 27/12/2018.
//

#include <iostream>
#include <math.h>

using namespace std;
int main() {
    int t;
    cin >> t;
    for(;t>0; t--)
    {
        int x1,y1,r1,x2,y2,r2;

        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;


        double i = sqrt(pow((x1-x2),2.0) + pow((y1-y2),2.0));

        if(x1 == x2 && y1 == y2)
        {
            if(r1 == r2)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        } else{
            if( (r1+r2) > i && i > abs(r1-r2))
            {
                cout << 2 << endl;
            }
            else if(r1+r2 == i || abs(r1-r2) == i)
            {
                cout << 1 << endl;
            } else
            {
                cout << 0 << endl;
            }
        }

    }



    return 0;
}