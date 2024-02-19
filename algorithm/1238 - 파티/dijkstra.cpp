#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 1e9
#define MAX 1001

using namespace std;
using pii = pair<int, int>;

int n, m, target;
vector<pii> graph[MAX];
int come[MAX], dist[MAX];

void dijkstra(int start) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start}); dist[start] = 0;

    while (!pq.empty()) {
        int now = pq.top().second, w = pq.top().first; pq.pop();
        if (w > dist[now]) continue;

        for (pii node : graph[now]) {
            int nxt = node.first, cost = node.second + w;
            if (cost < dist[nxt]) {
                dist[nxt] = cost; pq.push({dist[nxt], nxt});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> target;
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    for (int i=1; i<=n; ++i) dist[i] = INF;
    dijkstra(target);
    for (int i=1; i<=n; ++i) come[i] = dist[i];

    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == target) continue;
        for (int i=1; i<=n; ++i) dist[i] = INF;
        dijkstra(i);
        ret = max(ret, dist[target] + come[i]);
    }
    cout << ret;

    return 0;
}