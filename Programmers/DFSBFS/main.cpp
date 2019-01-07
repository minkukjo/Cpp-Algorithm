#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;


int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int is_answer = 0;
    for(auto iter=words.begin(); iter!=words.end(); ++iter)
    {
        if( target == *iter )
        {
            is_answer++;
        }
    }
    if(is_answer == 0 )
    {
        return 0;
    }

    map<string,int> cost;

    queue<string> q;
    q.push(begin);

    for(int i =0; i<words.size();i++)
    {
        cost[words[i]] = 99999;
    }

    cost[begin] = 0;

    while(q.size() != 0)
    {
        string search = q.front();
        q.pop();

        for(int i=0;i<words.size(); i++)
        {
            if(words[i] != search)
            {
                bool isfind = true;
                int count=0;
                for(int j=0; j<begin.size(); j++)
                {
                    if(words[i][j] != search[j])
                    {
                        count++;
                    }
                    if(count >1)
                    {
                        isfind=false;
                        break;
                    }
                }
                if(isfind&&cost[search]+1 < cost[words[i]])
                {
                    cost[words[i]] = cost[search]+1;
                    q.push(words[i]);
                }
            }

        }
    }

    answer = cost[target];



    return answer;
}

int main()
{
    vector<string> words;
    words.push_back("hot");
    words.push_back("dot");
    words.push_back("dog");
    words.push_back("lot");
    words.push_back("log");
    words.push_back("cog");

    string begin = "hit";
    string target = "cog";
    solution(begin,target,words);

    return 0;
}

//
//vector<int> path[100];
//int words_size;
//int route_value=99999999;
//
//void bfs(int start, vector<int> graph[], bool check[]){
//    queue<int> q;
//
//
//
//    q.push(start);
//    check[start] = true;
//
//    while(!q.empty()){
//        int tmp = q.front();
//        q.pop();
//        cout << tmp << endl;
//        for(int i=0; i<graph[tmp].size(); i++){
//            // 방문하지 않았다면
//            if(check[graph[tmp][i]] == false){
//                // 큐에 넣어주고 방문했음을 표시한다.
//                q.push(graph[tmp][i]);
//                check[graph[tmp][i]] = true;
//                path[tmp].push_back(graph[tmp][i]);
//            }
//        }
//    }
//}
//
//void dfs(int start, vector<int> graph[], bool check[], int count){
//    check[start]= true;
//
//    if(start == words_size)
//    {
//        if(route_value > count)
//        {
//            route_value = count;
//        }
//    }
//
//    for(int i=0; i < graph[start].size(); i++){
//        int next = graph[start][i];
//        // 방문하지 않았다면
//        if(check[next]==false){
//            // 재귀함수를 호출한다.
//            dfs(next, graph, check,count+1);
//        }
//    }
//}
//
//
//
//bool iswords(string target, vector<string> words)
//{
//    for(int i=0; i<words.size(); i++)
//    {
//        if(words[i] == target )
//        {
//            return true;
//        }
//    }
//    return false;
//}
//
//int solution(string begin, string target, vector<string> words) {
//    int answer = 0;
//    bool check [100+1];
//    fill(check, check+100+1, false);
//
//    bool check2 [100+1];
//    fill(check2, check2+100+1, false);
//
//    if ( !iswords(target,words) )
//    {
//        return answer;
//    }
//
//    vector<int> graph[100];
//    words_size = words.size();
//
//    words.insert(words.begin(),begin);
//
//
//    for(int i=0; i<words.size(); i++)
//    {
//        for(int j=0; j<words.size(); j++)
//        {
//            int counter = 0;
//            for(int k=0; k<begin.length(); k++)
//            {
//                if( ( words[i].at(k) != words[j].at(k) ) && i != j)
//                {
//                    counter++;
//                }
//            }
//            if(counter == 1)
//            {
//                graph[i].push_back(j);
//            }
//        }
//    }
//
//    bfs(0,graph,check);
//
//    dfs(0,path,check2,0);
//
//    cout << route_value << endl;
//
//    answer = route_value;
//
//    return answer;
//}
//
//int main()
//{
//    vector<string> words;
//    words.push_back("hot");
//    words.push_back("dot");
//    words.push_back("dog");
//    words.push_back("lot");
//    words.push_back("log");
//    words.push_back("cog");
//
//    string begin = "hit";
//    string target = "cog";
//    solution(begin,target,words);
//
//    return 0;
//}



//bool check [100+1];
//
//bool dfs(int start, vector<int> graph[], bool check[]){
//    check[start]= true;
//    printf("%d ", start);
//    bool isExist = false;
//
//    for(int i=0; i < graph[start].size(); i++){
//        int next = graph[start][i];
//
//        // 방문하지 않았다면
//        if(check[next]==false){
//            // 재귀함수를 호출한다.
//            dfs(next, graph, check);
//            isExist = true;
//        }
//    }
//
//    return isExist;
//}
//
//
//
//int solution(int n, vector<vector<int>> computers) {
//    int answer = 0;
//    map<int, int> m;
//    vector<int> graph[100];
//
//    fill(check, check+n+1, false);
//
//    for(int i=0; i<n; i++)
//    {
//        vector<int> add;
//
//        for(int j=0; j<n; j++)
//        {
//            if(computers[i][j] == 1 && i != j)
//            {
//                m[j]++;
//
//                graph[i+1].push_back(j+1);
//            }
//        }
//    }
//
//
//    for(int i=1; i<=n; i++){
//        sort(graph[i].begin(), graph[i].end());
//    }
//
//    for(int i=1; i<=n; i++){
//        answer += dfs(i,graph,check);
//    }
//
//    for(int i=0; i<n; i++)
//    {
//        if(m[i] == 0)
//        {
//            answer++;
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//    int n = 6;
//    vector<vector<int>> computers(
//            {
//                vector<int> ( { 1,0,1,0,0,0}),
//                vector<int> ( { 0,1,0,1,0,0}),
//                vector<int> ( { 1,0,1,0,0,0}),
//                vector<int> ( { 0,1,0,1,1,0}),
//                vector<int> ( { 0,0,0,1,1,0}),
//                vector<int> ( { 0,0,0,0,0,1}),
//                }
//            );
//
////    vector<vector<int>> computers(
////            {
////                vector<int> ( { 1,1,0,0}),
////                vector<int> ( { 1,1,0,0}),
////                vector<int> ( { 0,0,1,1}),
////                vector<int> ( { 0,0,1,1}),
////                }
////            );
//
//
//    solution(n,computers);
//
//
//    return 0;
//}


//int answer = 0;
//
//void num_make(vector<int> numbers, int index, int target)
//{
//    if(index < numbers.size())
//    {
//        numbers[index] *=1;
//        num_make(numbers,index+1,target);
//
//        numbers[index] *= -1;
//        num_make(numbers,index+1,target);
//    }
//    else
//    {
//        int sum=0;
//        for(int i=0; i<numbers.size(); i++)
//        {
//            sum+=numbers[i];
//        }
//        if(sum == target)
//        {
//            answer++;
//        }
//    }
//}
//
//int solution(vector<int> numbers, int target) {
//
//    num_make(numbers,0,target);
//
//    return answer;
//}


// 시간 초과
//int solution(vector<int> numbers, int target) {
//
//    int answer =0;
//    for(int i=0; i<numbers.size(); i++)
//    {
//        vector<int> temp = numbers;
//
//        for(int k=0; k<=i; k++)
//        {
//            int change;
//            change = temp[k];
//            temp[k] = -change;
//        }
//
//        do{
//            int sum =0;
//            for(int j=0; j<temp.size(); j++)
//            {
//                sum += temp[j];
//            }
//
//            if(sum == target)
//            {
//                answer++;
//            }
//        }while(next_permutation(temp.begin(),temp.end()));
//
//    }
//
//    return answer;
//}

//int main()
//{
//    vector<int> numbers;
//    int target = 3;
//    int ans;
//    numbers.push_back(1);
//    numbers.push_back(1);
//    numbers.push_back(1);
//    numbers.push_back(1);
//    numbers.push_back(1);
//    ans = solution(numbers,target);
//    cout << ans << endl;
//    return 0;
//}