/**
 * 지능 이슈로 인한 문제 풀이 참고...슬프다.
 * 
 * @link https://nahwasa.com/entry/%EC%9E%90%EB%B0%94-%EB%B0%B1%EC%A4%80-22949-%ED%9A%8C%EC%A0%84-%EB%AF%B8%EB%A1%9C-%ED%83%90%EC%83%89-java
 */
#include <iostream>
#include <string>
#include <queue>
#include <cstring>

#define MAX 1000

using namespace std;
using pii = pair<int, int>;
typedef struct Pos {
    int y, x , d, dist;
} Pos;

int k;
Pos start;
char map[4][MAX][MAX];
int dydx[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int getDivision(const int& y, const int& x) {
    if (y < 0 || x < 0 || y >= 4*k || x >= 4*k) return -1;
    return y/4*4 + x/4;
}

pii getRotatePos(int y, int x) {
    int originY = y/4*4, originX = x/4*4;
    y %= 4, x %= 4;
    return {originY+x, originX+3-y};
}

void bfs() {
    bool visited[4][4*k][4*k];
    memset(visited, false, sizeof(visited));

    queue<Pos> q; q.push(start);
    visited[0][start.y][start.x] = true;

    while (!q.empty()) {
        Pos cur = q.front(); q.pop();
        if (map[cur.d][cur.y][cur.x] == 'E') {
            cout << cur.dist; return;
        }

        int division = getDivision(cur.y, cur.x);
        for (int dir=0; dir<5; ++dir) {
            int ny = cur.y + dydx[dir][0], nx = cur.x + dydx[dir][1];
            int nxtDivision = getDivision(ny, nx);

            if (nxtDivision == -1) continue;
            int nd = (division == nxtDivision) ? (cur.d+1)%4 : 1;
            pii nxt = getRotatePos(ny, nx);
            ny = nxt.first, nx = nxt.second;

            if (visited[nd][ny][nx] || map[nd][ny][nx] == '#') continue;
            visited[nd][ny][nx] = true;
            q.push({ny, nx, nd, cur.dist+1});
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> k;
    for (int i=0; i<4*k; ++i) {
        string line; cin >> line;
        char c;
        for (int j=0; j<4*k; ++j) {
            c = line[j];
            map[0][i][j] = c;

            if (c=='S') start = {i, j, 0, 0};

            int tmpY = i, tmpX = j;
            for (int rotate=1; rotate <=3; ++rotate) {
                pii nxt = getRotatePos(tmpY, tmpX);
                tmpY = nxt.first, tmpX = nxt.second;
                map[rotate][tmpY][tmpX] = c;
            }
        }
    }
    bfs();

    return 0;
}