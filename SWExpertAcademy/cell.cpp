//
// Created by 조민국 on 2019-03-14.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class cell
{
public:
    bool activate;
    int HP;
};

int middle = 500;

int main()
{
    string input;
    int t;
    ifstream in("sample_input.txt");

    if(in.is_open())
    {
        cout << "열림" << endl;
    }

    in >> input;
    t = stoi(input);


    while(t--)
    {
        int N,M,K;
        cell cell[1001][1001];

        in >> N >> M >> K;

        for(int i=middle; i<middle+N;i++)
        {
            for(int j=middle; j<middle+M; j++)
            {
                int temp;
                in >> temp;
                cell[i][j].HP = temp;
            }
        }


        for(int i=middle; i<middle+N;i++)
        {
            for(int j=middle; j<middle+M; j++)
            {
                cout << cell[i][j].HP << " ";
            }
            cout << endl;
        }



    }

    return 0;
}
