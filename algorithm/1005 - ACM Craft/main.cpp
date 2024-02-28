#include <bits/stdc++.h>

#define MAX 1001

using namespace std;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

vector<int> building;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t; ++t;
    int n, k, w;

    while (--t) {
        cin >> n >> k; building.resize(n+1);
        vvi graph(n+1);
        int adj[n+1], cost[n+1], indegree[n+1];
        memset(cost, -1, sizeof(cost));
        memset(adj, 0, sizeof(adj));

        for (int i = 1; i <= n; ++i) cin >> building[i];
        for (int i = 0; i < k; ++i) {
            int u, v; cin >> u >> v;
            graph[u].push_back(v);
            ++adj[v];
        }
        cin >> w;

        queue<int> pq;
        for (int i = 1; i <= n; ++i) if (adj[i] == 0) {
            cost[i] = 0;
            pq.push(i);
        }

        while (!pq.empty()) {
            int cur = pq.front(); pq.pop();

            cost[cur] += building[cur];

            for (int nxt : graph[cur]) {
                cost[nxt] = (cost[nxt] != -1) ? max(cost[nxt], cost[cur]) : cost[cur];
                if (--adj[nxt] == 0) {
                    pq.push(nxt);
                }
            }
        }
        cout << cost[w] << "\n";
    }

    return 0;
}