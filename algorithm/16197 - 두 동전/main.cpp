#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef pair<int, int> pii;

int n, m;
char map[25][25];
vector<pii> dvetor = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

typedef struct coord {
    int y, x;
} coord;
vector<coord> coins;

int bfs();

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
        char item; cin >> item;
        if (item == 'o') coins.push_back({i, j});
        map[i][j] = (item == 'o') ? '.' : item;
    }

    cout << bfs() << "\n";

    return 0;
}

bool isValid(int y, int x) {
    return (0 <= y && y < n && 0 <= x && x < m);
}

int bfs() {
    bool visited[20][20][20][20];
    queue<tuple<coord, coord, int>> q;

    q.push({coins[0], coins[1], 0});
    visited[coins[0].y][coins[0].x][coins[1].y][coins[1].x] = true;

    while (q.size() > 0) {
        tuple<coord, coord, int> coin = q.front(); q.pop();

        if (get<2>(coin) > 10) return -1;

        for (pii dydx : dvetor) {
            coord coinA = {get<0>(coin).y + dydx.first, get<0>(coin).x + dydx.second};
            coord coinB = {get<1>(coin).y + dydx.first, get<1>(coin).x + dydx.second};
            int cnt = get<2>(coin) + 1;

            bool validA = isValid(coinA.y, coinA.x);
            bool validB = isValid(coinB.y, coinB.x);

            // 이미 방문한 경우 -> continue
            if (visited[coinA.y][coinA.x][coinB.y][coinB.x]) continue;

            // 동전 둘 다 떨어지는 경우 -> continue
            if (!validA && !validB) continue;

            // 벽에 부딪힌 경우 각각 갱신
            if (map[coinA.y][coinA.x] == '#') {
                coinA.y = get<0>(coin).y;
                coinA.x = get<0>(coin).x;
            }
            if (map[coinB.y][coinB.x] == '#') {
                coinB.y = get<1>(coin).y;
                coinB.x = get<1>(coin).x;
            }
            
            // 동전 하나만 떨어지는 경우
            if ((validA && !validB) || (!validA && validB)) {
                if (get<2>(coin) + 1 > 10) return -1;
                return cnt;
            }

            visited[coinA.y][coinA.x][coinB.y][coinB.x] = true;
            q.push({coinA, coinB, cnt});
        }
    }
    return -1;
}