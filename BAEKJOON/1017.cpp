//
// Created by 조민국 on 11/01/2019.
//

// 못풀었다 제길.. 계속 틀리네

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int list[51];
bool check[51][51];
int N;
vector<int> ans;

bool isPrime(int n)
{
    if(n<=1)
    {
        return false;
    }

    for(int i=2; i*i<=n; i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }

    return true;

}

void dfs(int start,int cases,int pair)
{
    if(start == N)
    {
        int count = 0;
        for(int i=0; i<N; i++)
        {
            if(check[cases][i] == true)
            {
                count++;
            }
        }

        if(count == N)
        {
            ans.push_back(list[pair]);
        }

        return;
    }

    // i가 N까지 증가하면서 묶을 애들을 찾음.
    for(int i=0; i<N; i++)
    {
        // 현재 짝이 없는 경우
        if (check[cases][i] == false)
        {
            // 처음 시작하는 경우 + 그 합이 소수인 경우
            if(start == 0 && isPrime(list[start]+list[pair]))
            {
                check[cases][start] = true;
                check[cases][pair] = true;
                dfs(start+1,cases,pair);
            }
            // 묶을 대상이 보인다면 묶음. 단, 내가 누군가에게 묶여졌다면 다른 녀석을 묶을 수 없음. + 그 합이 소수인 경우
            else if(check[cases][start] == false && start != i && isPrime(list[start] + list[i]))
            {
                check[cases][start] = true;
                check[cases][i] = true;
                dfs(i+1,cases,pair);
            }
            // 이미 선택당한 경우
            else if(i+1==N)
            {
                dfs(start+1,cases,pair);
            }
        }
    }
}

int main()
{

    cin >> N;

    for(int i=0; i<51; i++)
    {
        for(int j=0; j<51; j++)
        {
            check[i][j] = false;
            check[i][0] = true;
        }
    }

    for(int i=0; i<N; i++)
    {
        int value;
        cin >> value;
        list[i] = value;
    }



    for(int i=0; i<N; i++)
    {
        dfs(0,i,i+1);
    }

    sort(ans.begin(),ans.end());

    if(ans.size() > 0)
    {
        for(int i=0; i<ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    } else
    {
        cout << "-1" << endl;
    }


//    cout << isPrime(127) << endl;



    return 0;
}


