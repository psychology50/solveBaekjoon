#include <bits/stdc++.h>

using namespace std;

int sdoku[9][9];
bool R[9][10], C[9][10], S[9][10];

void print() {
    for (int i=0; i<9; ++i) {
        for (int j=0; j<9; ++j) {
            cout << sdoku[i][j] << " ";
        }
        cout << "\n";
    }
}

void dfs(int cnt) {
    if (cnt == 81) {
        print();
        exit(0);
    }

    int row = cnt / 9, col = cnt % 9;
    if (sdoku[row][col] == 0) {
        for (int i=1; i<=9; ++i) {
            if (!R[row][i] && !C[col][i] && !S[(row/3) * 3 + (col/3)][i]) {
                R[row][i] = C[col][i] = S[(row/3) * 3 + (col/3)][i] = true;
                sdoku[row][col] = i;
                // print();
                // cout << endl;
                dfs(cnt + 1);
                sdoku[row][col] = 0;
                R[row][i] = C[col][i] = S[(row/3) * 3 + (col/3)][i] = false;
            }
        }
    } else {
        dfs(cnt+1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string line;
    for (int i=0; i<9; ++i) {
        cin >> line;
        for (int j=0; j<9; ++j) {
            sdoku[i][j] = (char)line[j] - '0';
            if (sdoku[i][j] != 0) {
                R[i][sdoku[i][j]] = C[i][sdoku[i][j]] = S[(i/3)*3 + (j/3)][sdoku[i][j]] = true;
            }
        }
    }

    for (int i=0; i<9; ++i) {
        for (int j=1; j<10; ++j) {
            cout << S[i][j] << " ";
        }
        cout << endl;
    }

    dfs(0);
    return 0;
}