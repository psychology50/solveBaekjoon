#include <bits/stdc++.h>

using namespace std;

int h, w, ret;
char arr[101][101];
int dydx[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
bool keys[26];
bool visited[101][101];
struct Node {
    int y, x;
};
queue<Node> q;
queue<Node> locked_doors[26];

bool isValid(int y, int x) {
    return 0 <= y && y < h && 0 <= x && x < w && arr[y][x] != '*' && !visited[y][x];
}

void bfs() {
    while (!q.empty()) {
        Node& cur = q.front(); q.pop();

        for (int i=0; i<4; ++i) {
            int ny = cur.y + dydx[i][0], nx = cur.x + dydx[i][1];

            if (!isValid(ny, nx)) continue;
            visited[ny][nx] = true;

            if ('A' <= arr[ny][nx] && arr[ny][nx] <= 'Z') {
                if (keys[arr[ny][nx] - 'A']) q.push({ny, nx});
                else locked_doors[arr[ny][nx] - 'A'].push({ny, nx});
            } else if ('a' <= arr[ny][nx] && arr[ny][nx] <= 'z') {
                q.push({ny, nx});
                int alphabet = arr[ny][nx] - 'a'; 

                if (!keys[alphabet]) {
                    keys[alphabet] = true;

                    while (!locked_doors[alphabet].empty()) {
                        q.push(locked_doors[alphabet].front());
                        locked_doors[alphabet].pop();
                    }
                }
            } else {
                q.push({ny, nx});
                if (arr[ny][nx] == '$') ++ret;
            }
        }
    }
}

void init() {
    memset(keys, false, sizeof(keys));
    memset(visited, false, sizeof(visited));
    for (queue<Node>& locked_door : locked_doors) {locked_door = queue<Node>();}
    ret = 0;

    string line;
    vector<Node> nodes;

    cin >> h >> w;
    for (int i=0; i<h; ++i) {
        cin >> line;
        for (int j=0; j<w; ++j) {
            char& cur = arr[i][j] = (char)line[j];

            if (!(i == 0 || i == h-1 || j == 0 || j == w-1)) continue;

            if (cur == '.') {
                q.push({i, j});
                visited[i][j] = true;
            } else if ('A' <= cur && cur <= 'Z') {
                locked_doors[cur - 'A'].push({i, j});
                visited[i][j] = true;
            } else if ('a' <= cur && cur <= 'z') {
                q.push({i, j});
                keys[arr[i][j] - 'a'] = true;
                visited[i][j] = true;
            } else if (cur == '$') {
                q.push({i, j}); ++ret;
                visited[i][j] = true;
            }
        }
    }

    cin >> line;
    if (line[0] != '0') {for (char& c : line) keys[c - 'a'] = true;}        

    for (int i=0; i<26; ++i) {
        if (!keys[i]) continue; 
        while (!locked_doors[i].empty()) {
            Node locked_door = locked_doors[i].front(); 
            q.push(locked_door);
            visited[locked_door.y][locked_door.x] = true;
            locked_doors[i].pop();
        }
    }
}

// a 97, z 122 / A 65, B 90
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t; ++t;
    while (--t) {
        init();
        bfs();
        cout << ret << "\n";
    }
    return 0;
}