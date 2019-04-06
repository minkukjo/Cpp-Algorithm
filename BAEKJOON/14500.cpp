//
// Created by 조민국 on 2019-04-04.
//

// 테트리미노

#include <iostream>
#include <cmath>

int map[501][501];

int f[19]; // 모든 형태의 가짓수 저장

int ans;

using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> map[i][j];
        }
    }


    // i = 행
    for(int i=0; i<N; i++)
    {
        // j = 열
        for(int j=0; j<M; j++)
        {


            // 가로 짝대기
            if(j + 3 < M )
            {
                f[0] = max(map[i][j] + map[i][j+1] + map[i][j+2] + map[i][j+3],f[0]);
            }
            // 세로 짝대기
            if(i+3 < N)
            {
                f[1] = max(map[i][j] + map[i+1][j] + map[i+2][j] + map[i+3][j],f[1]);
            }
            // 네모 상자
            if(i+1 < N && j+1 < M)
            {
                f[2] = max(map[i][j] + map[i+1][j] + map[i][j+1] + map[i+1][j+1],f[2]);
            }
            // 세로가 긴 ㄴ 모양
            if(j+1 < M && i+2 < N)
            {
                f[3] = max(map[i][j] + map[i+1][j] + map[i+2][j] + map[i+2][j+1],f[3]);
            }
            // 그거 반전 시킨거
            if(j+1 < M && i+2 < N)
            {
                f[4] = max(map[i][j+1] + map[i+1][j+1] + map[i+2][j+1] + map[i+2][j],f[4]);
            }
            // 눕힌 니은자
            if(i+1 < N && j+2 < M)
            {
                f[5] = max(map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+1][j+2],f[5]);
            }
            // 그거 반전
            if(i+1 < N && j+2 < M)
            {
                f[6] = max(map[i+1][j] + map[i+1][j+1] + map[i+1][j+2] + map[i][j+2],f[6]);
            }

            // 세로가 긴 기억자 왼쪽 방향 |-
            if(j+1 < M && i+2 < N)
            {
                f[7] = max(map[i][j] + map[i+1][j] + map[i+2][j] + map[i][j+1],f[7]);
            }

            // 그거 반전시킨거
            if(j+1 < M && i+2 < N)
            {
                f[8] = max(map[i][j] + map[i][j+1] + map[i+1][j+1] + map[i+2][j+1],f[8]);
            }

            // 가로가 긴 눕힌 기억 |-
            if(j+2 < M && i+1 <N)
            {
                f[9] = max(map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j],f[9]);
            }

            // 그거 반전시킨거
            if(j+2 < M && i+1 <N)
            {
                f[10] = max(map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+2],f[10]);
            }

            // 세로 긴 왼쪽 커브형
            if(j+1 <M && i+2 < N)
            {
                f[11] = max(map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+2][j+1],f[11]);
            }

            // 그거 반전시킨거
            if(j+1 <M && i+2 <N)
            {
                f[12] = max(map[i][j+1] + map[i+1][j+1] + map[i+1][j] + map[i+2][j],f[12]);
            }

            // 가로 긴 오른쪽 위 커브형
            if(j+2<M && i+1 < N)
            {
                f[13] = max(map[i+1][j] + map[i+1][j+1] + map[i][j+1] + map[i][j+2],f[13]);
            }

            // 그거 반전
            if(j+2<M && i+1 < N)
            {
                f[14] = max(map[i][j] +map[i][j+1] + map[i+1][j+1] + map[i+1][j+2],f[14]);
            }

            // ㅜ
            if(j+2 < M && i+1 < N)
            {
                f[15] = max(map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+1],f[15]);
            }

            // ㅗ
            if(j+2 < M && i+1 < N)
            {
                f[16] = max(map[i][j+1] + map[i+1][j] + map[i+1][j+1] + map[i+1][j+2],f[16]);
            }

            // ㅏ

            if(j+1 < M && i+2 < N)
            {
                f[17] = max(map[i][j] + map[i+1][j] + map[i+2][j] + map[i+1][j+1],f[17]);
            }

            // ㅓ

            if(j+1 < M && i+2 < N)
            {
                f[18] = max(map[i+1][j] + map[i][j+1] + map[i+1][j+1] + map[i+2][j+1],f[18]);
            }
        }
    }

    for(int i=0; i<19; i++)
    {
        if(ans < f[i])
        {
            ans = f[i];
        }
    }

    cout << ans ;











    return 0;
}