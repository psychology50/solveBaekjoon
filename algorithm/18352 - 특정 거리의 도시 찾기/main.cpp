#include <iostream>
#include <vector>
#include <queue>

#define MAX 300001
#define INF 987654321

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int n, m, k, x;
vi graph[MAX];
int dist[MAX];

void dijkstra() {
    priority_queue<pii> pq; pq.push({0, x});

    while (!pq.empty()) {
        int cost = pq.top().first, cur = pq.top().second; pq.pop();
        if (cost > dist[cur]) continue;

        for (int i=0; i<graph[cur].size(); ++i) {
            int nxt = graph[cur][i];
            if (cost + 1 < dist[nxt]) {
                dist[nxt] = cost + 1; pq.push({dist[nxt], nxt});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> x;
    for (int i=0; i<m; ++i) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
    }
    for (int i=1; i<=n; ++i) dist[i] = INF;
    dijkstra();

    bool flag = false;
    for (int i=1; i<=n; ++i) {
        if (dist[i] == k) {
            cout << i << "\n";
            flag = true;
        }
    }
    if (!flag) cout << -1 << "\n";

    return 0;
}