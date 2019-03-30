//
// Created by 조민국 on 2019-03-31.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> adj[10001];
vector<pair<int,int>> v_ans;
vector<int> last_ans;
bool visit[10001];
int max_ans = 0;
int ans = 0;

void dfs(int n)
{
    visit[n] = true;

    for(int i=0; i<adj[n].size(); i++)
    {
        if(!visit[adj[n][i]])
        {
            ans++;
            dfs(adj[n][i]);
        }
    }
}

bool compare(pair<int,int> a, pair<int,int> b)
{
    if(a.first > b.first)
    {
        return true;
    }
    return false;
}

int main()
{
    int N,M;
    int a,b;
    // N은 컴퓨터의 번호, M은
    cin >> N >> M;

    for(int i=0; i<M; i++)
    {
        cin >> a >> b;
        adj[b].push_back(a);
    }




    for(int i=1; i<=N; i++)
    {
        memset(visit,false,sizeof(visit));
        dfs(i);
        v_ans.push_back(make_pair(ans,i));
        ans = 0;
    }

    sort(v_ans.begin(),v_ans.end(),compare);

    max_ans = v_ans[0].first;
    last_ans.push_back(v_ans[0].second);
    for(int i=1; i<N; i++)
    {
        if(max_ans == v_ans[i].first)
        {
            last_ans.push_back(v_ans[i].second);
        }
    }

    sort(last_ans.begin(),last_ans.end());

    cout << last_ans[0];

    for(int i=1; i<last_ans.size(); i++)
    {
        cout << " " << last_ans[i];
    }


    return 0;
}