#include <bits/stdc++.h>

#define MAX 11

using namespace std;

int n, m;
string board[MAX];
int ret = MAX;
int dydx[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Pos {
    int x, y;
};
Pos red, blue;
using tppi = tuple<Pos, Pos, int>;

void input() {
    for (int i=0; i<n; ++i) {
        cin >> board[i];

        for (int j=0; j<m; ++j) {
            if (board[i][j] == 'R') {
                board[i][j] = '.';
                red.y = i, red.x = j;
            } else if (board[i][j] == 'B') {
                board[i][j] = '.';
                blue.y = i, blue.x = j;
            }
        }
    }
}

bool isValid(Pos& p) {
    return (0 <= p.x && p.x < n && 0 <= p.y && p.y < m);
}

void move(int& y, int& x, int d) {
    while (1) {
        y += dydx[d][0], x += dydx[d][1];
        if (board[y][x] == '#') {
            y -= dydx[d][0], x -= dydx[d][1];
            break;
        } else if (board[y][x] == 'O') break;
    }
}

void bfs() {
    queue<tppi> q; q.push({red, blue, 0});
    bool visited[MAX][MAX][MAX][MAX]; memset(visited, 0, sizeof(visited));
    visited[red.y][red.x][blue.y][blue.x] = true;

    while (!q.empty()) {
        tppi cur = q.front(); q.pop();
        Pos& red = get<0>(cur), blue = get<1>(cur);
        int& cnt = get<2>(cur);

        if (cnt > 10) break;
        if (board[red.y][red.x] == 'O') {ret = cnt; break;}

        for (int i=0; i<4; ++i) {
            move(red.y, red.x, i), move(blue.y, blue.x, i);

            if (board[blue.y][blue.x] == 'O') continue;

            if (red.y == blue.y && red.x == blue.x) {
                if (i == 0) {
                    red.y < blue.y ? ++blue.y : --red.y;
                } else if (i == 1) {
                    red.y < blue.y ? ++blue.y : --red.y;
                } else if (i == 2) {
                    red.x < blue.x ? ++blue.x : ++red.x;
                } else {
                    red.x < blue.x ? --red.x : --blue.x;
                }
            }

            if (!visited[red.y][red.x][blue.y][blue.x]) {
                q.push({red, blue, cnt+1});
                visited[red.y][red.x][blue.y][blue.x] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    input();

    bfs();

    cout << ((ret >= MAX) ? -1 : ret);

    return 0;
}