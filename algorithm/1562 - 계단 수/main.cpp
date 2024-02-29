#include <bits/stdc++.h>

#define MOD 1e9
#define VALID 1023

using namespace std;
using ll = long long;

int n;
ll cache[11][101][(1 << 10) + 1];
int dx[2] = {1, -1};

ll dfs(int cur, int idx, int state) {
    if (idx == n-1) return (state == VALID) ? 1 : 0;

    ll& ret = cache[cur][idx][state];
    if (ret != -1) return ret;
    ret = 0;

    for (int& d: dx) {
        int nxt = cur + d;
        if (nxt < 0 || nxt > 9) continue;
        ret += dfs(nxt, idx + 1, state | 1<<nxt);
    }
    return ret %= (ll)MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    if (n < 10) {cout << 0; return 0;}
    memset(cache, -1, sizeof(cache));

    ll ret = 0;
    for (int i=1; i<10; ++i) {
        ret += dfs(i, 0, 1 << i);
    }

    cout << ret % (ll)MOD;
    return 0;
}