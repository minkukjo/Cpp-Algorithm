//
// Created by 조민국 on 11/01/2019.
//

#include <iostream>
#include <cmath>

using namespace std;

bool board[52][52];
bool answer_board[9][9][2]; // 0은 하얀색 먼저, 1은 검은색 먼저
int min_color = 9999999;

// W는 1 B는 0으로 하자.

int compare(int a, int b)
{
    int W_rectangle = 0;
    int B_rectangle = 0;
    for(int i=a+1; i<=8+a; i++)
    {
        for(int j=b+1; j<=8+b; j++)
        {
            if(board[i][j] != answer_board[i-a][j-b][0])
            {
                W_rectangle++;
            }

            if(board[i][j] != answer_board[i-a][j-b][1])
            {
                B_rectangle++;
            }

        }
    }

    return min(W_rectangle,B_rectangle);

}

int main()
{
    int row,col;
    cin>> row >> col;

    for(int i=1; i<=row; i++)
    {
        for(int j=1; j<=col; j++)
        {
            char C;
            cin >> C;
            if( C == 'W')
            {
                board[i][j] = 1;
            } else
            {
                board[i][j] = 0;
            }
        }
    }


    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
        {
            if(i%2 == 1)
            {
                if(j%2 == 1)
                {
                    answer_board[i][j][0] = 1;
                    answer_board[i][j][1] = 0;
                } else
                {
                    answer_board[i][j][0] = 0;
                    answer_board[i][j][1] = 1;
                }
            } else
            {
                if( j%2 == 1)
                {
                    answer_board[i][j][0] = 0;
                    answer_board[i][j][1] = 1;
                } else
                {
                    answer_board[i][j][0] = 1;
                    answer_board[i][j][1] = 0;
                }
            }
        }
    }




    for(int i=0; i<row-7; i++)
    {
        for(int j=0; j<col-7; j++)
        {
            min_color = min(min_color,compare(i,j));
        }
    }

    cout << min_color << endl;

    return 0;
}