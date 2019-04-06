//
// Created by 조민국 on 2019-04-04.
//

// 주사위 굴리기

#include <iostream>

using namespace std;

int map[21][21];

int dice[4][4];
int temp[4][4];

void print(int map[][4])
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void move(int n,int* x,int* y)
{



    // 오른쪽
    if(n == 1)
    {

        // 위
        temp[1][1] = dice[1][0];
        // 밑
        temp[3][1] = dice[1][2];
        // 오른쪽
        temp[1][2] = dice[1][1];
        // 남방향
        temp[2][1] = dice[2][1];
        // 왼
        temp[1][0] = dice[3][1];
        // 북방향
        temp[0][1] = dice[0][1];

        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                dice[i][j] = temp[i][j];
            }
        }

        if(map[*x][++(*y)] == 0)
        {
            map[*x][*y] = dice[3][1];
        }
        else
        {
            dice[3][1] = map[*x][*y];
            map[*x][*y] = 0;
        }

        //cout<< endl;
        //print(dice);
        cout<< dice[1][1] << endl;

    }
    // 왼쪽
    else if(n==2)
    {
        // 위
        temp[1][1] = dice[1][2];
        // 밑
        temp[3][1] = dice[1][0];
        // 오른쪽
        temp[1][2] = dice[3][1];
        // 남방향
        temp[2][1] = dice[2][1];
        // 왼
        temp[1][0] = dice[1][1];
        // 북방향
        temp[0][1] = dice[0][1];

        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                dice[i][j] = temp[i][j];
            }
        }

        if(map[*x][--(*y)] == 0)
        {
            map[*x][*y] = dice[3][1];
        }
        else
        {
            dice[3][1] = map[*x][*y];
            map[*x][*y] = 0;
        }

        //cout<< endl;
        //print(dice);
        cout<< dice[1][1] << endl;
    }
    // 북쪽
    else if(n==3)
    {
        // 위
        temp[1][1] = dice[2][1];
        // 밑
        temp[3][1] = dice[0][1];
        // 오른쪽
        temp[1][2] = dice[1][2];
        // 남방향
        temp[2][1] = dice[3][1];
        // 왼
        temp[1][0] = dice[1][0];
        // 북방향
        temp[0][1] = dice[1][1];

        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                dice[i][j] = temp[i][j];
            }
        }

        if(map[--(*x)][*y] == 0)
        {
            map[*x][*y] = dice[3][1];
        }
        else
        {
            dice[3][1] = map[*x][*y];
            map[*x][*y] = 0;
        }

        //cout<< endl;
        //print(dice);
        cout<< dice[1][1] << endl;
    }
    // 남쪽
    else if(n==4)
    {
        // 위
        temp[1][1] = dice[0][1];
        // 밑
        temp[3][1] = dice[2][1];
        // 오른쪽
        temp[1][2] = dice[1][2];
        // 남방향
        temp[2][1] = dice[1][1];
        // 좌측
        temp[1][0] = dice[1][0];
        // 북방향
        temp[0][1] = dice[3][1];

        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                dice[i][j] = temp[i][j];
            }
        }

        if(map[++(*x)][(*y)] == 0)
        {
            map[*x][*y] = dice[3][1];
        }
        else
        {
            dice[3][1] = map[*x][*y];
            map[*x][*y] = 0;
        }

        //cout<< endl;
        //print(dice);
        cout<< dice[1][1] << endl;
    }
}



int main()
{
    int N,M;
    int x,y;
    int k;
    cin >> N >> M >> x >> y >> k;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> map[i][j];
        }
    }

    //print(map,N,M);

    for(int i=0; i<k; i++)
    {
        int dir;
        cin >> dir;

        if(dir == 1 && y+1> M-1 )
        {
            continue;
        }
        else if(dir == 2 && y-1 < 0)
        {
            continue;
        }
        else if(dir==3 && x-1 < 0)
        {
            continue;
        }
        else if(dir == 4 && x+1 >N-1)
        {
            continue;
        }
        move(dir,&x,&y);
    }


    return 0;
}