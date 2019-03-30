//
// Created by 조민국 on 2019-03-31.
//

#include <iostream>
#include <cstring>
using namespace std;

int arr[1001];
bool visit[1001];
int ans = 0;

// n은 처음 들어온놈 m은 현재 들어가있는 놈
void dfs(int n,int m)
{
    visit[m] = true;

    // 현재 arr[m]과 n이 같다. 즉 사이클이 발생했다. 즉시 종료
    if(n == arr[m])
    {
        ans++;
        return;
    }

    dfs(n,arr[m]);
}

int main()
{
    int t;

    cin >> t;



    while(t--)
    {
        int n;
        ans = 0;
        memset(visit,false,sizeof(visit));
        cin >> n;
        for(int i=1; i<=n; i++)
        {
            cin >> arr[i];
        }

        for(int i=1; i<=n; i++)
        {
            if(!visit[i])
            {
                dfs(i,i);
            }
        }

        cout << ans << endl;

    }



    return 0;
}