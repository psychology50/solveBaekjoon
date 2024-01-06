#include <iostream>

using namespace std;
typedef long long ll;

int n, m;
int color[300001];

bool isValid(int maxV) {
    ll cnt = 0;

    for (int i=0; i<m; ++i) {
        cnt += (color[i] / maxV);
        if (color[i] % maxV) ++cnt;
    }

    return (n < cnt) ? false : true;
}

int binarySearch() {
    int lo = 1, hi = 1000000001;

    while (lo < hi) {
        int mid = (lo + hi) / 2;

        if (isValid(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    return lo;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i=0; i<m; ++i) cin >> color[i];

    cout << (n == 1 ? color[0] : binarySearch());

    return 0;
}