//
// Created by 조민국 on 2019-01-21.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> truck;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int total_size = 0;
    int count =0;

    for(int i=0; i<truck_weights.size(); i++)
    {
        int tw = truck_weights[i];
        while(true)
        {
            if(truck.empty())
            {
                truck.push(tw);
                total_size += tw;
                count++;
                break;
            }
            else if(truck.size() == bridge_length)
            {
                total_size -= truck.front();
                truck.pop();
            }
            else
            {
                if(total_size + tw > weight)
                {
                    truck.push(0);
                    count++;
                } else
                {
                    truck.push(tw);
                    count++;
                    total_size += tw;
                    break;
                }
            }

        }
    }

    answer = count + bridge_length;


    return answer;
}
int main()
{
    int bridge_length = 100;
    int weight = 100;
    vector<int> truck_weights;
    truck_weights.push_back(7);
    truck_weights.push_back(4);
    truck_weights.push_back(5);
    truck_weights.push_back(6);

    cout << solution(bridge_length,weight,truck_weights) << endl;

    return 0;
}