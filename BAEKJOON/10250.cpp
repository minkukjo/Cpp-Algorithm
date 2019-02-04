//
// Created by 조민국 on 2019-02-01.
//

#include <iostream>

using namespace std;


int ACM(int x, int y, int N)
{
   int answer = 0;
   int counter = 1;
    for(int i=0; i<x; i++)
    {
        answer = 0;
        answer += 100 + (i+1);
        for(int j=y-1; j>=0; j--)
        {
            if(counter != N)
            {
                counter++;
                answer += 100;
            }
            else if(counter == N)
            {
                return answer;
            }
        }

    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int x;
        int y;
        int N;
        cin >> y >> x >> N;

        cout << ACM(x,y,N)<< endl;



    }
    return 0;
}