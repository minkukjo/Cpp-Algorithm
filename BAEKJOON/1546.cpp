//
// Created by 조민국 on 2019-01-17.
//

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N;
    double answer;
    int max_score = 0;
    int score;
    double arr[1001];
    cin >> N;

    for(int i=0; i<N; i++)
    {
        cin >> score;
        arr[i] = score;
        max_score = max(score,max_score);
    }


    for(int i=0; i<N; i++)
    {
        answer += (arr[i]/max_score) * 100;
    }


    printf("%.2lf",answer/N);


    return 0;
}