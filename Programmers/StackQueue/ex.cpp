//
// Created by 조민국 on 2019-01-22.
//

// CKML 과제

#include <stdio.h>

int main()
{
    unsigned char a[10];
    a[0] = 0x7E;
    a[1] = 0x06;
    a[2] = 0x11;
    a[3] = 0x01;
    a[4] = 0x03;
    a[5] = 0x0B;
    a[6] = 0x01;
    a[7] = 0x00;
    a[8] = 0x1F;
    a[9] = 0x7F;

    unsigned char cal_xor;
    cal_xor = a[1];

    for(int i=2; i<8; i++)
    {
        cal_xor = cal_xor ^ a[i];
    }
   return 0;
}