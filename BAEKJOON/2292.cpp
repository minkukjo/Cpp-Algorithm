//
// Created by 조민국 on 2019-01-24.
//

#include <iostream>

using namespace std;

int main()
{
    long long unsigned n;
    long long unsigned start = 1;
    long long unsigned add = 1;
    long long unsigned cnt = 1;
    cin >> n;

    // 시간초과남.

//    while(true)
//    {
//        long long unsigned a = 1 + 6*start;
//        long long unsigned b = 1 + 6*(start-add) +1;
//        if(n <= a && n >= b)
//        {
//            cout << add +1 << endl;
//            break;
//        }
//        add += 1;
//        start += add;
//    }

    // 다른 사람 소스코드 보고 수정.
    // 시간초과 나는 이유는 1씩 더하는 바람에 시간이 너무 오래 걸림.
    // 그에 비해 6xn으로 나아가기 때문에 이쪽 코드가 훨씬 time complexity가 좋음.

    while(true)
    {
        if(n <= start)
        {
            cout << cnt << endl;
            break;
        }
        add = 6*(cnt++);
        start += add;
    }

    return 0;
}