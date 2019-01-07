//
// Created by 조민국 on 07/01/2019.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include <queue>
//#include <map>

using namespace std;

vector<pair<string,string>> t;
vector<bool> visit;
vector<string> answer;

bool dfs(string start, int count)
{
    answer.push_back(start);
    if(count == t.size())
    {
        return true;
    }

    for(int i=0; i<t.size(); i++)
    {
        if(visit[i] == false && start == t[i].first)
        {
            visit[i] = true;
            if(dfs(t[i].second,count+1))
            {
                return true;
            }
            visit[i] = false;
        }
    }

    answer.pop_back();

    return false;

}


vector<string> solution(vector<vector<string>> tickets) {

    visit.resize(tickets.size(), false);

    for(int i=0; i<tickets.size(); i++)
    {
        string first;
        string second;
        first = tickets[i][0];
        second = tickets[i][1];
        t.push_back(make_pair(first,second));
    }
    sort(t.begin(),t.end());

//    queue<pair<string,string>> q;
//    map<pair<string,string>,int> check;
//    for(int i=0; i<t.size(); i++)
//    {
//        check[t[i]] = 1;
//    }

//    q.push(t[0]);
//    while(!q.empty())
//    {
//        pair<string,string> data = q.front();
//        q.pop();
//
//        for(int i=0; i<t.size(); i++)
//        {
//            if( (data.second == t[i].first) && (check[t[i]] == 1) )
//            {
//                check[data] = -1;
//                answer.push_back(data.first);
//                q.push(t[i]);
//                break;
//            }
//        }
//    }

    dfs("ICN",0);


    return answer;
}

int main()
{
    vector<vector<string>> tickets;
    vector<string> ticket;
    ticket.push_back("ICN");
    ticket.push_back("SFO");
    tickets.push_back(ticket);
    vector<string> ticket2;
    ticket2.push_back("ICN");
    ticket2.push_back("ATL");
    tickets.push_back(ticket2);
    vector<string> ticket3;
    ticket3.push_back("SFO");
    ticket3.push_back("ATL");
    tickets.push_back(ticket3);
    vector<string> ticket4;
    ticket4.push_back("ATL");
    ticket4.push_back("ICN");
    tickets.push_back(ticket4);
    vector<string> ticket5;
    ticket5.push_back("ATL");
    ticket5.push_back("SFO");
    tickets.push_back(ticket5);

//    vector<string> ticket;
//    ticket.push_back("ICN");
//    ticket.push_back("ATL");
//    tickets.push_back(ticket);
//    vector<string> ticket2;
//    ticket2.push_back("ICN");
//    ticket2.push_back("SFO");
//    tickets.push_back(ticket2);
//    vector<string> ticket3;
//    ticket3.push_back("SFO");
//    ticket3.push_back("ICN");
//    tickets.push_back(ticket3);
    solution(tickets);

    return 0;
}