#include <string>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 110

using namespace std;
using vi = vector<int>;
typedef struct Pos {
    int y, x, cnt;
    bool flag;
} Pos;

int map[MAX][MAX];
int dydx[4][2] = {{-1, 0}, {1, 0}, {0,-1}, {0, 1}};

int bfs(int startY, int startX, int targetY, int targetX) {
    bool flag = (map[startY][startX] == 1) ? true : false;
    queue<Pos> q; q.push({startY, startX, 0, flag}); 
    bool visited[MAX][MAX];
    memset(visited, false, sizeof(visited));
    visited[startY][startX] = true;
    
    while (!q.empty()) {
        Pos cur = q.front(); q.pop();
        
        if (cur.y == targetY && cur.x == targetX) {
            return cur.cnt;
        }
        
        for (int i=0; i<4; ++i) {
            int ny = cur.y + dydx[i][0], nx = cur.x + dydx[i][1];
            if (!(0 <= ny && ny < MAX && 0 <= nx && nx < MAX)) continue;
            if (visited[ny][nx]) continue;
            
            if (map[ny][nx] == 0) {
                visited[ny][nx] = true;
                q.push({ny, nx, cur.cnt+1, false});
            }
            if (!cur.flag && map[ny][nx] == 1) {
                visited[ny][nx] = true;
                q.push({ny, nx, cur.cnt+1, true});
            }
        }
    }
    return 1;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    characterX *= 2, characterY *= 2, itemY *= 2, itemX *= 2;
    for (int i=0; i<MAX; ++i) for (int j=0; j<MAX; ++j) map[i][j] = -2;
    
    for (vi& coord : rectangle) {
        int lx = coord[0] * 2, ly = coord[1] * 2, rx = coord[2] * 2, ry = coord[3] * 2;
        
        for (int r=ly; r<=ry; ++r) for (int c=lx; c<=rx; ++c) {
            int& cur = map[r][c];
            if (r == ry || r == ly || c == rx || c == lx) {
                cur = (cur == 0) ? 1 : (cur == -1) ? -1 : 0;
            } else {
                cur = -1;
            }
        }
    }
    
    return bfs(characterY, characterX, itemY, itemX)/2;
}