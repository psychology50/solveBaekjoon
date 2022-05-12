#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

#define MAX 501
#define INF 2147483647

using namespace std;
using p = pair<int, int>;

vector<tuple<int, int, int>> graph;
vector<long long> Dist(MAX, INF);

void bellman_ford(int n) {
    Dist[1] = 0;
    for (int i = 1; i <= n-1; i++) {
        for (auto j: graph) {
            int u, v, w;
            u = get<0>(j); v = get<1>(j); w = get<2>(j);

            if (Dist[u] == INF) continue;
            if (Dist[v] > Dist[u] + w) Dist[v] = Dist[u] + w;
        }
    }

    for (auto i: graph) {
        for (auto j: graph) {
            int u, v, w;
            u = get<0>(j); v = get<1>(j); w = get<2>(j);

            if (Dist[u] == INF) continue;
            if (Dist[v] > Dist[u] + w) {
                cout << -1 << "\n";
                return;
            }
        }
    }

    for (int i=2; i <= n; i++) {
        if (Dist[i] == INF) cout << -1 << "\n";
        else cout << Dist[i] << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; cin >> n >> m;

    for (int i=0; i<m; i++) {
        int u,v,w; cin >> u >> v >> w;
        graph.push_back({u, v, w});
    }

    bellman_ford(n);

    return 0;
}