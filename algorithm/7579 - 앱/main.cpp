#include <bits/stdc++.h>

#define MAX 10001

using namespace std;
using pii = pair<int, int>;
using ll = long long;

int n, m;
vector<pii> apps;
ll cache[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m; apps.resize(n);

    ll sum = 0;
    for (pii& app : apps) cin >> app.first;
    for (pii& app : apps) {cin >> app.second; sum += app.second;}

    for (int i=0; i<n; ++i) for (int j=sum; j>=apps[i].second; --j) 
            cache[j] = max(cache[j], cache[j - apps[i].second] + apps[i].first);

    for (int i=0; i<MAX; ++i) if (cache[i] >= m) {
        cout << i;
        break;
    }

    return 0;
}