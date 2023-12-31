#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int n;
int map[25][25];
vector<pii> moveVector = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

typedef struct BabyShark {
    int y, x, size = 2, totalCnt = 0, moveCnt = 0, point = 0;
} BabyShark;
BabyShark babyShark;

typedef struct coord {
    int y = 250, x = 250, moveCnt = 987654321;
} coord;

void init();
coord searchFeed();
void updateShark(coord);

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    init();

    while (true) {
        coord nxtCoord = searchFeed();

        if (nxtCoord.y == 250)
            break;
        updateShark(nxtCoord);
    }

    cout << babyShark.totalCnt << "\n";

    return 0;
}

void init() {
    cin >> n;

    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
        int tmp; cin >> tmp;
        map[i][j] = tmp;

        if (tmp == 9) {
            babyShark.y = i; babyShark.x = j;
            map[i][j] = 0;
        }
    }
}

void updateShark(coord nxtCoord) {
    map[nxtCoord.y][nxtCoord.x] = 0;
    babyShark.totalCnt += nxtCoord.moveCnt;
    babyShark.moveCnt = 0;
    babyShark.y = nxtCoord.y;
    babyShark.x = nxtCoord.x;
    
    if (++babyShark.point == babyShark.size) {
        babyShark.point = 0;
        ++babyShark.size;
    }
}

bool inRange(int y, int x) {
    return (0 <= y && y < n && 0 <= x && x < n);
}

coord searchFeed() {
    queue<BabyShark> q; q.push(babyShark);
    bool visited[25][25] = {false, };
    visited[babyShark.y][babyShark.x] = true;

    coord res;

    while (q.size() > 0) {
        BabyShark now = q.front();
        q.pop();

        int y = now.y, x = now.x;
        ++now.moveCnt;

        for (pii dydx : moveVector) {
            int ny = y + dydx.first;
            int nx = x + dydx.second;

            if (!inRange(ny, nx)) continue;
            if (visited[ny][nx]) continue;
            if (now.size < map[ny][nx]) continue;

            if (map[ny][nx] != 0 && now.size > map[ny][nx]) {
                if (now.moveCnt < res.moveCnt) {
                    res.y = ny;
                    res.x = nx;
                    res.moveCnt = now.moveCnt;
                } else if (now.moveCnt == res.moveCnt) {
                    if (ny < res.y) {
                        res.y = ny;
                        res.x = nx;
                    } else if (ny == res.y && nx < res.x) {
                        res.y = ny;
                        res.x = nx;
                    }
                }  
            }

            visited[ny][nx] = true;
            now.y = ny; now.x = nx;
            q.push(now);
        }
    }

    return res;
}