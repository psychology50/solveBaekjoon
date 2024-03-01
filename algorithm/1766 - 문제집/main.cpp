#include <bits/stdc++.h>

#define MAX 32010

using namespace std;
int n, m;
int adj[MAX];
vector<int> graph[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    int u, v;
    for (int i=0; i<m; ++i) {
        cin >> u >> v; graph[u].push_back(v);
        ++adj[v];
    }

    priority_queue<int, vector<int>, greater<>> pq;
    for (int i=1; i<=n; ++i) {
        if (adj[i] == 0) pq.push(i);
    }

    vector<int> res;
    while (!pq.empty()) {
        int cur = pq.top(); pq.pop();
        res.push_back(cur);

        for (int& nxt : graph[cur]) {
            if (--adj[nxt] == 0) pq.push(nxt);
        }
    }

    for (int& r : res) {
        cout << r << " ";
    }

    return 0;
}