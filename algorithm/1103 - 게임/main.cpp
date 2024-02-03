#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

#define MAX 51

using namespace std;
using pii = pair<int, int>;

int n, m;
char map[MAX][MAX];
int dydx[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int cache[MAX][MAX];
bool visited[MAX][MAX];
vector<int> res;

bool isValid(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m && map[y][x] != 'H';
}

int dfs(int y, int x) {
    if (!isValid(y, x)) return 0;
    if (visited[y][x]) {cout << -1; exit(0);}

    int& ret = cache[y][x];
    if (ret != -1) return ret;

    visited[y][x] = true;
    ret = 0;

    int cnt = map[y][x] - '0';
    for (int dir=0; dir<4; ++dir) {
        int ny = y + dydx[dir][0] * cnt, nx = x + dydx[dir][1] * cnt;
        ret = max(ret, dfs(ny, nx) + 1);
    }
    visited[y][x] = false;
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    memset(cache, -1, sizeof(cache));

    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> map[i][j];

    cout << dfs(0, 0);

    return 0;
}