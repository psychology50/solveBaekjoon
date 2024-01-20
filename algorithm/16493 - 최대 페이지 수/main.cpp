#include <iostream>
#include <cmath>

using namespace std;
int n, m;
int cache[201];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for (int i=0; i<m; ++i) {
        int day, page; cin >> day >> page;
        for (int j=n; j>=day; --j) {
            cache[j] = max(cache[j], cache[j-day] + page);
        }
    }

    cout << cache[n] << endl;
    return 0;
}