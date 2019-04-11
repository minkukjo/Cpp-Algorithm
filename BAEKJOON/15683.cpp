//
// Created by 조민국 on 2019-04-11.
//

#include <iostream>
#include <vector>

using namespace std;

char map[9][9];

int N, M;

int bs = 99999;

class camera
{
public:
    int x;
    int y;
    char t;
    camera(int a,int b, char c):x(a),y(b),t(c){};
};

vector<camera> v;

void up(int x,int y,char temp[][9])
{

    for(int i=x-1; i>=0; i--)
    {
        if(temp[i][y] == '6')
        {
            return;
        }
        else if(temp[i][y] == '0')
        {
            temp[i][y] = '#';
        }
    }
}

void left(int x,int y,char temp[][9])
{

    for(int i=y-1; i>=0; i--)
    {
        if(temp[x][i] == '6')
        {
            return;
        }
        else if(temp[x][i] == '0')
        {
            temp[x][i] = '#';
        }
    }
}

void right(int x,int y,char temp[][9])
{

    for(int i=y+1; i<M; i++)
    {
        if(temp[x][i] == '6')
        {
            return;
        }
        else if(temp[x][i] == '0')
        {
            temp[x][i] = '#';
        }
    }
}

void down(int x, int y,char temp[][9])
{

    for(int i=x+1; i<N; i++)
    {
        if(temp[i][y] == '6')
        {
            return;
        }
        else if(temp[i][y] == '0')
        {
            temp[i][y] = '#';
        }
    }
}

void print(char m[][9])
{
    cout << endl;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int count(char temp[][9])
{
    int zero = 0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(temp[i][j] == '0')
            {
                zero++;
            }
        }
    }
    return zero;
}

void copy(char a[][9], char b[][9])
{

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            b[i][j] = a[i][j];
        }
    }


}


void dfs(int n,char prev[][9])
{
    char temp[9][9];

    if(n == v.size())
    {
        int k;
        k = count(prev);
        bs = min(bs,k);

        return;
    }

    //print(prev);



    if(v[n].t == '1')
    {
        copy(prev,temp);
        up(v[n].x,v[n].y,temp);
        dfs(n+1,temp);

        copy(prev,temp);
        down(v[n].x,v[n].y,temp);
        dfs(n+1,temp);

        copy(prev,temp);
        left(v[n].x,v[n].y,temp);
        dfs(n+1,temp);

        copy(prev,temp);
        right(v[n].x,v[n].y,temp);
        dfs(n+1,temp);
    }
    else if(v[n].t == '2')
    {
        copy(prev,temp);
        up(v[n].x,v[n].y,temp);
        down(v[n].x,v[n].y,temp);
        dfs(n+1,temp);

        copy(prev,temp);
        left(v[n].x,v[n].y,temp);
        right(v[n].x,v[n].y,temp);
        dfs(n+1,temp);

    }
    else if(v[n].t == '3')
    {
        copy(prev,temp);
        up(v[n].x,v[n].y,temp);
        right(v[n].x,v[n].y,temp);
        dfs(n+1,temp);

        copy(prev,temp);
        up(v[n].x,v[n].y,temp);
        left(v[n].x,v[n].y,temp);
        dfs(n+1,temp);

        copy(prev,temp);
        down(v[n].x,v[n].y,temp);
        left(v[n].x,v[n].y,temp);
        dfs(n+1,temp);

        copy(prev,temp);
        down(v[n].x,v[n].y,temp);
        right(v[n].x,v[n].y,temp);
        dfs(n+1,temp);
    }
    else if(v[n].t == '4')
    {
        copy(prev,temp);
        up(v[n].x,v[n].y,temp);
        right(v[n].x,v[n].y,temp);
        left(v[n].x,v[n].y,temp);
        dfs(n+1,temp);

        copy(prev,temp);
        up(v[n].x,v[n].y,temp);
        down(v[n].x,v[n].y,temp);
        left(v[n].x,v[n].y,temp);
        dfs(n+1,temp);

        copy(prev,temp);
        up(v[n].x,v[n].y,temp);
        right(v[n].x,v[n].y,temp);
        down(v[n].x,v[n].y,temp);
        dfs(n+1,temp);

        copy(prev,temp);
        down(v[n].x,v[n].y,temp);
        right(v[n].x,v[n].y,temp);
        left(v[n].x,v[n].y,temp);
        dfs(n+1,temp);
    }
    else if(v[n].t == '5')
    {
        copy(prev,temp);
        up(v[n].x,v[n].y,temp);
        right(v[n].x,v[n].y,temp);
        left(v[n].x,v[n].y,temp);
        down(v[n].x,v[n].y,temp);
        dfs(n+1,temp);

    }


}





int main()
{

    cin >> N >> M;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == '1' ||map[i][j] == '2'|| map[i][j] == '3' || map[i][j] == '4'||map[i][j] == '5')
            {
                v.push_back(camera(i,j,map[i][j]));
            }
        }
    }



    dfs(0,map);


    cout << bs << endl;



    return 0;
}