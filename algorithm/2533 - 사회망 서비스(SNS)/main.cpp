#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<vector<int>> graph;
int cache[1000001][2];

int dp(int cur, int pre, int flag) {
    if (cache[cur][flag] != -1) return cache[cur][flag];

    int sum = 0;
    for (int idx=0; idx < graph[cur].size(); idx++) {
        int nxt = graph[cur][idx];
        if (nxt == pre) continue;
        sum += (flag) ? min(dp(nxt, cur, 0), dp(nxt, cur, 1)) : dp(nxt, cur, 1);
    }
    return cache[cur][flag] = (flag) ? sum+1 : sum;
}

int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // minimum vertex cover -> bipartite matching?
    // Ford-Fulkerson: O((|E|+|V|) * F) -> TIME OVER (because 2<=N<=1,000,000)
    // how resolve? dynamic programing, how many early adaptor?
    // cache[cur][flag] = num of cases

    // (1) root node is early adaptor?
    //     - true: dp(1, 0, 1) -> num of child nodes have early adpator + 1
    //     - false: dp(1, 0, 0) -> num of child nodes have early adpator

    // (2) rule : cache[cur][now][0] = cache[nxt][cur][1] (내가 얼리어댑터가 아니면 인접 노드는 얼리어댑터여야 한다.)
    //            cache[cur][pre][1] = min(cache[nxt][cur][0], cache[nxt][cur][1]) (내가 얼리어댐터라면 인접 노드는 얼리어댑터여도 되고 아니어도 된다.)

    int n; cin >> n;
    graph.resize(n+1);
    memset(cache, -1, sizeof(cache)); // notion! glabal array initialize 

    for (int i=0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << min(dp(1, 0, 1), dp(1, 0, 0)) << "\n";

    return 0;
}