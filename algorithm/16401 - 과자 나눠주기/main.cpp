#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
vector<int> L;

int binarySearch() {
    int l = 1, r = *max_element(L.begin(), L.end());
    int res = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt = 0;

        for (int i=0; i<n; ++i) {
            cnt += L[i] / mid;
        }

        if (cnt >= m) {
            l = mid + 1;
            res = mid;
        } else r = mid - 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> n; L.resize(n);
    for (int i=0; i<n; ++i) cin >> L[i]; 
    cout << binarySearch();
    return 0;
}