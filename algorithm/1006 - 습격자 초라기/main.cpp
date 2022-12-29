#include <iostream>
#include <algorithm>
#include <cstring>

#define endl "\n"
using namespace std;

int enemy[10005][2];
int cache[10005][4][4];

int operation(int idx, int prev, int last, int n, int w) {
    int &unit = cache[idx][prev][last];
    bool is_inner, is_outer, is_inner_outer;

    if (unit) return unit;

    is_inner = (enemy[idx][0] + enemy[idx ? idx-1 : n-1][0] <= w);
    is_outer = (enemy[idx][1] + enemy[idx ? idx-1 : n-1][1] <= w);
    is_inner_outer = (enemy[idx][0] + enemy[idx][1] <= w);

    if (idx == n-1) {
        if (idx == 0) return is_inner_outer ? 1 : 2;
        unit = 2;
        if (last == 0) {
			if (is_inner && !(prev & 1)) unit = 1;
			if (is_outer && prev < 2) unit = 1;
			if (is_inner_outer) unit = 1;
			if (is_inner && is_outer && prev == 0) unit = 0;
        } else if (last == 1) {
            if (is_outer && prev < 2) unit = 1;
        } else if (last == 2) {
            if (is_inner && !(prev & 1)) unit = 1;
        }
        return unit;
    }

    // bifurcation
    unit = 2 + operation(idx+1, 0, idx ? last : 0, n, w);
    if (is_inner && !(prev & 1))
        unit = min(unit, 1+operation(idx+1, 1, idx ? last : 1, n, w));
    if (is_outer && prev < 2)
        unit = min(unit, 1+operation(idx+1, 2, idx ? last : 2, n, w));
    if (is_inner && is_outer && prev == 0)
        unit = min(unit,   operation(idx+1, 3, idx ? last : 3, n, w));
    if (is_inner_outer)
        unit = min(unit, 1+operation(idx+1, 3, idx ? last : 0, n, w));

    return unit;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) {
        memset(cache, 0, sizeof(cache));
        int n, w; cin >> n >> w;

        for (int i=0; i < n; i++) cin >> enemy[i][0];
        for (int i=0; i < n; i++) cin >> enemy[i][1];
        cout << operation(0, 0, 0, n, w) << endl;
    }

    return 0;
}