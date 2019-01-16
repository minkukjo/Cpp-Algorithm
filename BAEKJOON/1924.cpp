//
// Created by 조민국 on 2019-01-16.
//

#include <iostream>

using namespace std;

int main()
{
    int cal[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int M,D;
    cin >> M >> D;
    int count=0;
    for(int i=1; i<M; i++)
    {
        count += cal[i-1];
    }
    count += D-1;
    switch (count%7)
    {
        case 0:
            printf("MON");
            break;
        case 1:
            printf("TUE");
            break;
        case 2:
            printf("WED");
            break;
        case 3:
            printf("THU");
            break;
        case 4:
            printf("FRI");
            break;
        case 5:
            printf("SAT");
            break;
        case 6:
            printf("SUN");
            break;
    }


    return 0;
}