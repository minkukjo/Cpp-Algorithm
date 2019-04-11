#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N,M;
int map[51][51];
bool visit[51];
int ans =  9999999;

vector<pair<int,int>> h;
vector<pair<int,int>> c;
vector<pair<int,int>> s;

void calDist()
{
    int dist[h.size()];
    for(int i=0; i<h.size(); i++)
    {
        dist[i] = 9999999;
    }

    for(int i=0; i<s.size(); i++)
    {
        for(int j=0; j<h.size(); j++)
        {
            int dis = abs(s[i].first - h[j].first) + abs(s[i].second - h[j].second);
            dist[j] = min(dist[j],dis);
        }
    }

    int temp = 0;

    for(int i=0; i<h.size(); i++)
    {
        temp += dist[i];
    }

    ans = min(ans,temp);

}

void dfs(int cnt, int k)
{

    if(cnt == M)
    {
        calDist();
        return;
    }
    for(int i=k; i<c.size(); i++)
    {
        s.push_back(c[i]);
        dfs(cnt+1,i+1);
        s.pop_back();

    }
}

int main()
{
    cin >> N >> M;

    memset(visit,false,sizeof(visit));

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%d",&map[i][j]);
            if(map[i][j] == 1)
            {
                h.push_back(make_pair(i,j));
            }
            else if(map[i][j] == 2)
            {
                c.push_back(make_pair(i,j));
            }
        }
    }

    dfs(0,0);

    cout << ans;
    return 0;
}