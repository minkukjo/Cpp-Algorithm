//
// Created by 조민국 on 2019-04-05.
//

// 퇴사

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> d;
int N;
int ans=0;

void dfs(int time, int pay)
{
    if(time >= N)
    {
        ans = max(ans,pay);
        return;
    }

    dfs(time+1,pay);

    if(time + d[time].first <= N)
    {
        dfs(time+d[time].first,pay+d[time].second);
    }

}

int main()
{

    int time,pay;
    cin >> N;


    for(int i=0; i<N; i++)
    {
        cin >> time >> pay;
        d.push_back(make_pair(time,pay));
    }

    for(int i=0; i<N; i++)
    {
        dfs(i,0);
    }



    cout << ans << endl;

    return 0;
}