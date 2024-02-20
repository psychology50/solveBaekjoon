#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <vector>
#include <set>

#define MAX 1001

using namespace std;
using pii = pair<int, int>;
int n, m;
int map[MAX][MAX], ret[MAX][MAX], sector[MAX][MAX];
bool visited[MAX][MAX];
int dydx[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<int> sectorSize;

void bfs(int y, int x, int sectorNum) {
    queue<pii> q; q.push({y, x});
    int cnt = 1;
    sector[y][x] = sectorNum;
    visited[y][x] = true;

    while (!q.empty()) {
        pii now = q.front(); q.pop();

        for (int i=0; i<4; ++i) {
            int ny = now.first + dydx[i][0], nx = now.second + dydx[i][1];

            if (!(0 <= ny && ny < n && 0 <= nx && nx < m && !visited[ny][nx])) continue;
            if (map[ny][nx] == 1) continue;

            visited[ny][nx] = true;
            sector[ny][nx] = sectorNum;
            ++cnt; q.push({ny, nx});
        }
    }
    sectorSize.push_back(cnt);
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

    int num = 0;
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
        if (map[i][j] == 1 || visited[i][j]) continue;
        bfs(i, j, num);
        ++num;
    }

    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
        int& now = ret[i][j]; 

        if (map[i][j] == 0) continue;
        ++now;

        set<int> idx;
        for (int dir=0; dir<4; ++dir) {
            int ny = i + dydx[dir][0], nx = j + dydx[dir][1];
            if (!(0 <= ny && ny < n && 0 <= nx && nx < m && map[ny][nx] == 0)) continue;

            if (idx.find(sector[ny][nx]) != idx.end()) continue;
            now += sectorSize[sector[ny][nx]];
            idx.insert(sector[ny][nx]);
        }
        now %= 10;
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cout << ret[i][j];
        }
        cout << "\n";
    }
}