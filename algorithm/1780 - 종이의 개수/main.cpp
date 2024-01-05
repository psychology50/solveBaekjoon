#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int n;
int graph[2500][2500];
int cnt[3] = {0, }; // -1, 0, 1

bool searchGraph(int y, int x, int sz) {
    int flag = graph[y][x];
    for (int i=y; i<y+sz; ++i) for (int j=x; j<x+sz; ++j) {
        if (graph[i][j] != flag) {
            return false;
        }
    }
    return true;
}

void devide(int y, int x, int sz) {
    if (searchGraph(y, x, sz)) {
        ++cnt[graph[y][x] + 1];
        return;
    }

    int nxtSz = sz / 3;
    for (int i=0; i<3; ++i) for (int j=0; j<3; ++j) {
        devide(y + i * nxtSz, x + j * nxtSz, nxtSz);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) cin >> graph[i][j];
    devide(0, 0, n);

    cout << cnt[0] << "\n" << cnt[1] << "\n" << cnt[2];

    return 0;
}