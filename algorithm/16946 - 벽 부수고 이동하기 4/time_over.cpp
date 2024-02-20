#include <iostream>
#include <queue>
#include <string>
#include <cstring>

#define MAX 1001

using namespace std;
using pii = pair<int, int>;
int n, m;
int map[MAX][MAX];
int ret[MAX][MAX];
int dydx[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(int y, int x) {
    queue<pii> q; q.push({y, x});
    map[y][x] = 0;

    bool visited[MAX][MAX];
    memset(visited, false, sizeof(visited));
    visited[y][x] = true;

    int cnt = 1;
    while (!q.empty()) {
        pii now = q.front(); q.pop();

        for (int i=0; i<4; ++i) {
            int ny = now.first + dydx[i][0], nx = now.second + dydx[i][1];

            if (!(0 <= ny && ny < n && 0 <= nx && nx < m && !visited[ny][nx])) continue;
            if (map[ny][nx] == 1) continue;

            visited[ny][nx] = true;
            ++cnt; q.push({ny, nx});
        }
    }
    ret[y][x] = cnt % 10; map[y][x] = 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        string tmp; cin >> tmp;
        for (int j=0; j<m; ++j) {
            map[i][j] = tmp[j] - '0';
        }
    }

    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
        if (map[i][j] == 0) {ret[i][j] = 0; continue;}
        bfs(i, j);
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cout << ret[i][j];
        }
        cout << "\n";
    }

    return 0;
}