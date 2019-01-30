#include <iostream>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

long long arr[81];

long long solution_songdong(int n) {
    int len = 0;

    if (arr[n] == -1)
    {
        if (n == 0)
        {
            arr[n] = 0;
            return arr[n];
        }
        else if (n == 1)
        {
            arr[n] = 4;
            return arr[n];
        }
        else if (n == 2)
        {
            arr[n] = 6;
            return arr[n];
        }
        else
            return arr[n] = (solution_songdong(n - 1) + solution_songdong(n - 2));
    }
    else
        return arr[n];
}

long long solution(int N) {
    long long answer = 0;
    long long temp;
    long long arr[81];
    clock_t start, end;
    double duration = 0;
    start = clock();
    arr[0] = 1;
    arr[1] = 1;

    for(long long i=2; i<N; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];

    }
    answer = arr[N-1]*2 + (arr[N-1]+arr[N-2])*2;

    end = clock();
    duration = (double)(end-start)/CLOCKS_PER_SEC;

    printf("%0.20lf\n", (double)(end-start)/CLOCKS_PER_SEC);

    return answer;
}

int main() {
    clock_t start, end;
    double duration = 0;
    start = clock();
    solution_songdong(6);
    end = clock();
    printf("%0.20lf\n", (double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}