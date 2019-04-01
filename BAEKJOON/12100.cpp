//
// Created by 조민국 on 2019-03-31.
//

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

// 2048

int map[25][25];
int n;
int ans = 0;


// 1 : 동 2 : 서 3 : 남 4 : 북

void make(int dir)
{
    queue<int> q;

    switch(dir)
    {
        // 동
        case 1:
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(map[i][j] !=0)
                    {
                        q.push(map[i][j]);
                    }
                    map[i][j] = 0;
                }

                int idx = 1;
                int pop_data;

                while(!q.empty()) {
                    pop_data = q.front();
                    q.pop();

                    if (map[i][idx] == 0) {
                        map[i][idx] = pop_data;
                    } else if (map[i][idx] == pop_data) {
                        map[i][idx] *= 2;
                        idx++;
                    } else {
                        map[i][++idx] = pop_data;
                    }
                }
            }
            break;

            // 서
        case 2:
            for(int i=1; i<=n; i++)
            {
                for(int j=n; j>=1; j--)
                {
                    if(map[i][j] !=0)
                    {
                        q.push(map[i][j]);
                    }
                    map[i][j] = 0;
                }

                int idx = n;
                int pop_data;

                while(!q.empty()) {
                    pop_data = q.front();
                    q.pop();

                    if (map[i][idx] == 0) {
                        map[i][idx] = pop_data;
                    } else if (map[i][idx] == pop_data) {
                        map[i][idx] *= 2;
                        idx--;
                    } else {
                        map[i][--idx] = pop_data;
                    }
                }
            }

            break;
            // 남
        case 3:
            for(int i=1; i<=n; i++)
            {
                for(int j=n; j>=1; j--)
                {
                    if(map[j][i] !=0)
                    {
                        q.push(map[j][i]);
                    }
                    map[j][i] = 0;
                }

                int idx = n;
                int pop_data;

                while(!q.empty()) {
                    pop_data = q.front();
                    q.pop();

                    if (map[idx][i] == 0) {
                        map[idx][i] = pop_data;
                    } else if (map[idx][i] == pop_data) {
                        map[idx][i] *= 2;
                        idx--;
                    } else {
                        map[--idx][i] = pop_data;
                    }
                }
            }
            break;
            //북
        case 4:
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(map[j][i] !=0)
                    {
                        q.push(map[j][i]);
                    }
                    map[j][i] = 0;
                }

                int idx = 1;
                int pop_data = 0;

                while(!q.empty()) {
                    pop_data = q.front();
                    q.pop();

                    if (map[idx][i] == 0) {
                        map[idx][i] = pop_data;
                    } else if (map[idx][i] == pop_data) {
                        map[idx][i] *= 2;
                        idx++;
                    } else {
                        map[++idx][i] = pop_data;
                    }
                }
            }
            break;
    }

}

void copy(int arr[][25],int arr2[][25])
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            arr[i][j] = arr2[i][j];
        }
    }
}

void print()
{
    for(int i=1; i<=n; i++)
    {
            for(int j=1; j<=n; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(int d)
{
    if(d == 5)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(map[i][j] > ans) ans = map[i][j];
            }
        }
        return;
    }


    int temp_map[25][25];
    copy(temp_map,map);

    for(int i=1; i<=4; i++)
    {
        make(i);
        dfs(d+1);
        copy(map,temp_map);

    }
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    dfs(0);


    cout << ans << endl;

    return 0;
}