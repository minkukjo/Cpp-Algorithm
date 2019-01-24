//
// Created by 조민국 on 2019-01-23.
//

// 못품
// 아오
// 왜케 어렵냐 이거

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool comp(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}
struct Compare{
    bool operator()(pair<int,int> &a, pair<int,int> &b)
    {
        if(a.second == b.second)
        {
            return a.first > b.first;
        }
        return a.second>b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int old_time = 0;
    int i = 0;

    sort(jobs.begin(),jobs.end(),comp);
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
    pair<int,int> pq_get;

    while(true)
    {
        for(; i<jobs.size(); i++)
        {
            if(jobs[i][0] <= old_time)
            {
                pq.push(make_pair(jobs[i][0],jobs[i][1]));
            }
            else
            {
                break;
            }
        }

        if(i == jobs.size())
        {
            break;
        }

        if(pq.empty())
        {
            old_time++;
            continue;
        }


        pq_get = pq.top();
        pq.pop();

        answer += (old_time - pq_get.first) + pq_get.second;
        old_time += pq_get.second;
    }


    while(!pq.empty())
    {
        pq_get = pq.top();
        pq.pop();

        answer += (old_time - pq_get.first) + pq_get.second;
        old_time += pq_get.second;
    }


    answer = answer / jobs.size();

    return answer;
}

int main()
{
    vector<vector<int>> jobs = { {0,3},
                                 {1,9},
                                 {2,6},
                                 {0,5}};
    solution(jobs);
    return 0;
}