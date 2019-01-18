//
// Created by 조민국 on 2019-01-18.
//

// queue를 안쓰고 디큐를 써서 풀었음.
// 문제에 말한 것 처럼 앞 뒤를 붙이는 식으로 이동하면서
// 미리 소팅해놓은 벡터의 값과 비교해가면서 나아감.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

bool compare(int a, int b)
{
    if(a > b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int,int>> dq;
    vector<int> v_sort;
    for(int i=0; i<priorities.size(); i++)
    {
        dq.push_back(make_pair(priorities[i],i));
        v_sort.push_back(priorities[i]);
    }

    sort(v_sort.begin(),v_sort.end(),compare);


    while(1)
    {
        if(dq.front().first == v_sort[answer])
        {
            if(dq.front().second == location)
            {
                return answer+1;
            } else
            {
                dq.pop_front();
                answer++;
            }
        } else
        {
            dq.push_back(dq.front());
            cout << dq.back().first << endl;
            dq.pop_front();
            cout << dq.front().first << endl;
        }
    }


//    for(auto iter=dq.begin(); iter != dq.end(); ++iter)
//    {
//        cout << iter->first << iter->second << endl;
//    }




    return answer;
}

int main()
{
    vector<int> priorities;
//    priorities.push_back(2);
//    priorities.push_back(1);
//    priorities.push_back(3);
//    priorities.push_back(2);
//    cout << solution(priorities,2) << endl;

    priorities.push_back(1);
    priorities.push_back(1);
    priorities.push_back(9);
    priorities.push_back(1);
    priorities.push_back(1);
    priorities.push_back(1);
    cout << solution(priorities,0) << endl;
}