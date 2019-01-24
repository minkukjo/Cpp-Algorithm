//
// Created by 조민국 on 2019-01-23.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int start = 0;
    priority_queue<int> pq;

    while(stock < k)
    {
        for(int i=start; i<dates.size(); i++)
        {
            if(dates[i] <= stock)
            {
                pq.push(supplies[i]);
            } else
            {
                start = i;
                break;
            }
        }
        stock += pq.top();
        pq.pop();
        answer++;
    }

    return answer;
}

int main()
{
    int stock = 4;
    vector<int> dates = {4,10,15};
    vector<int> supplies = {20,5,10};
    int k =30;
    solution(stock,dates,supplies,k);
    return 0;
}