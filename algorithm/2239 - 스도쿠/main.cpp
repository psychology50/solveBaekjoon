#include <bits/stdc++.h>

using namespace std;

int sdoku[10][10];

void print() {
    for (int i=0; i<9; ++i) {
        for (int j=0; j<9; ++j) {
            cout << sdoku[i][j] << "";
        }
        cout << "\n";
    }
}

bool isValid(int r, int c) {
    for (int i=0; i<9; ++i) {
        if (sdoku[r][c] == sdoku[r][i] && i != c) return false;
        if (sdoku[r][c] == sdoku[i][c] && i != r) return false;
    }

    int squareR = (r / 3) * 3, squareC = (c / 3) * 3;

    for (int i=squareR; i<squareR+3; ++i) for (int j=squareC; j<squareC+3; ++j) {
        if (i == r && j == c) continue;
        if (sdoku[r][c] == sdoku[i][j]) return false;
    }

    return true;
}

void dfs(int r, int c) {
    if (r == 9) {
        print(); exit(0);
    } else if (c == 9) {
        dfs(r+1, 0);
        return;
    }

    if (sdoku[r][c] == 0) {
        for (int i=1; i<=9; ++i) {
            sdoku[r][c] = i;
            if (isValid(r, c)) dfs(r, c+1);
        }
        sdoku[r][c] = 0;
    } else dfs(r, c+1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string line;
    for (int i=0; i<9; ++i) {
        cin >> line;
        for (int j=0; j<9; ++j) {
            sdoku[i][j] = (char)line[j] - '0';
        }
    }
    dfs(0, 0);

    return 0;
}