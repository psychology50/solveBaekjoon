#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define MAX 10001
#define endl "\n"

using namespace std;
typedef tuple<int, int> tii;

int n, m;
int src, dst;
vector<tii> adj[MAX];
vector<tii> radj[MAX]; // reverse adj
vector<int> indegree(MAX, 0);
vector<int> dist(MAX, 0);

bool chk[MAX] = {false};
int cnt = 0;
void dfs(int now) {
    if (chk[now]) return;
    chk[now] = true;

    for (tii t : radj[now]) {
        int nxt = get<0>(t), cost = get<1>(t);
        if (dist[now] - dist[nxt] == cost) {
            dfs(nxt);
            cnt++;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    // 도시의 개수 n (1 <= n <= 10,000)
    // 도로의 개수 m (1 <= m <= 100,000)
    // 도로의 정보 u, v, c (u에서 v로 가는 비용 c)
    // 1번 도시에서 출발해 도착하는 도시는 몇 개인가?
    // 도착하는 도시들 중 가장 늦게 도착하는 시간은 얼마인가?

    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        adj[u].push_back({v, c});
        radj[v].push_back({u, c});
        indegree[v]++;
    }
    cin >> src >> dst;

    queue<int> q;
    for (int i = 0; i <= n; i++) if (indegree[i] == 0) {q.push(i);}

    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (tii t : adj[now]) {
            int nxt = get<0>(t), cost = get<1>(t);
            if (dist[nxt] < dist[now] + cost) {
                dist[nxt] = dist[now] + cost;
            }
            if (--indegree[nxt] == 0) q.push(nxt);
        }
    }

    dfs(dst);
    cout << dist[dst] << "\n" << cnt << endl;
    return 0;
}