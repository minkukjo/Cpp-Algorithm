//
// Created by 조민국 on 2019-03-06.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long solution(int n, vector<int> times) {
    unsigned long long answer = 0;
    sort(times.begin(),times.end());

    unsigned long long start = 0;
    unsigned long long end = times[times.size()-1] * n;

    while(start <= end)
    {
        unsigned long long mid = (end+start)/2;
        unsigned long long temp = 0;

        for(int i : times)
        {
            if(i > mid)
            {
                break;
            }
            temp += mid/i;
        }

        if(temp >= n)
        {
            end = mid - 1;
            answer = mid;
        }
        else if(temp < n)
        {
            start = mid + 1;
        }

    }
    return answer;
}

int main()
{
    int n = 6;
    vector<int> times = {7,10};

    solution(n,times);
    return 0;
}