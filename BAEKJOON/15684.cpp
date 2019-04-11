//
// Created by 조민국 on 2019-04-11.
//

// 사다리 주작

#include <iostream>
#include <cstring>

using namespace std;

int map[31][11];
int N,M,H;
int ans=9999999;

bool chk()
{
    int pos;
    for(int i=1; i<=N; i++)
    {
        pos = i;
        for(int j=1; j<=H; j++)
        {
            if(map[j][pos] == 1) pos++;
            else if(map[j][pos-1] == 1) pos--;

        }
        if(i != pos) return false;
    }
    return true;
}

void print()
{
    cout << endl;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=H; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void go(int count, int x,int y)
{
    if(chk())
    {
        ans = min(ans,count);
        return;
    }
    if(count == 3)
    {
        return;
    }
    //print();

    for(int i=y; i<=H; i++)
    {
        x = 1;
        for(int j=x; j<N; j++)
        {
            if(map[i][j])
            {
                j++;
                continue;
            }
            map[i][j] = 1;
            //print();
            go(count+1,j+2,i);
            map[i][j] = 0;
        }
    }

}

int main()
{

    // M : x, N : y

    cin >> N>> M >> H;

    for(int i=1; i<=M; i++)
    {
        int a,b;
        cin >> a >> b;
        map[a][b] = 1;
    }


    go(0,1,1);




    if(ans>3)
    {
        cout << "-1";
    }
    else
    {
        cout << ans << endl;
    }

    return 0;
}