#include <iostream>
#include <cmath>

using namespace std;
int n;
int boxes[1001];
int cache[1001];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> boxes[i];
        cache[i] = 1;
    }

    for (int now = 0; now < n; ++now) {
        int& ret = cache[now];
        for (int pre = 0; pre < now; ++pre) {
            if (boxes[now] <= boxes[pre]) continue;
            ret = max(ret, cache[pre] + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {ans = max(ans, cache[i]);}
    cout << ans;

    return 0;
}