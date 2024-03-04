#include <bits/stdc++.h>

#define MAX 32001

using namespace std;
int n, m;
vector<int> ret;

int adj[MAX];
vector<int> graph[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        ++adj[v];
    }

    priority_queue<int> pq;
    for (int i=1; i<=n; ++i) if (adj[i] == 0) pq.push(i);

    while (!pq.empty()) {
        int cur = pq.top(); pq.pop();
        ret.push_back(cur);

        for (int& nxt: graph[cur]) {
            if (--adj[nxt] == 0) pq.push(nxt);
        }
    } 

    for (int& r: ret) {
        cout << r << " ";
    }

    return 0;
}