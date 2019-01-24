#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int mixed = 0;
    int min = 0;
    int min_2 = 0;

    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0; i<scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }

    while(true)
    {
        if(pq.top() >= K)
        {
            break;
        }

        if(pq.size() == 1)
        {
            return -1;
        }
        min = pq.top();
        pq.pop();
        min_2 = pq.top();
        pq.pop();
        mixed = min + (2 * min_2);
        pq.push(mixed);
        answer++;
    }




    return answer;
}


int main() {
    vector<int> scoville = {1, 2, 3, 9, 10, 12};
    int K = 7;
    cout << solution(scoville, K) << endl;

    return 0;
}