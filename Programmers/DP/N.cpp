//
// Created by 조민국 on 2019-02-07.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1e9 == 1000000000
int answer = 1e9;
int input_N;
int ans_number;
void search(int N, int counter)
{
    if(counter > 8)
    {
        return;
    }
    if(counter >= answer)
    {
        return;
    }
    if ((counter < answer ) && (N == ans_number))
    {
        answer = counter;
        return;
    }


    int temp = 0;
    for(int i=0; i<7; i++)
    {
        temp = temp*10 + input_N;
        search(temp + N, counter + i+1);
        search(temp * N, counter + i + 1);
        if(N != 0)
        {
            search(temp / N, counter+i+1);
        }
        search(N / temp,counter+i+1);
        search(temp + N, counter + i+1);
        search(N - temp,counter+i+1);
        search(temp - N,counter+i+1);
    }
}

int solution(int N, int number) {
    ans_number = number;
    input_N = N;
    search(0,0);
    if(answer > 8 )
    {
        return -1;
    }
    return answer;
}

int main()
{
    int N= 5;
    int number = 12;
    solution(N,number);

    return 0;
}