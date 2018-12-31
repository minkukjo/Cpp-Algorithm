//
// Created by 조민국 on 31/12/2018.
//

#include <iostream>
#include <math.h>

using namespace std;
int main()
{
    int answer = 0;
    int t;
    int x1;
    int y1;
    int x2;
    int y2;
    int n;
    int cx;
    int cy;
    int r;
    cin >> t;
    for(;t>0; t--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        for(int i=1; i<=n; i++)
        {
            cin >> cx >> cy >> r;
            double l = sqrt( pow((x1-cx),2.0)+ pow((y1-cy),2.0));
            double l2 = sqrt( pow((x2-cx),2.0)+ pow((y2-cy),2.0));

            if( (l > r && l2 < r ) || (l <r && l2 > r))
            {
                answer++;
            }
        }
        cout << answer << endl;
        answer = 0;
    }


    return 0;
}