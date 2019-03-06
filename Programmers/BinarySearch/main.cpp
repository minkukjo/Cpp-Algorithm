#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int temp = 0;
    int count = 1;
    sort(budgets.begin(),budgets.end());

    for(int i=0; i<budgets.size(); i++)
    {
        temp += budgets[i];
    }

    if(temp < M)
    {
        return budgets[budgets.size()-1];
    }

    temp = 0;

    while(true)
    {
        for(int i=0; i<budgets.size()-count; i++)
        {
            temp += budgets[i];
        }

        int sum = (M - temp)/ count ;

        if( (sum > budgets[budgets.size()-count-1]) || count == budgets.size() )
        {
            for(int i=budgets.size()-count; i < budgets.size(); i++)
            {
                temp += sum;
            }

            if(temp <= M)
            {
                return sum;
            }
        }


        count++;
        temp = 0;
    }

    return answer;
}

int main()
{
    vector<int> budgets = {10,20,30,40};
    int M = 36;

    cout << solution(budgets,M) << endl;
    return 0;
}