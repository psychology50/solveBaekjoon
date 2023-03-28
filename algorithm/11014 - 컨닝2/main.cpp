#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <tuple>

#define endl "\n"
using namespace std;
typedef tuple<int, int> tii;

char map[81][81];
int aMatch[50], bMatch[50];
bool visited[50];
vector<tii> vc = {{-1,-1}, {0,-1}, {1,-1}, {-1,1}, {0,1}, {1,1}};

bool dfs(int now, vector<int> adj[50]) {
    if (visited[now]) return false;
    visited[now] = true;

    for (int nxt : adj[now]) {
        if (bMatch[nxt] == -1 || dfs(bMatch[nxt], adj)) {
            aMatch[now] = nxt;
            bMatch[nxt] = now;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int c; cin >> c;

    while (c--) {
        int n, m; cin >> n >> m;
        for (int i=0; i<n; i++) cin >> map[i];

        int nodeNum[81][81]; 
        int A, B; A = B = 0;
        int broken = 0;
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
            if (map[i][j] == 'x') broken++;
            nodeNum[i][j] = (j % 2 == 0) ? A++ : B++; 
        }

        vector<int> adj[50];
        for (int i=0; i<n; i++) for (int j=0; j<m; j+=2) {
                if (map[i][j] == 'x') continue;
                for (tii t : vc) {
                    int ny = i + get<0>(t); int nx = j + get<1>(t);
                    if (0 <= ny && ny < n && 0 <= nx && nx < m && map[ny][nx] != 'x')
                        adj[nodeNum[i][j]].push_back(nodeNum[ny][nx]);
                }
        }

        int maxMatch = 0;
        memset(aMatch, -1, sizeof(aMatch));
        memset(bMatch, -1, sizeof(bMatch));
        for (int i=0; i<A; i++) {
            memset(visited, 0, sizeof(visited));
            if (dfs(i, adj)) maxMatch++;
        }

        cout << n*m - broken - maxMatch << endl;
    }

    return 0;
}
