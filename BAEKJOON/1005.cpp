#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 내가 짠거 아님

int main(){
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        // pre: 선행자의 개수, suc: 후행자의 목록
        int N, K, W, time[1000], pre[1000] = {0};
        vector<int> suc[1000];
        scanf("%d %d", &N, &K);
        for(int i=0; i<N; i++)
            scanf("%d", time+i);
        for(int i=0; i<K; i++){
            int X, Y;
            scanf("%d %d", &X, &Y);
            suc[X-1].push_back(Y-1);
            pre[Y-1]++;
        }
        scanf("%d", &W);
        W--;

        // result: 해당 건물을 짓기 시작하는 데 걸리는 최소 시간
        int result[1000] = {0};
        queue<int> Q;
        // 선행자가 하나도 없는 노드들을 먼저 큐에 push
        for(int i=0; i<N; i++)
            if(!pre[i]) Q.push(i);

        // W번 건물의 선행자가 하나도 없을 때까지(더 갱신될 여지가 없음)
        while(pre[W] > 0){
            int u = Q.front();
            Q.pop();
            // 모든 후행자 건물의 최소 건설시작시간을 갱신
            for(int next: suc[u]){
                result[next] = max(result[next], result[u]+time[u]);
                if(--pre[next] == 0) Q.push(next);
            }
        }
        // 목표 건물을 짓는 데 걸리는 시간도 더해야 함
        printf("%d\n", result[W]+time[W]);
    }
}