#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

int n, t;
vector<pii> chapter;
int cache[10001];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> t;

    chapter.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> chapter[i].first >> chapter[i].second;

    for (int i=0; i<n; ++i) for (int j=t; j>=chapter[i].first; --j) {
        cache[j] = max(cache[j], cache[j - chapter[i].first] + chapter[i].second);
    }

    cout << cache[t];

    return 0;
}