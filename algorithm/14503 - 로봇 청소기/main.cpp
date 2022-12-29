#include <iostream>

using namespace std;

int n, m; 
int map[51][51];
int vector[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(int r, int c, int d, int cnt) {
    map[r][c] = -1;

    for (int i=0; i<4; i++) {
        int nxt_d = (d+3-i) % 4;
        int nxt_r = r + vector[nxt_d][0];
        int nxt_c = c + vector[nxt_d][1];

        if (0 <= nxt_r && nxt_r < n && 0 <= nxt_c && nxt_c < m && map[nxt_r][nxt_c] == 0)
            dfs(nxt_r, nxt_c, nxt_d, cnt+1);
    }

    int back_idx = (d+2) % 4;
    int back_r = r + vector[back_idx][0];
    int back_c = c + vector[back_idx][1];
    if (0 <= back_r && back_r < n && 0 <= back_idx && back_idx < m) {
        if (map[back_r][back_c] == 0 || map[back_r][back_c] == -1) 
            dfs(back_r, back_c, d, cnt); 
        else {
            cout << cnt << "\n";
            exit(0); 
        }
            
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int r, c, d; 
    cin >> n >> m >> r >> c >> d;

    for(int i=0; i<n; i++) for (int j=0; j<m; j++) cin >> map[i][j];

    dfs(r, c, d, 1);
    return 0;
}