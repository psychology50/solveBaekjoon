#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, k;
vector<pii> arr;
vector<int> backpack;

bool cmp(pii& a, pii& b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k; arr.resize(n); backpack.resize(k);
    for (int i=0; i<n; ++i) cin >> arr[i].first >> arr[i].second;
    for (int i=0; i<k; ++i) cin >> backpack[i]; 
    sort(arr.begin(), arr.end(), cmp);
    sort(backpack.begin(), backpack.end());

    priority_queue<ll> pq;

    ll ret = 0;
    int idx = 0;
    for (int i=0; i<k; ++i) {
        while (idx < n && backpack[i] >= arr[idx].first) {
            pq.push(arr[idx].second); ++idx;
        }
        if (!pq.empty()) {
            ret += (ll)pq.top(); pq.pop();
        }
    }
    cout << ret;

    return 0;
}