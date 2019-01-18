#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// 스택을 사용해서 () <- 레이저가 되는 경우 현재 스택에 쌓인 개수만큼 답에 더함.
// )<- 를 만났을 시에 만약 이전에도 ) <- 라면 막대기 끝이라는 의미에서 +1 더함.

int solution(string arrangement) {
    int answer = 0;
    stack<char> stack;

    for(int i=0; i<arrangement.size(); i++)
    {
        if(arrangement.at(i) == '(')
        {
            stack.push(arrangement.at(i));
        } else
        {
            stack.pop();
            if(arrangement.at(i-1) == '(')
            {
                answer += stack.size();
            }
            else
            {
                answer++;
            }

        }
    }
    return answer;
}

int main()
{
    string arg;

    arg = "()(((()())(())()))(())";
    cout <<solution(arg) << endl;


    return 0;
}