#include <iostream>
#include <cstring>

#define MAX 10001

using namespace std;
int n, k;
int d[MAX], s[MAX], v[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; ++i) cin >> s[i];
    for (int i=1; i<=n; ++i) cin >> d[i];

    ++k;
    while (--k) {
        for (int i=1; i<=n; ++i) v[d[i]] = s[i];
        memcpy(s, v, sizeof(s));
    }
    for (int i=1; i<=n; ++i) cout << v[i] << " ";

    return 0;
}