//
// Created by 조민국 on 2019-04-09.
//

// 경사로요맨

#include <iostream>
#include <cmath>
using namespace std;

int map[101][101];
int N;
int L;
int ans;






int main()
{

    cin >> N >> L;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> map[i][j];
        }
    }

    solve();

    cout << ans << endl;

    return 0;
}