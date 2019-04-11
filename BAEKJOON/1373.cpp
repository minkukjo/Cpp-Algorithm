//
// Created by 조민국 on 2019-04-12.
//

#include<stdio.h>
#include<string.h>
char a[1000000+3] ={'0', '0' };
int main()
{
    scanf("%s",a+2);

    int length = strlen(a);
    int k = 0;

    for(int i=length%3; i<length; i=i+3)
    {
        printf("%d", (a[i]-'0')*4 + (a[i+1]-'0')*2 + (a[i+2]-'0')) ;
    }

}

