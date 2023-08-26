#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <string>
#include <utility>

#define MAX 50
#define endl "\n"

using namespace std;
using pii = pair<int, int>;

int N, M;
int start_x, start_y;
char maze[MAX][MAX];
bool visited[MAX][MAX][1 << 6];
vector<pii> moved = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void init();
int bfs();
bool hasKey(int cur_key, char door) {
    return cur_key & (1 << (int(door) - 'A'));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init();
    cout << bfs() << "\n";

    return 0;
}

void init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        for (int j = 0; j < M; j++) {
            maze[i][j] = str[j];
            if (maze[i][j] == '0') {
                start_y = i; start_x = j;
                maze[i][j] = '.';
            }
        }
    }
}

int bfs() {
    queue<pair<pii, pii>> q;
    queue<pii> door[26];
    q.push(make_pair(make_pair(start_y, start_x), make_pair(0, 0)));
    visited[start_y][start_x][0] = true;

    while (!q.empty()) {
        pair<pii, pii> cur = q.front();
        int cur_y = cur.first.first, cur_x = cur.first.second;
        int cnt = cur.second.first, key = cur.second.second;
        q.pop();

        if (maze[cur_y][cur_x] == '1') return cnt;

        for (pii m : moved) {
            int nxt_y = cur_y + m.first, nxt_x = cur_x + m.second;
            if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= M) continue; // 1. 범위 밖 예외 처리
            if (visited[nxt_y][nxt_x][key]) continue; // 2. 방문한 곳 예외 처리
            
            if (maze[nxt_y][nxt_x] == '.' || maze[nxt_y][nxt_x] == '1') 
            {
                visited[nxt_y][nxt_x][key] = true;
                q.push({{nxt_y, nxt_x}, {cnt + 1, key}});
            } 
            else if (maze[nxt_y][nxt_x] >= 'a' && maze[nxt_y][nxt_x] <= 'f') 
            {
                int tmp_key = key | (1 << (int)(maze[nxt_y][nxt_x] - 'a')); // 키 획득
                visited[nxt_y][nxt_x][tmp_key] = true;
                q.push({{nxt_y, nxt_x}, {cnt + 1, tmp_key}});
            } 
            else if (maze[nxt_y][nxt_x] >= 'A' && maze[nxt_y][nxt_x] <= 'F') 
            {
                if (hasKey(key, maze[nxt_y][nxt_x])) 
                {
                    visited[nxt_y][nxt_x][key] = true;
                    q.push({{nxt_y, nxt_x}, {cnt + 1, key}});
                }
            }
        }
    }
    return -1;
}