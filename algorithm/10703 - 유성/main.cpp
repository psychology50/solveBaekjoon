#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 3010

using namespace std;
int r, s;

char map[MAX][MAX];
int upper[MAX];
int lower[MAX];
bool visited[MAX][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> r >> s;

    for (int i = 0; i < s; ++i) upper[i] = -1, lower[i] = MAX;
    for (int i=0;i<r;++i) for (int j=0;j<s;++j) {
        cin >> map[i][j];

        if (map[i][j] == 'X') upper[j] = max(upper[j], i);
        if (map[i][j] == '#') lower[j] = min(lower[j], i);
    }

    

    int minInterval = MAX;
    for (int i=0; i<s; ++i) {
        if (upper[i] == -1 || lower[i] == MAX) continue;
        minInterval = min(minInterval, lower[i] - upper[i] - 1);
    }

    
    for (int i=r-1;i>=0;--i) for (int j=0;j<s;++j) {
        if (map[i][j] != 'X' || visited[i][j]) continue;
        map[i][j] = '.'; map[i + minInterval][j] = 'X';
        visited[i][j] = visited[i + minInterval][j] = true; 
    }

    for (int i = 0; i < r; ++i) {
        for (int j=0; j<s; ++j) {
            cout << map[i][j];
        }
        cout << "\n";
    }

    return 0;
}