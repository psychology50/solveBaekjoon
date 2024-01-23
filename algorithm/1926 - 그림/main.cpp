#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
int n, m;
int map[500][500];
int dydx[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<int> res;

void bfs(int startY, int startX) {
    queue<pii> q; q.push({startY, startX});

    int cnt = 0;
    while (!q.empty()) {
        pii now = q.front(); q.pop();

        if (map[now.first][now.second] == 0) continue;
        map[now.first][now.second] = 0;
        ++cnt;

        for (int i=0; i<4; ++i) {
            int ny = now.first + dydx[i][0];
            int nx = now.second + dydx[i][1];

            if (!(0 <= ny && ny < n && 0 <= nx && nx < m && map[ny][nx] == 1)) continue;

            q.push({ny, nx});
        }
    }
    res.push_back(cnt);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> map[i][j];

    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        if (map[i][j] == 0) continue; 
        bfs(i, j);
    }

    if (res.size() != 0)
        cout << res.size() << "\n" << *max_element(res.begin(), res.end());
    else cout << 0 << "\n" << 0;
    return 0;
}