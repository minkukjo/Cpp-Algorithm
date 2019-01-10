//
// Created by 조민국 on 10/01/2019.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool judge(string& num)
{
    char state = 'S';
    char ch[201];
    for(int i=0; i<num.size(); i++)
    {
        ch[i] = num[i];
        switch(state)
        {
            case 'S':
                if(ch[i] == '0')
                {
                    state = 'B';
                } else if(ch[i] == '1')
                {
                    state = 'A';
                } else
                {
                    return false;
                }
                break;
            case 'B':
                if(ch[i] == '1')
                {
                    state = 'S';
                }
                else
                {
                    return false;
                }
                break;
            case 'A':
                if(ch[i] == '0')
                {
                    state = 'C';
                }
                else
                {
                    return false;
                }
                break;
            case 'C':
                if(ch[i] == '0')
                {
                    state = 'D';
                } else
                {
                    return false;
                }
                break;
            case 'D':
                if(ch[i] == '0')
                {
                    state = 'D';
                }
                else if(ch[i] == '1')
                {
                    state = 'E';
                } else
                {
                    return false;
                }
                break;
            case 'E':
                if(ch[i] == '1')
                {
                    state = 'F';
                } else if(ch[i] == '0')
                {
                    state = 'B';
                }
                else
                {
                    return false;
                }
                break;
            case 'F':
                if(ch[i] == '0')
                {
                    if(i+1 < num.size())
                    {
                        if(num[i+1] == '0')
                        {
                            state = 'C';
                        }
                        else if(num[i+1] == '1')
                        {
                            state = 'B';
                        } else
                        {
                            return false;
                        }
                    } else
                    {
                        return false;
                    }
                }
                else if(ch[i] == '1')
                {
                    state = 'F';
                } else
                {
                    return false;
                }
                break;
        }
    }

    return (state == 'S' || state == 'E' || state == 'F');
}

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        string num;
        cin >> num;
        bool ans;
//        vector<int> arr;
//        for(int i=0; i<num.size(); i++)
//        {
//            arr.push_back(num.at(i)-'0');
//        }



        ans = judge(num);
        if(ans == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

    }
    return 0;
}