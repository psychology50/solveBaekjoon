#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using pii = pair<int, int>;
using v = vector<pii>;
typedef long long ll;

int n, maxD;
v towns;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    towns.resize(n+1);

    ll total = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> towns[i].first >> towns[i].second;
        total += towns[i].second;
    }
    sort(towns.begin() + 1, towns.end());

    ll cur = 0;
    for (int i=1; i<=n; ++i) {
        cur += towns[i].second;
        if (cur >= (total+1)/2) {
            cout << towns[i].first;
            break;
        }
    }
    return 0;
}