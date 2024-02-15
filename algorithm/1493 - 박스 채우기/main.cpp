#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

typedef struct Cube {
    ll l;
    int cnt;
} Cube;
vector<Cube> cubes;
int ret = 0;
bool flag = false;

void divide(int l, int w, int h, int idx) {
    if (l == 0 || w == 0 || h == 0) return;

    for (int i=idx; i>=0; --i) {
        if (cubes[i].cnt <= 0) continue;
        if (l < cubes[i].l || w < cubes[i].l || h < cubes[i].l) continue;
        --cubes[i].cnt; ++ret;

        divide(l - cubes[i].l, w, cubes[i].l, idx);
        divide(cubes[i].l, w - cubes[i].l, cubes[i].l, idx);
        divide(l, w, h - cubes[i].l, idx);

        return;
    }

    flag = true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int length, width, height, n;
    cin >> length >> width >> height >> n;
    cubes.resize(n);
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        cubes[i] = {1 << a, b}; 
    }

    divide(length, width, height, n-1);
    
    cout << ((flag) ? -1 : ret);
    return 0;
}