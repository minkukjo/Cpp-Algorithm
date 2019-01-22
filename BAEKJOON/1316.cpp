//
// Created by 조민국 on 2019-01-22.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int answer = 0;
    int N;
    cin >> N;
    string str[101];
    bool combo = false;

    for(int i=0; i<N; i++)
    {
        string word;
        cin >> word;
        str[i] = word;
    }

    for(int i =0; i<N; i++)
    {
        bool check = true;
        map<char,int> m;
        for(int j=0; j<str[i].size(); j++)
        {
            if(j==0)
            {
                m[str[i][j]]++;
            }
            else
            {
                //cout << str[i][j-1] << str[i][j] << endl;
                if(str[i][j-1] == str[i][j])
                {
                    combo = true;
                }
                else
                {
                    combo = false;
                }

                if(combo == false)
                {
                    m[str[i][j]]++;
                }
            }
        }

        for(int j=0; j<str[i].size(); j++)
        {
            //cout << m[str[i][j]] << endl;
            if(m[str[i][j]] >= 2)
            {
                check = false;
                break;
            }
        }
        if(check == true)
        {
            answer++;
        }


    }

    cout << answer << endl;
    return 0;
}