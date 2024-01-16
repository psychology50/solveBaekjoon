#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int m, n, k;

typedef struct node {
    int y, x;
} node;
int map[100][100];
vector<int> res;
int dydx[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(int startY, int startX) {
    queue<node> q; q.push({startY, startX});
    int size = 0;

    while (!q.empty()) {
        node now = q.front(); q.pop();

        if ((0 <= now.y && now.y < m) && (0 <= now.x && now.x < n) && (map[now.y][now.x] == 0)) {
            map[now.y][now.x] = 1;
            ++size;

            for (int i=0; i<4; ++i) {
                int nxtY = now.y + dydx[i][0];
                int nxtX = now.x + dydx[i][1];

                q.push({nxtY, nxtX});
            }
        }
    }
    res.push_back(size);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> n >> k;
    for (int i = 0; i < k; ++i) {
        int ly, lx, ry, rx; cin >> lx >> ly >> rx >> ry;
        for (int row=ly; row<ry; ++row) for (int col=lx; col<rx; ++col) {
            map[row][col] = 1;
        }
    }

    for (int y=0; y<m; ++y) for (int x=0; x<n; ++x) {
        if (map[y][x]) continue;
        bfs(y, x);
    }

    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for (int& r : res) cout << r << " ";

    return 0;
}