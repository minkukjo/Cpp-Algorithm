//
// Created by 조민국 on 2019-01-17.
//

#include <iostream>

using namespace std;

int main()
{
    int C;
    cin >> C;

    while(C--)
    {
        int N;
        double avg = 0;
        int sum_score= 0;
        int score=0;
        int student[1001];
        int pass_student_num = 0;
        cin >> N;
        for(int i=0; i<N; i++)
        {
            cin >> score;
            student[i] = score;
            sum_score += score;
        }

        avg = sum_score/N;

        for(int i=0; i<N; i++)
        {
            if(avg < student[i])
            {
                pass_student_num++;
            }
        }

        avg = (double)pass_student_num/(double)N;
        avg *= 100.000;

        printf("%.3f%%\n",avg);



    }
    return 0;
}