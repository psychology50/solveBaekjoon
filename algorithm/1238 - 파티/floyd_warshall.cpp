#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;
using pii = pair<int, int>;

int n, m, target;
vector<pii> graph;
int cache[1001][1001];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> target;
    for (int i=1; i<=n; ++i) for (int j=1; j<=m; ++j) {
        if (i == j) continue;
        cache[i][j] = INF;
    }

    for (int i=0; i<m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        cache[u][v] = w;
    }

    for (int k=1; k<=n; ++k) for (int u=1; u<=n; ++u) {
        if (cache[u][k] == INF) continue; 
        for (int v=1; v<=n; ++v) {
            cache[u][v] = min(cache[u][v], cache[u][k] + cache[k][v]);
        }
    }
  
    int ret = 0;
    for (int i=1; i<=n; ++i) ret = max(ret, cache[i][target] + cache[target][i]);
    cout << ret;

    return 0;
}