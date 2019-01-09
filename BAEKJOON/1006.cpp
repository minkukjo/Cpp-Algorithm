/*
내가 짠거 아님 개어렵네
*/
#include <iostream>
#include <algorithm>
#include <cstring> //memset
using namespace std;

const int MAX = 10000;

int N; //(구역의 개수)/2
int sfNum; //special force number

int cirTagon[MAX][2]; //원타곤(circular Tagon)
//idx번째 블록 이전 블록, 마지막 블록 상태 표시
//0->방어되지 않음, 1->안쪽 원만 방어됨, 2->바깥쪽 원만 방어됨, 3->두 원 모두 방어됨
int cache[MAX][4][4];

int covered(int idx, int prev, int last) //previous(이전 블록), last(N-1 블록)의 상태
{
    int &result = cache[idx][prev][last];
    if (result != -1)
        return result;
    bool inner, outer, both; //안쪽 원, 바깥쪽 원, 두 원 모두 방어됬는가?
    //이전 블록과 묶어서 방어 가능한가?
    inner = (cirTagon[idx][0] + cirTagon[idx ? idx - 1 : N - 1][0] <= sfNum); //idx가 0인 경우 이전 블록이 last
    outer = (cirTagon[idx][1] + cirTagon[idx ? idx - 1 : N - 1][1] <= sfNum);
    //위 아래 블록 모두 방어 가능한가?
    both = (cirTagon[idx][0] + cirTagon[idx][1] <= sfNum);
    //끝에 도달했을 경우
    if (idx == N - 1)
    {
        if (idx == 0) //원타곤의 구역이 두개 밖에 없었을 경우
            return both ? 1 : 2; //위 아래 모두 방어되어있을 경우 1, 아닐 경우 2개의 스쿼드 필요
        result = 2; //기본적으로는 2개의 스쿼드 필요
        if (last == 0) //마지막 블록이 전혀 방어되어있지 않은 경우
        {
            //이전 블록의 안쪽과 묶어서 방어 가능하고
            //이전 블록의 안쪽이 방어되어있지 않은 경우
            if (inner && !(prev & 1)) //비트 &
                result = 1; //1개의 스쿼드
            //이전 블록의 바깥쪽과 묶어서 방어 가능하고
            //이전 블록의 바깥쪽이 방어되어있지 않은 경우
            if (outer && prev < 2)
                result = 1; //1개의 스쿼드
            //위 아래 블록 모두 방어 가능한가?
            if (both)
                result = 1; //1개의 스쿼드
            //이전 블록과 안쪽 바깥쪽 각각 묶을 경우
            if (inner && outer && prev == 0)
                result = 0; //스쿼드 추가 안해도 됨
        }
        else if (last == 1) //마지막 블록이 안쪽만 방어되어있는 경우
        {
            if (outer && prev < 2)
                result = 1;
        }
        else if (last == 2) //마지막 블록이 바깥쪽만 방어되어있는 경우
        {
            if (inner && !(prev & 1))
                result = 1;
        }
        return result;
    }
    //구역이 묶이지 않았을 경우
    result = 2 + covered(idx + 1, 0, idx ? last : 0);
    //이전 블록과 안쪽 구역을 묶을 때
    if (inner && !(prev & 1))
        result = min(result, 1 + covered(idx + 1, 1, idx ? last : 1));
    //이전 블록과 바깥쪽 구역을 묶을 때
    if (outer && prev < 2)
        result = min(result, 1 + covered(idx + 1, 2, idx ? last : 2));
    //이전 블록과 안쪽과 바깥 구역을 각각 묶을 때
    if (inner && outer && prev == 0)
        result = min(result, covered(idx + 1, 3, idx ? last : 3));
    //안쪽과 바깥 구역을 함께 묶을 때
    if (both)
        result = min(result, 1 + covered(idx + 1, 3, idx ? last : 0));
    return result;
}

int main(void)
{
    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        memset(cache, -1, sizeof(cache));
        memset(cirTagon, 0, sizeof(cirTagon));
        cin >> N >> sfNum;
        //원타곤 안쪽
        for (int i = 0; i < N; i++)
            cin >> cirTagon[i][0];
        //원타곤 바깥쪽
        for (int i = 0; i < N; i++)
            cin >> cirTagon[i][1];
        cout << covered(0, 0, 0) << endl;
    }
    return 0;
}