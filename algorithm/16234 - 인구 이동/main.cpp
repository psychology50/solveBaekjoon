#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

#define endl "\n"

using namespace std;
typedef tuple<int, int> tii;

int N, L, R;
bool flag;
int map[51][51];
int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};


int bfs(tii start, bool visited[51][51], vector<tii> &v) {
    int sum = map[get<0>(start)][get<1>(start)];
    visited[get<0>(start)][get<1>(start)] = true;
    v.push_back({get<0>(start), get<1>(start)});

    queue<tii> q; q.push(start);

    while (!q.empty()) {
        tii now = q.front(); q.pop();
        int y = get<0>(now), x = get<1>(now);

        for (int i=0; i<4; i++) {
            int ny = y + d[i][0];
            int nx = x + d[i][1];

            if (0 <= nx && nx < N && 0 <= ny && ny < N && !visited[ny][nx]) {
                if (L <= abs(map[y][x] - map[ny][nx]) && abs(map[y][x] - map[ny][nx]) <= R) {
                    visited[ny][nx] = true;
                    flag = true;

                    q.push({ny, nx});
                    v.push_back({ny, nx});
                    sum += map[ny][nx];
                }
            }
        }
    } 

    return sum;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> L >> R;
    
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) cin >> map[i][j];
    int day = 0;
    while (true) {
        bool visited[51][51] = {false,};
        flag = false;

        for (int r=0; r<N; r++) for (int c=0; c<N; c++) {
            if (!visited[r][c]) {
                vector<tii> v;
                int sum = bfs({r,c}, visited, v);
                int avg = sum / v.size();

                for (auto tmp : v) {
                    int y = get<0>(tmp), x = get<1>(tmp);
                    map[y][x] = avg;
                }
                v.clear();
            }
        } 

        if (flag) day++; 
        else break; 
    }
    cout << day << endl;
    
    return 0;
}