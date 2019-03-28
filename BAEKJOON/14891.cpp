//
// Created by 조민국 on 2019-03-28.
//

// 톱니바퀴

#include <cstdio>

using namespace std;

int wheel[4][8];

void turn(int number,int dir)
{
    int temp;
    int temp_wheel[8];
    if(dir == 1)
    {
        for(int i =0; i<7; i++)
        {
            temp_wheel[i+1] = wheel[number][i];
        }
        temp_wheel[0] = wheel[number][7];

        //printf("태엽 번호 : %d, 방향 : %d \n",number,dir);
        for(int i =0; i<8; i++)
        {
            wheel[number][i] = temp_wheel[i];
            //printf("%d",wheel[number][i]);
        }
        //printf("\n");

    }
    else
    {
        for(int i =1; i<8; i++)
        {
            temp_wheel[i-1] = wheel[number][i];
        }
        temp_wheel[7] = wheel[number][0];

        //printf("태엽 번호 : %d, 방향 : %d \n",number,dir);
        for(int i =0; i<8; i++)
        {
            wheel[number][i] = temp_wheel[i];
            //printf("%d",wheel[number][i]);
        }
        //printf("\n");
    }



}


int Rolling(int number, int r)
{


    if(number == 0)
    {
        if( (wheel[number][2] != wheel[number+1][6]) && (wheel[number+1][2] != wheel[number+2][6]) && (wheel[number+2][2] != wheel[number+3][6]) )
        {
            turn(number,r);
            turn(number+1,-r);
            turn(number+2,r);
            turn(number+3,-r);
        }
        else if( (wheel[number][2] != wheel[number+1][6]) && (wheel[number+1][2] != wheel[number+2][6]) )
        {
            turn(number,r);
            turn(number+1,-r);
            turn(number+2,r);
        }
        else if( (wheel[number][2] != wheel[number+1][6]) )
        {
            turn(number,r);
            turn(number+1,-r);
        }
        else
        {
            turn(number,r);
        }
    }
    else if(number == 3)
    {
        if( (wheel[number][6] != wheel[number-1][2]) && (wheel[number-1][6] != wheel[number-2][2]) && (wheel[number-2][6] != wheel[number-3][2]) )
        {
            turn(number,r);
            turn(number-1,-r);
            turn(number-2,r);
            turn(number-3,-r);
        }
        else if( (wheel[number][6] != wheel[number-1][2]) && (wheel[number-1][6] != wheel[number-2][2]))
        {
            turn(number,r);
            turn(number-1,-r);
            turn(number-2,r);
        }
        else if( (wheel[number][6] != wheel[number-1][2]) )
        {
            turn(number,r);
            turn(number-1,-r);
        }
        else
        {
            turn(number,r);
        }

    }
    else if(number == 1)
    {
        if( ( wheel[number][6] != wheel[number-1][2]) && (wheel[number][2] != wheel[number+1][6]) && (wheel[number+1][2] != wheel[number+2][6]) )
        {
            turn(number,r);
            turn(number-1,-r);
            turn(number+1,-r);
            turn(number+2,r);
        }
        else if( (wheel[number][2] != wheel[number+1][6]) && (wheel[number+1][2] != wheel[number+2][6]) )
        {
            turn(number,r);
            turn(number+1,-r);
            turn(number+2,r);
        }
        else if( ( wheel[number][6] != wheel[number-1][2]) && (wheel[number][2] != wheel[number+1][6])  )
        {
            turn(number,r);
            turn(number-1,-r);
            turn(number+1,-r);
        }
        else if( (wheel[number][2] != wheel[number+1][6])  )
        {
            turn(number,r);
            turn(number+1,-r);
        }
        else if( ( wheel[number][6] != wheel[number-1][2]) )
        {
            turn(number,r);
            turn(number-1,-r);
        }
        else
        {
            turn(number,r);
        }
    }
    else if(number==2)
    {
        if( (wheel[number][2] != wheel[number+1][6]) && (wheel[number][6] != wheel[number-1][2]) && (wheel[number-1][6] != wheel[number-2][2]) )
        {
            turn(number,r);
            turn(number-1,-r);
            turn(number+1,-r);
            turn(number-2,r);
        }
        else if( (wheel[number][6] != wheel[number-1][2]) && (wheel[number-1][6] != wheel[number-2][2])   )
        {
            turn(number,r);
            turn(number-1,-r);
            turn(number-2,r);
        }
        else if( (wheel[number][2] != wheel[number+1][6]) && (wheel[number][6] != wheel[number-1][2]) )
        {
            turn(number,r);
            turn(number-1,-r);
            turn(number+1,-r);
        }
        else if(  (wheel[number][6] != wheel[number-1][2]) )
        {
            turn(number,r);
            turn(number-1,-r);
        }
        else if( (wheel[number][2] != wheel[number+1][6]))
        {
            turn(number,r);
            turn(number+1,-r);
        }
        else
        {
            turn(number,r);
        }
    }


//    printf("rotate:\n");
//    for(int i=0; i<4; i++)
//    {
//        for(int j=0; j<8; j++)
//        {
//            printf("%d",wheel[i][j]);
//        }
//        printf("\n");
//    }

}


int main()
{
    int n;
    char c;
    int number,dir;
    int ans = 0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<8; j++)
        {
            scanf("%c",&c);
            wheel[i][j] = c - '0';
        }
        getchar();
    }





    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &number,&dir);


        Rolling(number-1,dir);
//        printf("\n");
    }

    ans += wheel[0][0] == 0 ? 0 : 1;
    ans += wheel[1][0] == 0 ? 0 : 2;
    ans += wheel[2][0] == 0 ? 0 : 4;
    ans += wheel[3][0] == 0 ? 0 : 8;

    printf("%d",ans);

    return 0;
}
