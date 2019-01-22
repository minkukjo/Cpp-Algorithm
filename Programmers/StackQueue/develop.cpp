//
// Created by 조민국 on 2019-01-21.
//

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int,int>> q;
    queue<int> ans;

    int days= 0;

    for(int i=0; i<progresses.size(); i++)
    {
        q.push(make_pair(progresses[i],speeds[i]));
    }

    while (!q.empty())
    {
        int p = q.front().first;
        int s = q.front().second;
        q.pop();

        while(true)
        {
            if (p + days * s < 100)
            {
                days++;
            }
            else
            {
                break;
            }
        }

        ans.push(days);
    }

    ans.push(-1);

    int pre = ans.front();
    ans.pop();
    int count = 1;


    while(!ans.empty())
    {
        cout << ans.front() << endl;
        if(pre == ans.front())
        {
            count++;
            ans.pop();
        } else
        {
            answer.push_back(count);
            pre = ans.front();
            count = 1;
            ans.pop();
        }
    }






    return answer;
}

int main()
{
    vector<int> progresses;

    vector<int> speeds;

    progresses.push_back(40);
    progresses.push_back(93);
    progresses.push_back(30);
    progresses.push_back(55);
    progresses.push_back(60);
    progresses.push_back(65);

    speeds.push_back(60);
    speeds.push_back(1);
    speeds.push_back(30);
    speeds.push_back(5);
    speeds.push_back(10);
    speeds.push_back(7);

    solution(progresses,speeds);

    return 0;
}