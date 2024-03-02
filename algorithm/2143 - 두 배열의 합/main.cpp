#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> a, b;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t, n, m; cin >> t >> n; a.resize(n);
    for (int& v : a) cin >> v;
    cin >> m; b.resize(m);
    for (int& v : b) cin >> v;
    
    // 누적합
    vector<int> aSum, bSum;
    for (int i=0; i<n; ++i) {
        int sum = a[i]; aSum.push_back(sum);
        for (int j=i+1; j<n; ++j) {
            sum += a[j]; aSum.push_back(sum);
        }
    }

    for (int i=0; i<m; ++i) {
        int sum = b[i]; bSum.push_back(sum);
        for (int j=i+1; j<m; ++j) {
            sum += b[j]; bSum.push_back(sum);
        }
    }

    sort(bSum.begin(), bSum.end());
    ll ret = 0;
    for (int i = 0; i < aSum.size(); ++i) {
        int target = t - aSum[i];
        int lo = lower_bound(bSum.begin(), bSum.end(), target) - bSum.begin();
        int hi = upper_bound(bSum.begin(), bSum.end(), target) - bSum.begin();
        ret += (hi - lo);
    }
    cout << ret;

    return 0;
}