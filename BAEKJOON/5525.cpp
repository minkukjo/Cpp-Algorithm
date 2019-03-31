//
// Created by 조민국 on 2019-03-31.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getpi(string Pn)
{
    int j =0;
    int M = Pn.size();

    vector<int> pi(M,0);

    for(int i=1; i<M; i++)
    {
        while(j>0 && Pn[i] != Pn[j])
        {
            j = pi[j-1];
        }

        if(Pn[i] == Pn[j])
        {
            pi[i] = ++j;
        }
    }

    return pi;
}

vector<int> KMP(string S, string Pn)
{
    vector<int> ans;
    int j = 0;
    auto pi = getpi(Pn);
    int M = Pn.size();

    for(int i=0; i<S.size(); i++)
    {
        while(j>0 && S[i] != Pn[j])
        {
            j = pi[j-1];
        }

        if(S[i] == Pn[j])
        {
            if(j == M -1)
            {
                ans.push_back(i-M-1);
                j = pi[j];
            }
            else
            {
                j++;
            }
        }
    }

    return ans;

}

int main()
{
    int N;
    int M;
    string S;
    string Pn;
    vector<int> ans;

    Pn = "I";

    cin >> N;
    cin >> M;
    cin >> S;

    for(int i=0; i<N; i++)
    {
        Pn.append("OI");
    }

    ans = KMP(S,Pn);
    cout << ans.size() << endl;


    return 0;
}