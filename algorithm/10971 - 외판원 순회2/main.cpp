#include <iostream>
#include <cmath>

#define MAX 987654321

using namespace std;
int n;
int w[11][11];
int res[10];
bool visited[11];

void dfs(int start, int now, int cnt, int depth) {
    visited[now] = true;

    if (depth == n-1) {
        if (w[now][start] == 0) return;
        res[start] = min(res[start], cnt + w[now][start]);
        return;
    } 

    for (int i=0; i<n; ++i) {
        if (w[now][i] == 0 || visited[i]) continue;
        dfs(start, i, cnt + w[now][i], depth+1);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) cin >> w[i][j];
    
    for (int i=0; i<n; ++i) {
        res[i] = MAX;
        dfs(i, i, 0, 0);
        visited[i] = false;
    }

    int ans = MAX;
    for (int i=0; i<n; ++i) {
        ans = min(ans, res[i]);
        visited[i] = false;
    }
    cout << ans;

    return 0;
}