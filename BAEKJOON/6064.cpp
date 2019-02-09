//
// Created by 조민국 on 2019-02-01.
//

#include <iostream>

using namespace std;

// 유클리드 호제법을 이용한 최대공약수 구하는 함수
int gcd(int a, int b)
{
    while(b>0)
    {
        int temp = a;
        a = b;
        b = temp%b;
    }
    return a;
}

// a*b를 최대공약수로 나눠서 최소공배수를 찾아줌.

int lcm(int a, int b)
{
    return a*b/gcd(a,b);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int M;
        int N;
        int x;
        int y;
        cin >> M >> N >> x >> y;

        int count = x % (M+1);
        int tempy = x;

        for(int i=0; i<N; i++)
        {
            int temp = tempy % N == 0 ? N : tempy % N;
            if(temp == y)
            {
                break;
            }
            tempy = temp + M;
            count += M;
        }
        int answer = count > lcm(M,N) ? -1 : count;
        cout << answer << endl;


//        시간초과남 이렇게 짜면 O(MN)이 됌.
//        while(true)
//        {
//            if( (now_x == M) && (now_y == N) )
//            {
//                cout << year << endl;
//                break;
//            }
//
//            if( (now_x == x) && (now_y == y) )
//            {
//                cout << -1 << endl;
//                break;
//            }
//
//            if(now_x >= x)
//            {
//                now_x = 1;
//            }
//            else
//            {
//                now_x++;
//            }
//
//            if(now_y >= y)
//            {
//                now_y = 1;
//            }
//            else
//            {
//                now_y++;
//            }
//
//            year++;
//
//
//        }





    }
    return 0;
}