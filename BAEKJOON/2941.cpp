//
// Created by 조민국 on 2019-01-23.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int i=0;
    int answer = 0;
    cin >> str;

    while(true)
    {
        if(i == str.size())
        {
            break;
        }
        if(str[i] == 'c' && (str[i+1] == '=' || str[i+1] == '-'))
        {
            i += 2;
            answer++;
        }
        else if(str[i] == 'd' && str[i+1] == '-' )
        {
            i += 2;
            answer++;
        }
        else if(str[i] == 'd' && (str[i+1] == 'z' && str[i+2] == '='))
        {
            i+= 3;
            answer++;
        }
        else if(str[i] == 'l' && (str[i+1] == 'j'))
        {
            i += 2;
            answer++;
        }
        else if(str[i] == 'n' && (str[i+1] == 'j'))
        {
            i += 2;
            answer++;
        }
        else if(str[i] == 's' && (str[i+1] == '='))
        {
            i += 2;
            answer++;
        }
        else if(str[i] == 'z' && (str[i+1] == '='))
        {
            i += 2;
            answer++;
        }
        else
        {
            answer++;
            i +=1;
        }
    }

    cout << answer<< endl;


    return 0;
}