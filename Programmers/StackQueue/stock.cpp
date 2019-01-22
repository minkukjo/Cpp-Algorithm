//
// Created by 조민국 on 2019-01-22.
//

// 도대체 이게 왜 Stack/Queue 문제인걸까?

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    // 답은 맞으나 O(n^2)으로 인하여 시간초과 나옴.

    // 테스트 1. push_back 대신 큐를 써보자
    // 테스트 1 실패

    // 테스트 2 원 코드에서 마지막 반복문을 -1 해주니 효용성 통과 왤까...?

    for(int i=0; i<prices.size()-1; i++)
    {
        for(int j=i+1; j<prices.size(); j++)
        {
            // j값이 작은 경우를 체크
            if(prices[i] > prices[j] || j == prices.size()-1)
            {
                answer.push_back(j-i);
                break;
            }
        }
    }
    answer.push_back(0);


//    while(!q.empty())
//    {
//        answer.push_back(q.front());
//        q.pop();
//    }
//
//    answer.push_back(0);




    return answer;
}

int main()
{
    vector<int> prices;
    prices.push_back(498);
    prices.push_back(501);
    prices.push_back(470);
    prices.push_back(489);
    solution(prices);
    return 0;
}