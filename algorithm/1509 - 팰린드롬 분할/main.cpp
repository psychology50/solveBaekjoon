#include <bits/stdc++.h>

#define MAX 2505
#define INF 1e9

using namespace std;
int n, cache[MAX];
int pal[MAX][MAX];
string input;

int isPal(int l, int r) {
    if (l == r) return true;
    if (l + 1 == r) return input[l] == input[r];

    int& ret = pal[l][r];
    if (ret != -1) return ret;
    return ret = (input[l] == input[r] && isPal(l+1, r-1)); 
}

int recur(int cur) {
    if (cur == n) return 0;

    int& ret = cache[cur];
    if (ret != -1) return ret;
    ret = INF;

    for (int nxt=cur; nxt<n; ++nxt) {
        if (isPal(cur, nxt)) {
            ret = min(ret, recur(nxt + 1) + 1);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> input;
    memset(cache, -1, sizeof(cache));
    memset(pal, -1, sizeof(pal));

    n = input.length();
    cout << recur(0);

    return 0;
}