//
// Created by 조민국 on 2019-01-22.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int answer = 0;
    string str;
    cin >> str;

    for(int i=0; i<str.size(); i++)
    {
        switch(str[i]){
            case 'A':
            case 'B':
            case 'C':
                answer += 3;
                break;
            case 'D':
            case 'E':
            case 'F':
                answer += 4;
                break;
            case 'G':
            case 'H':
            case 'I':
                answer += 5;
                break;
            case 'J':
            case 'K':
            case 'L':
                answer += 6;
                break;
            case 'M':
            case 'N':
            case 'O':
                answer += 7;
                break;
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
                answer += 8;
                break;
            case 'T':
            case 'U':
            case 'V':
                answer += 9;
                break;
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                answer += 10;
                break;
            default:
                break;
        }
    }

    cout << answer << endl;
    return 0;
}