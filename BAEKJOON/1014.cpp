//
// Created by 조민국 on 10/01/2019.
//

// 넘어렵다..


#include <iostream>

using namespace std;



int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int col,row;
        int student=0;
        int m[11][11][2];
        for(int i=1; i<=10; i++)
        {
            for(int j=1; j<=10; j++)
            {
                for(int k=0; k<2; k++)
                {
                    m[i][j][k] = 0;
                }
            }
        }
        cin >> row >> col;
        for(int i=1; i<=row; i++)
        {
            for(int j=1; j<=col; j++)
            {
                char input;
                cin >> input;
                if(input == '.')
                {
                    m[i][j][0] = 1;
                }
                else
                {
                    m[i][j][0] = 0;
                }
            }
        }


        for(int i=1; i<=row; i++)
        {
            for(int j=1; j<=col; j++)
            {
                if(m[i][j][0] == 1)
                {
                    if( (m[i][j+1][1] == 0 && m[i][j-1][1] == 0 && m[i-1][j+1][1] == 0 && m[i-1][j-1][1] == 0 ) || j == 1)
                    {
                        m[i][j][1] = 1;
                        student++;
                    }

                }
                else
                {
                    m[i][j][1] = 0;
                }
            }

        }

        cout<<endl;
        cout<<student<<endl;




    }


    return 0;
}