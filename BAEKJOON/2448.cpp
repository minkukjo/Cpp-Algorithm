//
// Created by 조민국 on 2019-01-17.
//

#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N / 3; i++) {
        for (int j = i; j < N; j++) {
            cout << " ";
        }

        cout << "*" << endl;

        for (int j = i; j < N - 1; j++) {
            cout << " ";
        }
        cout << "*" << " " << "*" << endl;

        for (int j = i; j < N - 2; j++) {
            cout << " ";
        }

        for (int j = i; j < 5; j++) {
            cout << "*";
        }
        cout << endl;




    }
    return 0;
}