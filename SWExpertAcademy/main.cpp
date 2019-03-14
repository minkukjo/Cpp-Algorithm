#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> a = {9,1,5,10,3};
    int count = 0;
    for (int i = 0; i<4; i++){
        for (int j = 0; j<4 - i; j++){
            if (a[j] > a[j + 1])
            {
                int tmp = a[j]; a[j] = a[j + 1]; a[j + 1] = tmp;
                count++;
                cout << count << endl;
            }
        }
    }
    return 0;
}