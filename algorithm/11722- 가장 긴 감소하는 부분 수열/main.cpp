#include <iostream>
#include <cmath>

using namespace std;
int n;
int numbers[1001];
int cache[1001];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
        cache[i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        int& ret = cache[i];
        for (int j = 0; j < i; ++j) {
            if (numbers[i] >= numbers[j]) continue;
            ret = max(ret, cache[j] + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {ans = max(ans, cache[i]);}
    cout << ans;

    return 0;
}