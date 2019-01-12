//
// Created by 조민국 on 12/01/2019.
//

// 실패 DP공부 더 해야할 듯!

#include <iostream>
#include <string>

using namespace std;

int dp[16];
int adge[10] = {6,2,5,5,4,5,6,3,7,5};

int num_size = 0;

int now_edge_count()
{
    int count = 0;
    for(int i=0; i<num_size; i++)
    {
        count += adge[dp[i]];
    }

    return count;
}

int main()
{
    string num;

    cin>>num;

    int now_edge = 0;



    int ans = 0;

    for(int i=num.size(); i>0; i--)
    {
        dp[num_size++] = num.at(i-1) - '0';
    }

    for(int i=0; i<num_size; i++)
    {
        now_edge += adge[dp[i]];
    }



    //cout << now_edge << endl;


    while(true)
    {
        ans++;

        dp[0] +=1;

        for(int i=0; i<num.size(); i++)
        {
            if(dp[i] == 10)
            {
                dp[i] = 0;
                dp[i+1] += 1;
            }
        }

        if(now_edge == now_edge_count())
        {
            break;
        }
    }

    cout << ans << endl;


    return 1;
}