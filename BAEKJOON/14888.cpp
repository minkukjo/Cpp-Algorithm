//
// Created by 조민국 on 2019-04-09.
//

// 연산자 끼워넣기

#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

long long ans_min = 1000000000;
long long ans_max = -1000000000;

int a[11];

class op
{
public:
    int pl;
    int mi;
    int mul;
    int divi;
    long long middle;
    int count;
    op(int a, int b, int c, int d,long long e,int f):pl(a),mi(b),mul(c),divi(d),middle(e),count(f){};
};

queue<op> q;

int pl;
int mi;
int mul;
int divi;

int N;

void bfs()
{
    if(pl > 0)
    {
        q.push(op(pl-1,mi,mul,divi,a[0]+a[1],1));
    }

    if(mi > 0)
    {
        q.push(op(pl,mi-1,mul,divi,a[0]-a[1],1));
    }

    if(mul > 0)
    {
        q.push(op(pl,mi,mul-1,divi,a[0]*a[1],1));
    }


    if(divi > 0)
    {
        q.push(op(pl,mi,mul,divi-1,a[0]/a[1],1));
    }


    while(!q.empty())
    {
        int size = q.size();

        for(int i=0; i<size; i++)
        {
            int pl = q.front().pl;
            int mi = q.front().mi;
            int mul = q.front().mul;
            int divi = q.front().divi;
            long long v = q.front().middle;
            int ct = q.front().count;
            q.pop();

            if(ct == N-1)
            {
                ans_max = max(ans_max,v);
                ans_min = min(ans_min,v);
                continue;
            }

            if(pl > 0)
            {
                q.push(op(pl-1,mi,mul,divi,v+a[ct+1],ct+1));
            }

            if(mi > 0)
            {
                q.push(op(pl,mi-1,mul,divi,v-a[ct+1],ct+1));
            }

            if(mul > 0)
            {
                q.push(op(pl,mi,mul-1,divi,v*a[ct+1],ct+1));
            }

            if(divi > 0)
            {
                q.push(op(pl,mi,mul,divi-1,v/a[ct+1],ct+1));
            }


        }
    }

}

int main()
{

    cin >> N;

    for(int i=0; i<N; i++)
    {
        cin >> a[i];
    }

    cin >> pl >> mi >> mul >> divi;


    bfs();

    cout << ans_max << endl;
    cout << ans_min << endl;

    return 0;
}