#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

int R, C;
char map[15][15];

int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};

int minY = 20, maxY = -1;
int minX = 20, maxX = -1;

void after50thYear();
void checkMapSize();
void reDrawingMap();
bool isValidRange(int y, int x) {
    return (0 <= y && y < R) && (0 <= x && x < C);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> R >> C;
    for (int i=0; i<R; ++i) cin >> map[i];

    after50thYear();
    checkMapSize();

    for (int i=minY; i<=maxY; ++i) {
        for (int j=minX; j<=maxX; ++j) cout << map[i][j];
        cout <<endl;
    }

    return 0;
}

void after50thYear() {
    vector<pair<int ,int>> underTheSee;

    for (int y=0; y<R; ++y) for (int x=0; x<C; ++x) {
        if (map[y][x] == 'X') {
            int countSee = 0;

            for (int idx=0; idx<4; ++idx) {
                int ny = y + dy[idx];
                int nx = x + dx[idx];

                if (isValidRange(ny, nx)) {
                    if (map[ny][nx] == '.') {
                        ++countSee;
                    }
                } else { ++countSee; }
            }

            if (countSee >= 3) {
                underTheSee.push_back(make_pair(y, x));
            }
        }
    }

    for (auto coord : underTheSee) map[coord.first][coord.second] = '.';
}

void checkMapSize() {
    for (int y = 0; y < R; ++y) for (int x = 0; x < C; ++x) {
        if (map[y][x] == 'X') {
            minY = min(minY, y); maxY = max(maxY, y);
            minX = min(minX, x); maxX = max(maxX, x);
        }
    } 
}