#include <iostream>

#define MAX 50

using namespace std;
int n, m, cnt=0;
char matrix1[MAX][MAX];
char matrix2[MAX][MAX];

void reverse(int y, int x) {
    for (int i = y; i < y+3; ++i) for (int j = x; j < x+3; ++j) {
        matrix1[i][j] = (matrix1[i][j] == '1') ? '0' : '1';
    }
}

bool isValid() {
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
        if (matrix1[i][j] != matrix2[i][j]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> matrix1[i][j];
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> matrix2[i][j];

    for (int i=0; i<n-2; ++i) for (int j=0; j<m-2; ++j) {
        if (matrix1[i][j] != matrix2[i][j]) {
            reverse(i, j);
            ++cnt;
        }
    }
    
    cout << ((isValid() ? cnt : -1));

    return 0;
}