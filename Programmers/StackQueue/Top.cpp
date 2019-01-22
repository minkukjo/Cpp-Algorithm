//
// Created by 조민국 on 2019-01-22.
//

#include <iostream>
// 필요없을거같아서 주석 해놓음 문제 생기면 이거 주석 해제 해볼 것.
// #include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> s;


    for(int i=heights.size()-1; i>=0; i--)
    {
        bool check = false;
        for(int j=i-1; j>=0; j--)
        {
            if(heights[i] < heights[j])
            {
                s.push(j+1);
                check = true;
                break;
            }
        }
        if(check == false)
        {
            s.push(0);
        }
    }

    while(!s.empty())
    {
        int t = s.top();
        s.pop();
        answer.push_back(t);
    }



    return answer;
}

int main()
{
    vector<int> heights;
//    heights.push_back(6);
//    heights.push_back(9);
//    heights.push_back(5);
//    heights.push_back(7);
//    heights.push_back(4);


    heights.push_back(3);
    heights.push_back(9);
    heights.push_back(9);
    heights.push_back(3);
    heights.push_back(5);
    heights.push_back(7);
    heights.push_back(2);
    solution(heights);
    return 0;
}