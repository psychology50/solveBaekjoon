#include <iostream>
#include <algorithm>

using namespace std;
int n, maxDepth = 0;
char ret[7][101];

void divide(int l, int r, int depth) { // 5, 10
    if (l >= r-1 || depth == 7) return;
    maxDepth = max(maxDepth, depth);

    int mid = (l + r) / 2; // 8

    for (int i=l; i<r; ++i) ret[depth][i] = (i < mid) ? 'A' : 'B';

    divide(l, mid, depth+1); // 5, 8
    divide(mid, r, depth+1); // 9, 10
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    divide(0, n, 0);

    for (int day = 0; day<maxDepth; ++day) {
        for (int i=0; i<n; ++i) {
            cout << ret[day][i] << "";
        }
        cout << endl;
    }

    while (maxDepth != 7) {
        for (int i=0; i<n; ++i) cout << ((i&1) ? 'A' : 'B');
        ++maxDepth; cout << "\n";
    }

    return 0;
}