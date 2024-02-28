#include <bits/stdc++.h>

#define MAX 16
#define INF 1e9

using namespace std;
int n, w[MAX][MAX];
int cache[MAX][1 << MAX];

int dfs(int cur, int status) {
    if (status == (1 << n) - 1) return (w[cur][0] != 0) ? w[cur][0] : INF;

    int& ret = cache[cur][status];
    if (ret != -1) return ret;
    ret = INF;

    for (int nxt=0; nxt<n; ++nxt) {
        if (!w[cur][nxt]) continue;
        if ((status & (1 << nxt)) == (1 << nxt)) continue;
        ret = min(ret, w[cur][nxt] + dfs(nxt, status | 1 << nxt));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> w[i][j];
    memset(cache, -1, sizeof(cache));

    cout << dfs(0, 1);
    return 0;
}