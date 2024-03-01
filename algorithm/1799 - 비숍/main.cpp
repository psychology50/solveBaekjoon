#include <bits/stdc++.h>

using namespace std;
int n, ret[2];
int chess[11][11];
int l[20], r[20];

void dfs(int row, int col, int cnt, int flag) {
    if (col >= n) {
        ++row;
        col = (col%2 == 0) ? 1 : 0;
    }
    if (row >= n) {
        ret[flag] = max(ret[flag], cnt);
        return ;
    }

    if (chess[row][col] && !l[col - row + n - 1] && !r[row + col]) {
        l[col - row + n - 1] = r[row + col] = 1;
        dfs(row, col+2, cnt+1, flag);
        l[col - row + n - 1] = r[row + col] = 0;
    }
    dfs(row, col+2, cnt, flag); // 그냥 지나가는 경우
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) cin >> chess[i][j];
    dfs(0, 0, 0, 0);
    dfs(0, 1, 0, 1);
    cout << ret[0] + ret[1];

    return 0;
}