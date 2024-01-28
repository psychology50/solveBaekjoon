#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 5001

using namespace std;

int n;
int a[MAX], cache[MAX][MAX];

int solve(int l, int r) {
    if (l >= r) return 0;

    int& ret = cache[l][r];
    if (ret != -1) return ret;

    if (a[l] == a[r]) ret = solve(l+1, r-1);
    else ret = min(solve(l, r-1), solve(l+1, r)) + 1;

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    memset(cache, -1, sizeof(cache));
    cout << solve(0, n-1);

    return 0;
}